/*
 * main.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: jonas
 */
#include <iostream>
#include "cTree.h"

using namespace std;

int main (void)
{
	cTree* a = new cTree();

	/*for (char i = ' '; i <= '~'; i ++)
	{
		string s(&i);
		a->insert(&s[0]);
	}

	a->draw();
	cout << a->size() << "/" << a->depth() << endl;
	cout << a->gradeOfUnbalance() << endl;
	cout << "-------------------" << endl;
	a->sort();
	a->draw();
	cout << a->size() << "/" << a->depth() << endl;
	cout << a->gradeOfUnbalance() << endl;*/

	while(1)
	{
		for (char i = ' '; i <= '~'; i ++)
		{
			string s(&i);
			a->insert(&s[0]);
		}
		a->sort();
		a->clear();
	}

	delete a;

	return 0;
}



