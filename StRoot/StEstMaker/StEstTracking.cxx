/***************************************************************************
 *
 * $Id: StEstTracking.cxx,v 1.3 2001/01/31 16:59:30 lmartin Exp $
 *
 * Author: PL,AM,LM,CR (Warsaw,Nantes)
 ***************************************************************************
 *
 * Description: Methods for the tracking
 *
 ***************************************************************************
 *
 * $Log: StEstTracking.cxx,v $
 * Revision 1.3  2001/01/31 16:59:30  lmartin
 * mParams[]->debug replaced by mDebug.
 *
 * Revision 1.2  2001/01/25 18:24:56  lmartin
 * Method declared as a StEstTracker method.
 * mIdealTracking used as a flag for the perfect tracking and the evaluation.
 *
 * Revision 1.1  2000/12/07 11:14:22  lmartin
 * First CVS commit
 *
 **************************************************************************/
#include "StEstTracker.h"
#include "StEstParams.hh"
#include "Infrastructure/StEstWafer.hh"
#include "Infrastructure/StEstBranch.hh"
#include "Infrastructure/StEstHit.hh"
#include "Infrastructure/StEstTrack.hh"
#include "Infrastructure/StEstTPCTrack.hh"

int StEstTracker::Tracking(int slay) {
  // Method called at each tracking step (ie in each layer)
  // Two big loops are set on tracks and their branches.
  // For each branch the following action are done :
  // - a call to Preprojection which return a list of wafer to scan
  // - a call to Projection which return a list of hits (matching the geometrical limits).
  // - a new list is build with only the available hits with respect
  //   to the hit sharing criteria
  // - a sort of the hits by increasing hit-track projection distance
  // - a given number N of hits are attached to the branches. This number is the minimum value
  //   between the found hits and the maximum number of new branches which can be formed
  //   during that pass in the current layer. N-1 new branches are formed 
  //   by duplication of the mother branch and the Nth hit is attached at the end to the 
  //   mother branch.
  
  if(mDebugLevel>2)  {
      cout << "StEstMaker::Tracking ****START****"<<endl;
  }

  int TheNewHitIsGood;
  int FirstHitIndex,HitPosition,ThereIsOneIdealHitInTheLayer;
  int fitstatus,OneIsGood,SeveralWereGood,IndexFirstWasGood;

  long lm,lm2;
  long i,j,jc,k,kk, maxl, nbr, nbranch;
  double distbra[MAXHITPROJ];
  int distind[MAXHITPROJ], indtmp;
  StEstHit* hitbra[MAXHITPROJ];

  StEstBranch *branch, *branch_new;
 
  if(mDebugLevel>2) cout << "loop over the tracks START"<<endl;
  for (i=0;i<mNTrack;i++) { // loop over the tracks
    
    maxl = 0;

    if(mDebugLevel>2) {
      cout << "StEstMaker::Tracking" << endl;
      cout << " Track #"<<i<<"  Number of branches: "<<mTrack[i]->GetNBranches();
      cout << "  mPt="<<mTrack[i]->mTPCTrack->mPt<< endl;
    }

    if(mTrack[i]->GetDoIt()!=1) continue;
    
    nbranch = mTrack[i]->GetNBranches();

    for (j=0;j<nbranch;j++) { // loop over the branches in the track
      if(mDebugLevel>2)
	cout << " Track #"<<i<<"  Branch #"<<j<<endl;
      branch = mTrack[i]->GetBranch(j);

      // get the wafer list.
      Preprojection(*branch,slay);

      // get the hit list (of size maxl).
      Projection(branch,slay);

      maxl=mProjOut.nhit;

      if(mDebugLevel>2){
	cout << " number of hits from projection: "<<maxl<<endl;
	cout << " loop over the hits found in Projection"<<endl;
      }

      nbr = 0; 
      kk=0;
      for (k=0;k<maxl;k++) { // loop over the hits found in Projection

	if(mDebugLevel>2)
	  cout << "    k="<<k<<endl;
	if(mDebugLevel>3) {
	  cout << "    nbr="<<nbr<<endl;
	  cout << "    branch=" << branch<<endl;
	  cout << "    branch->GetNHits()="<<branch->GetNHits()<<endl;
	  cout << "    mProjOut.dist= "<<mProjOut.dist[k]<<endl;
	}

	if (mProjOut.hit[k]->CheckAvailability()) {
	  hitbra[kk] = mProjOut.hit[k];
	  distbra[kk] = mProjOut.dist[k];
	  kk++;
	}
      }

      for (k=0;k<kk;k++) distind[k] = k;

      // sorting on projection to hit distances
      for (k=0;k<kk;k++) {
	for (jc=k+1;jc<kk;jc++) {
	  if (distbra[distind[k]]>distbra[distind[jc]]) {
	    indtmp       = distind[k];
	    distind[k]  = distind[jc];
	    distind[jc] = indtmp;
	  }
	}
      }
    
      if( mIdealTracking == 1){
	//Ideal Tracking

	// looking where the ideal is in the list
	if (branch->GetIsGood()==1) {
	  FirstHitIndex=-1;
	  HitPosition=-4;
	  ThereIsOneIdealHitInTheLayer=0;
	  for (lm2=0;lm2<mTrack[i]->GetIdealBranch()->GetNHits();lm2++) {
	    if (mTrack[i]->GetIdealBranch()->GetHit(lm2)->GetWafer()->GetLayer()==slay) {
	      ThereIsOneIdealHitInTheLayer=1;
	      for (lm=0;lm<kk;lm++) {
		if (hitbra[lm]==mTrack[i]->GetIdealBranch()->GetHit(lm2)) {
		  if (FirstHitIndex==-1) FirstHitIndex=lm;
		  else if (distbra[lm]<distbra[FirstHitIndex]) FirstHitIndex=lm;
		}
	      }
	    }
	  }
	  // if the ideal hit is in the selected hit list it should have 
	  // FirstHitIndex>=0.  If there is one ideal hit but not found in the list
	  // it can still be in the original mProjOut list but not available
	  if (FirstHitIndex==-1 && ThereIsOneIdealHitInTheLayer==1) {
	    HitPosition=-3;
	    for (lm=0;lm<maxl;lm++) 
	      for (lm2=0;lm2<mTrack[i]->GetIdealBranch()->GetNHits();lm2++) 
		if (mTrack[i]->GetIdealBranch()->GetHit(lm2)==mProjOut.hit[lm]) HitPosition=-1;
	    if (HitPosition==-3) {
	      for (lm2=0;lm2<mTrack[i]->GetIdealBranch()->GetNHits();lm2++) {
		if (mTrack[i]->GetIdealBranch()->GetHit(lm2)->GetWafer()->GetLayer()==slay) {	    
		  for (lm=0;lm<mPreprojNumber;lm++) {
		    if (mPreprojTable[lm]->GetId()==mTrack[i]->GetIdealBranch()->GetHit(lm2)->GetWafer()->GetId())
		      HitPosition=-2;
		  }
		}
	      }
	    }
	  }
	  else {
	    for (lm=0;lm<kk;lm++) if (distind[lm]==FirstHitIndex) HitPosition=lm;
	  }
	}
      }// ENd of ideal Tracking
      if(mDebugLevel>2)
	cout << " hits found: " << kk << endl;
      if (kk>0) {
	// connecting branch and hits, branch duplication
	for (k=0;k<kk-1 && k<mParams[mPass]->nbranch[slay]-1;k++) { 

	  if(mDebugLevel>2)
	    cout << " duplicating...  k= "<<k<<endl;

	  branch_new = branch->Duplicate();
	  if (branch_new!=NULL) {
	    if(mDebugLevel>3) 
	      cout <<"  nBranch= "<<branch_new->mTrack->GetNBranches()<<endl;
	    if (hitbra[distind[k]]->JoinBranch(branch_new,mTrack[i])==1) {
	      branch_new->AddHit(hitbra[distind[k]],distbra[distind[k]]);
	      RefitBranch(branch_new,NULL,-1,0,&fitstatus);
	      branch_new->SetStep(10*mSuperPass+mPass);
	      if (mIdealTracking==1) {
		branch_new->mHitPosition=HitPosition;
		// we check if isgood is still good or not (for debugging) 
		if (branch_new->GetNHits()==1 || branch_new->GetIsGood()==1) {
		  TheNewHitIsGood=0;
		  for (lm=0;lm<mTrack[i]->GetIdealBranch()->GetNHits();lm++)
		    if (mTrack[i]->GetIdealBranch()->GetHit(lm)==hitbra[distind[k]]) 
		      TheNewHitIsGood=1;
		  if (TheNewHitIsGood==0) {
		    branch_new->SetIsGoodOld(branch->GetIsGood());
		    branch_new->SetIsGood(0);
		  }
		}
		else {
		  branch_new->SetIsGoodOld(branch->GetIsGood());
		  branch_new->SetIsGood(0);
		}		
	      }
	    }
	    else {
	      delete branch_new;
	      if(mDebugLevel>0) {
		cout << "  hit was not added to the branch *1*"<<endl;	    
		cout<<" hit id ="<<hitbra[distind[k]]->GetId()
		    <<" Nbranch="<<hitbra[distind[k]]->GetNBranch()
		    <<" MaxBranches="<<hitbra[distind[k]]->GetMaxBranches()
		    <<" NShare="<<hitbra[distind[k]]->GetNShare()
		    <<" MaxShare="<<hitbra[distind[k]]->GetMaxShare()<<endl;	
      }
	      continue;
	    }
	  }
	  else
	    if(mDebugLevel>0)
	      cout << "  duplication error"<<endl;
	  if(mDebugLevel>3)
	    cout << " done..."<<endl;
	} //for (k=0;k<kk...
	// the last hit to join is connected to the old branch
	if(mDebugLevel>3)
	    cout << " the last...  k= "<<k<<endl;

	if (hitbra[distind[k]]->JoinBranch(branch,mTrack[i])==1) {
	  branch->AddHit(hitbra[distind[k]],distbra[distind[k]]);
	  RefitBranch(branch,NULL,-1,0,&fitstatus);
	  branch->SetStep(10*mSuperPass+mPass);
	  if (mIdealTracking==1) {
	    branch->mHitPosition=HitPosition;
	    // we check if isgood is still good or not (for debugging) 
	    if (branch->GetNHits()==1 || branch->GetIsGood()==1) {
	      TheNewHitIsGood=0;
	      for (lm=0;lm<mTrack[i]->GetIdealBranch()->GetNHits();lm++)
		if (mTrack[i]->GetIdealBranch()->GetHit(lm)==hitbra[distind[k]]) TheNewHitIsGood=1;
	      //	    if (TheNewHitIsGood==1 && branch->GetNHits()==1) branch->SetIsGood(1);
	      if (TheNewHitIsGood==0) {
		branch->SetIsGoodOld(branch->GetIsGood());
		branch->SetIsGood(0);
	      }
	    }
	    else {
	      branch->SetIsGoodOld(branch->GetIsGood());
	      branch->SetIsGood(0);
	    }
	  }
	}
	else {
	  delete branch;
	  if(mDebugLevel>0) {
	    cout << "  hit was not added to the branch *2*"<<endl;	    	
	    cout<<" hit id ="<<hitbra[distind[k]]->GetId()
		<<" Nbranch="<<hitbra[distind[k]]->GetNBranch()
		<<" MaxBranches="<<hitbra[distind[k]]->GetMaxBranches()
		<<" NShare="<<hitbra[distind[k]]->GetNShare()
		<<" MaxShare="<<hitbra[distind[k]]->GetMaxShare()<<endl;	
	  }
	}
      } //end of if (kk>0)...          
    } // end of "for (j=0;j<mTrack[i]->GetNBranches();j++) "
    if (mIdealTracking==1) {
      // we have to loop again on the branches to check if one good survives
      // if several good branches become bad we set GoodOld to zero for all 
      // except the first to avoid double counting.
      OneIsGood=0;
      SeveralWereGood=0;
      IndexFirstWasGood=0;
      for (j=0;j<mTrack[i]->GetNBranches();j++)
	if (mTrack[i]->GetBranch(j)->GetIsGood()==1) OneIsGood=1;
      if (OneIsGood==0) {
	for (j=0;j<mTrack[i]->GetNBranches();j++) {
	  if (mTrack[i]->GetBranch(j)->GetIsGoodOld()==1 && SeveralWereGood==0)
	    IndexFirstWasGood=j;
	  if (mTrack[i]->GetBranch(j)->GetIsGoodOld()==1) SeveralWereGood++;
	}
	if (SeveralWereGood>1) 
	  for (j=0;j<mTrack[i]->GetNBranches();j++) 
	    if (mTrack[i]->GetBranch(j)->GetIsGoodOld()==1 && j!=IndexFirstWasGood)
	      mTrack[i]->GetBranch(j)->SetIsGoodOld(0);
      }
    }
    if(mDebugLevel>2)
      cout << "loop over the branches in the track STOP"<<endl;
  }// end of "for (i=0;i<mNTrack;i++)"

  if(mDebugLevel>2) cout << "loop over the tracks STOP"<<endl;


  if(mDebugLevel>2)
    cout<<"StEstMaker::Tracking ****STOP****"<<endl;

  return 0;
}	    
