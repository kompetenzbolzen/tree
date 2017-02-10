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

	for (char i = '1'; i <= 'z'; i ++)
	{
		string s(&i);
		a->insert(&s[0]);
	}

	a->draw();
	cout << "-------------------" << endl;
	a->sort();
	a->draw();

	delete a;

	return 0;
}



