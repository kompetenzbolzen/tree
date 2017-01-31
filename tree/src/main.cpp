/*
 * main.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: jonas
 */
#include <iostream>

#include "cTree.h"

int main (void)
{
	cTree* a = new cTree();
	a->insert("Hallo");
	a->insert("faggot");
	a->insert("Arschloch");
	a->draw();
	cout << "-------------------" << endl;
	a->remove(a->search("Hallo"));
	a->draw();

	return 0;
}



