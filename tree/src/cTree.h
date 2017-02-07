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

using namespace std;

class cTree{
public:
	cTree();
	~cTree();
	void insert(cData*);
	void insert(string);
	void balance();
	void getList(list<cData>*);
	void remove(cData*);
	void clear();
	cData* search(string);

	void draw();


private:
	cNode* root;

};


#endif /* SRC_CTREE_H_ */
