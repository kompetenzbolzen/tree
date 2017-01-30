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

using namespace std;

class cTree{
public:
	void insert(cData*);
	void insert(string);

	void remove(cData*);
	cData search(string);


private:

};


#endif /* SRC_CTREE_H_ */
