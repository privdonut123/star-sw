/***************************************************************************
 *
 * $Id: StDbNode.cc,v 1.1 2000/01/10 20:37:54 porter Exp $
 *
 * Author: R. Jeff Porter
 ***************************************************************************
 *
 * Description: Base-class database entities
 *
 ***************************************************************************
 *
 * $Log: StDbNode.cc,v $
 * Revision 1.1  2000/01/10 20:37:54  porter
 * expanded functionality based on planned additions or feedback from Online work.
 * update includes:
 * 	1. basis for real transaction model with roll-back
 * 	2. limited SQL access via the manager for run-log & tagDb
 * 	3. balance obtained between enumerated & string access to databases
 * 	4. 3-levels of diagnostic output: Quiet, Normal, Verbose
 * 	5. restructured Node model for better XML support
 *
 *
 ***************************************************************************/

#include "StDbNode.hh"
#include <iostream.h>
   
StDbNode::StDbNode(StDbNodeInfo* node) {

mnode.setNodeInfo(node);
misConfigured = true;
misNode = true;

}

StDbNode::StDbNode(const char* name, const char* versionKey){

mnode.mstrCpy(mnode.name,name);
mnode.mstrCpy(mnode.versionKey,versionKey);
misConfigured = false;
misNode = false;


}

StDbNode::StDbNode(StDbNode& node){

node.getNodeInfo(&mnode);
misConfigured = node.IsConfigured();
misNode = node.IsNode();

}

/////////////////////////////////////////////////////////////

void
StDbNode::setNodeInfo(StDbNodeInfo* node) {
mnode.setNodeInfo(node);
}

/////////////////////////////////////////////////////////////

void
StDbNode::getNodeInfo(StDbNodeInfo* node){
node->deleteInfoPointers();
node->copyInfo(&mnode);
}

char*
StDbNode::getName() { return mnode.mstrDup((const char*)mnode.name); };

char*
StDbNode::getVersion()  { return mnode.mstrDup((const char*)mnode.versionKey); }

char*
StDbNode::getDbName()  { return mnode.mstrDup((const char*)mnode.dbName); }

char*
StDbNode::getElementID()  { return mnode.mstrDup((const char*)mnode.elementID); }

int*
StDbNode::getElementID(int& nrows) { return mnode.getElementID((const char*)mnode.elementID, nrows); }

void
StDbNode::setName(const char* nodeName){ mnode.mstrCpy(mnode.name,nodeName);}

void
StDbNode::setVersion(const char* version){ mnode.mstrCpy(mnode.versionKey,version);}

void
StDbNode::setDbName(const char* nodeDbName){ mnode.mstrCpy(mnode.dbName,nodeDbName);}

void
StDbNode::setElementID(const char* elementID) { mnode.mstrCpy(mnode.elementID,elementID); }














