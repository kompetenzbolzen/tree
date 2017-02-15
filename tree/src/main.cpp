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

cTree* a;

void fill()
{
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
}

int main (void)
{
	a = new cTree();
	int iInputOption;

	while (1)
	{
		cout << "[1] Fill with Data\n";
		cout << "[2] Clear\n";
		cout << "[3] Balance\n";
		cout << "[4] Draw\n";
		cout << "[5] Info\n";
		cout << "> ";

		cin >> iInputOption;

		switch(iInputOption)
		{
		case 1:
			cout << "Filling with Data.....";
			fill();
			cout << "OK\n";
			break;
		case 2:
			a->clear();
			break;
		case 3:
			a->sort();
			break;
		case 4:
			a->draw();
			break;
		default:
			cout << "Unrecognized Command\n";
			break;
		}
	}
	delete a;

	return 0;
}



