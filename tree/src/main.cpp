/*
 * main.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: jonas
 */
#include <iostream>
#include <string>
#include <sstream>
#include "cTree.h"

using namespace std;

int main (void)
{
	cTree* a = new cTree();

	for (char b = ' '; b <= '~'; b++)
	{
		stringstream ss;
		string y;

		ss << b;
		ss >> y;

		a->insert(y);
	}

	a->draw();
	cout << "-------------------" << endl;
	a->sort();
	a->draw();

	for(unsigned int i = 0; i < a->size(); i++)
	{
		cout << (*a)[i]->getData() << ", ";
	}
	cout << endl;


	/*while(1)
	{
		for (char i = ' '; i <= '~'; i ++)
		{
			string s(&i);
			a->insert(&s[0]);
		}
		a->sort();
		a->clear();
	}*/

	delete a;

	return 0;
}



