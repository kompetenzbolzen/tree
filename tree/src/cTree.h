/*
 * cTree.h
 *
 *  Created on: Jan 25, 2017
 *      Author: jonas
 */

#ifndef SRC_CTREE_H_
#define SRC_CTREE_H_

#include "cNode.h"
#include <string>
#include <list>
#include <math.h>

using namespace std;

class cTree{
public:
	cTree();
	~cTree();
	void insert(cData*);
	/*
	 * inserts element into tree
	 */
	void insert(string);
	/*
	 * inserts string into tree
	 */
	void insertList(list<cData>*);
	/*
	 * inserts List into tree as balanced as possible
	 * assumes ordered list!
	 */
	void getList(list<cData>*);
	/*
	 * returns inorder list
	 */
	void remove(cData*);
	/*
	 * remove node from tree
	 */
	void sort();
	/*
	 * balances tree
	 */
	void clear();
	/*
	 * emptys the tree
	 */
	unsigned int size();
	/*
	 * returns overall size
	 */
	unsigned int depth();
	/*
	 * returns maximum depth
	 */
	unsigned int gradeOfUnbalance();
	/*
	 * returns integer value indicating to with the tree is unsymmetrical
	 * 0: tree is symmetrical
	 * x: tree is x-times deeper than it could
	 */
	cData* search(string);
	/*
	 * returns pointer to matching object
	 * NULL if no match
	 */
	void draw();
	/*
	 * draws subtree in ASCII
	 */
	cData* operator[](unsigned int);


private:
	cNode* root;

};


#endif /* SRC_CTREE_H_ */
