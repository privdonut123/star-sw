/***************************************************************************
 *
 * $Id: StDbConfigNode.hh,v 1.10 2000/01/10 20:37:53 porter Exp $
 *
 * Author: R. Jeff Porter
 ***************************************************************************
 *
 * Description:  Node (directory) to hold list of dbtables
 *
 ***************************************************************************
 *
 * $Log: StDbConfigNode.hh,v $
 * Revision 1.10  2000/01/10 20:37:53  porter
 * expanded functionality based on planned additions or feedback from Online work.
 * update includes:
 * 	1. basis for real transaction model with roll-back
 * 	2. limited SQL access via the manager for run-log & tagDb
 * 	3. balance obtained between enumerated & string access to databases
 * 	4. 3-levels of diagnostic output: Quiet, Normal, Verbose
 * 	5. restructured Node model for better XML support
 *
 * Revision 1.9  1999/12/28 21:31:41  porter
 * added 'using std::vector' and 'using std::list' for Solaris CC5 compilation.
 * Also fixed some warnings arising from the CC5 compiles
 *
 * Revision 1.8  1999/12/03 22:24:01  porter
 * expanded functionality used by online, fixed bug in
 * mysqlAccessor::getElementID(char*), & update StDbDataSet to
 * conform to changes in Xml reader & writer
 *
 * Revision 1.7  1999/10/19 14:30:38  porter
 * modifications relevant to use with StDbBroker and future merging with
 * "params" database structure + some docs + suppressing diagnostics messages
 *
 * Revision 1.6  1999/09/30 02:06:03  porter
 * add StDbTime to better handle timestamps, modify SQL content (mysqlAccessor)
 * allow multiple rows (StDbTable), & Added the comment sections at top of
 * each header and src file
 *
 **************************************************************************/
#ifndef STDBCONFIGNODE_HH
#define STDBCONFIGNODE_HH

#include "StDbNode.hh"

class StDbTable;
class StDbFactoryI;
class TableIter;


#ifndef __CINT__
#include <list>


#ifdef ST_NO_TEMPLATE_DEF_ARGS
typedef list<StDbTable*, allocator<StDbTable*> > TableList;
#else
using std::list;
typedef list<StDbTable*> TableList;
#endif
#endif
#ifdef __CINT__
class TableList;
#endif

class TableIter;

class StDbConfigNode : public StDbNode {

 friend class TableIter;

private:

 StDbConfigNode* mfirstChildNode;
 StDbConfigNode* mnextNode;
 StDbConfigNode* mparentNode;

protected:

  void zeroNodes(){
    mfirstChildNode = 0;
    mnextNode = 0;
    mparentNode = 0;
    mhasData = false;
    mfactory = 0;
  };


 StDbFactoryI* mfactory;
 TableList     mTables;
 bool          mhasData;

 void deleteTables();
 bool compareTables(StDbTable* tab1, StDbTable* tab2);
 void resolveNodeInfo(StDbNodeInfo*& node);

public:

  //  StDbConfigNode() { zeroNodes();};
  StDbConfigNode( StDbType type, 
                  StDbDomain domain, 
                  const char* nodeName, 
                  const char* configName="none");

  StDbConfigNode( StDbConfigNode* parent, 
                  const char* nodeName, 
                  const char* configName);

  StDbConfigNode( StDbConfigNode* parent, 
                  StDbNodeInfo* node);

  

  virtual ~StDbConfigNode(); 

  virtual void resetConfig(const char* configName);
  
  // set & get node relations
  virtual void setNextNode(StDbConfigNode* node) { mnextNode = node;}; 
  virtual void setParentNode(StDbConfigNode* node); 
  virtual void setFirstChildNode(StDbConfigNode* node); 
  virtual void appendNode(StDbConfigNode* node); 

  virtual StDbConfigNode* getNextNode() const { return mnextNode;} ;
  virtual StDbConfigNode* getParentNode() const {return mparentNode;}; 
  virtual StDbConfigNode* getFirstChildNode() const {return mfirstChildNode;}; 

  // Tree operations
  virtual void deleteTree();
  virtual void buildTree();
  virtual void deleteChildren();

  // check container
  virtual bool hasChildren();
  virtual bool hasData();
  virtual void printTree();

  // Table operations
  virtual StDbTable* addDbTable(const char* tableName, 
                                const char* version="default");
  virtual StDbTable* addTable(const char* tableName, 
                              const char* version="default");

  virtual StDbTable* addTable(StDbNodeInfo* node);


  virtual StDbTable* findTable(const char* name, const char* subPath="/");
  virtual StDbTable* findLocalTable(const char* name);
  virtual void removeTable(StDbTable* table);
  virtual TableIter* getTableIter();

  // node operations
  virtual StDbConfigNode* findConfigNode(StDbType type, 
                                         StDbDomain domain, 
                                         const char* subPath);

  virtual StDbConfigNode* findConfigNode(StDbType type, 
                                         StDbDomain domain);

  virtual StDbConfigNode* findConfigNode(const char* subPath);

  virtual bool isNode(StDbType type, StDbDomain domain);

  // For Offline Root CLI
  //ClassDef(StDbConfigNode,0)

}; 

inline
bool StDbConfigNode::isNode(StDbType type, StDbDomain domain){
if(mnode.dbDomain == domain && mnode.dbType == type)return  true;
return false;
}

inline
bool StDbConfigNode::hasData(){ return mhasData;};

inline
bool StDbConfigNode::hasChildren(){ if(mfirstChildNode)return true;
return false;
};


#endif











