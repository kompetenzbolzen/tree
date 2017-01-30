/*
 * cNode.h
 *
 *  Created on: Jan 25, 2017
 *      Author: jonas
 */

#ifndef SRC_CNODE_H_
#define SRC_CNODE_H_

#include "cData.h"
#include <list>

using namespace std;

class cNode  {
public:
	cNode();
	virtual ~cNode();

	virtual cData getDataObject() = 0;
	/*
	 * returns dataObject
	 */
	virtual void insert(cData*,  cNode* = NULL) = 0;
	/*
	 * Inserts *cData into tree
	 */
	virtual void remove(cData*) = 0;
	/*
	 * Removes *cData from tree
	 */
	virtual cData* search(string) = 0;
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	virtual bool isEnd() = 0;
	/*
	 * returns false
	 */
	virtual list<cData>* getSortet(list<cData>* _list) = 0;

};

class cDatanode:public cNode
{
	cDatanode(cData* _data);
	~cDatanode();

	cData getDataObject();
	/*
	 * returns dataObject
	 */
	void insert(cData*, cNode* = NULL);
	/*
	 * Inserts *cData into tree
	 */
	void remove(cData*);
	/*
	 * Removes *cData from tree
	 */
	cData* search(string);
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	bool isEnd();
	/*
	 * returns false
	 */
	list<cData>* getSortet(list<cData>* _list);
private:
	cNode *nextSmaller, *nextBigger;
	cData *data;

};

class cEndnode:public cNode
{
public:
	cEndnode();
	~cEndnode();

	cData getDataObject();
	/*
	 * returns dataObject
	 */
	void insert(cData*, cNode* );
	/*
	 * Inserts *cData into tree
	 */
	void remove(cData*);
	/*
	 * Removes *cData from tree
	 */
	cData* search(string);
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	bool isEnd();
	/*
	 * returns false
	 */
	list<cData>* getSortet(list<cData>* _list);

private:
};

#endif /* SRC_CNODE_H_ */
