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
	a->insert("servus");
	a->insert("moinmoin");
	a->draw();
	cout << "-------------------" << endl;
	a->remove(a->search("Hallo"));
	a->draw();
	cout << "clear\n";
	a->clear();

	/*while(1)
	{
		a->insert("h");
		a->insert("y");
		a->insert("k");
		a->insert("h");
		a->remove(a->search("h"));
		a->clear();
	}*/

	return 0;
}



