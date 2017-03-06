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

class cNode;

struct sSubTree
{
	cNode *nextBigger;
	cNode *nextSmaller;
};

class cNode  {
public:
	cNode();
	virtual ~cNode();

	virtual cData getDataObject() = 0;
	/*
	 * returns dataObject
	 */
	virtual void insert(cData* _data,  cNode** _me) = 0;
	/*
	 * Inserts *cData into tree
	 * cNode** required to change pointer in the caller's pointer to next element
	 */
	virtual void insert(cNode* _data, cNode** _me) = 0;
	/*
	 * Overloading Function to be able to insert complete subtrees
	 */
	virtual void remove(cData* _data, sSubTree* _subtree, cNode** _me) = 0;
	/*
	 * Removes *cData from tree. Its subtree is stored in sSubTree*. cNode** refers to pointer to pointer to self to be able to change reference
	 */
	virtual cData* search(string _data) = 0;
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	virtual cData* getById(unsigned int _id, unsigned int& _cntr) = 0;
	/*
	 * searches for obejct ID (-> inorder)
	 * int: wanted id
	 * int&: id counter
	 */
	virtual void getSortet(list<cData>* _list) = 0;
	/*
	 * saves inorder list to *_list
	 */
	virtual unsigned int  getSubtreeSize() = 0;
	/*
	 * returns size of subtree
	 */
	virtual unsigned int getDepth(unsigned int _deppth) = 0;
	/*
	 * returns maximum depth under node
	 * unsigned int: depth of parent
	 */
	virtual void draw(int _depth) = 0;
	/*
	 *draws tree in ASCII
	 */
	virtual sSubTree getSubTree() = 0;
	/*
	 * Returns subtree of this Node, nextSmaller and nextBigger are set to new Endnodes
	 */
	virtual cNode *getFirstNode(cNode** _me) = 0;
	/*
	 * Returns Pointer to Inorder-First element in Tree
	 */
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
	void insert(cData*, cNode**);
	/*
	 * Inserts *cData into tree
	 */
	void insert(cNode*, cNode**);
	void remove(cData*, sSubTree*, cNode**);
	/*
	 * Removes *cData from tree
	 */
	cData* search(string);
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	cData* getById(unsigned int, unsigned int&);

	void getSortet(list<cData>* _list);
	/*
	 * Copy all cData Instances into _list
	 */
	void draw(int _depth);
	unsigned int getSubtreeSize();
	unsigned int getDepth(unsigned int);
	sSubTree getSubTree();
	cNode *getFirstNode(cNode**);
private:
	cNode *nextSmaller, *nextBigger;
	cData *data;

};

class cEndnode:public cNode
{
public:
	//TODO Optimize! there are 2^(n+1) endnodes in a tree wich each take 4B!
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
	void insert(cNode*, cNode**);
	void remove(cData*, sSubTree*, cNode**);
	/*
	 * Removes *cData from tree
	 */
	cData* search(string);
	/*
	 * Searches for a Object by its Primary Key, returns pointer pointing at result (NULL if no result)
	 */
	cData* getById(unsigned int, unsigned int&);

	void getSortet(list<cData>* _list);

	unsigned int getSubtreeSize();

	unsigned int getDepth(unsigned int);

	void draw(int _depth);

	sSubTree getSubTree();

	cNode *getFirstNode(cNode**);
private:
};

#endif /* SRC_CNODE_H_ */
