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
	a->insert("z");
	a->insert("f");
	a->insert("a");
	a->insert("n");
	a->insert("p");
	a->insert("k");
	a->draw();
	cout << "-------------------" << endl;
	list<cData> list, list2;
	a->getList(&list);

	list2 = list;

	unsigned int asdf = list2.size();

	for(unsigned int i = 0; i < asdf;i++)
	{
		cout << list2.front().getData() << ", ";
		list2.pop_front();
	}
	cout << endl;

	a->clear();
	a->insertList(&list);
	a->draw();

	delete a;
	/*while(1)
	{
		a->insert("h");
		a->insert("y");
		a->insert("k");
		a->insert("z");
		a->remove(a->search("h"));
		a->remove(a->search("k"));
		a->clear();
	}*/

	return 0;
}



