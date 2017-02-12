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

	cout << "Filling with data..." << endl;
	for (char b = ' '; b <= '~'; b++) //insert some data into tree
	{
		for(char c = ' '; c<= '~'; c++)
		{
			stringstream ss;
			ss << b;
			ss << c;

			a->insert(ss.str());
		}
	}

	//a->draw();
	cout << "size: "<< a->size() << endl << "Unbalance: " << a->gradeOfUnbalance() << endl << "Depth: " << a->depth() << endl;
	cout << "deleting element" << endl;
	a->remove((*a)[100]);
	cout << "Balancing..." << endl;
	a->draw();
	a->sort();
	cout << "size: "<< a->size() << endl << "Unbalance: " << a->gradeOfUnbalance() << endl << "Depth: " << a->depth() << endl;
	//
	cout << "-------------------" << endl;
	a->draw();

	/*for(unsigned int i = 0; i < a->size(); i++)
	{
		cout << (*a)[i]->getData() << ", ";
	}
	cout << endl;*/


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



