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
#include <iostream>

using namespace std;

class cNode  {
public:
	cNode();
	virtual ~cNode();

	virtual cData getDataObject() = 0;
	/*
	 * returns dataObject
	 */
	virtual void insert(cData*,  cNode** = NULL) = 0;
	/*
	 * Inserts *cData into tree
	 * cNode** required to change pointer in the caller's pointer to next element
	 */
	virtual void remove(cData*, list<cData>*, cNode**) = 0;
	/*
	 * Removes *cData from tree
	 */
	virtual cData* search(string) = 0;
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	virtual void getSortet(list<cData>* _list) = 0;
	/*
	 * gets sortet list
	 */
	virtual unsigned int  getSubtreeSize() = 0;
	/*
	 * returns size of tree under node
	 */
	virtual unsigned int getDepth(unsigned int) = 0;
	/*
	 * returns maximum depth under node
	 */

	virtual void draw(int _depth) = 0;
};

class cDatanode:public cNode
{
public:
	cDatanode(cData* _data);
	~cDatanode();

	cData getDataObject();
	/*
	 * returns dataObject
	 */
	void insert(cData*, cNode** = NULL);
	/*
	 * Inserts *cData into tree
	 */
	void remove(cData*, list<cData>*, cNode**);
	/*
	 * Removes *cData from tree
	 */
	cData* search(string);
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	void getSortet(list<cData>* _list);
	/*
	 * Copy all cData Instances into _list
	 */
	void draw(int _depth);
	unsigned int getSubtreeSize();
	unsigned int getDepth(unsigned int);
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
	void insert(cData*, cNode** );
	/*
	 * Inserts *cData into tree
	 */
	void remove(cData*, list<cData>*, cNode**);
	/*
	 * Removes *cData from tree
	 */
	cData* search(string);
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	void getSortet(list<cData>* _list);

	unsigned int getSubtreeSize();
	unsigned int getDepth(unsigned int);

	void draw(int _depth);
private:
};

#endif /* SRC_CNODE_H_ */
