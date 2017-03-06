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

void fill(void);

void stress(void);

int main (void)
{
	a = new cTree();
	int i; //Argument Integer
	int iInputOption; //Input Selection
	string s; //Argument String

	cout << endl;
	cout << "| |" << endl;
	cout << "| |_ _ __ ___  ___ " << endl;
	cout << "| __| '__/ _ \\/ _ \\" << endl;
	cout << "| |_| | |  __/  __/" << endl;
	cout << " \\__|_|  \\___|\\___|" << endl << endl;


	while (1)
	{
		cout << "===========================\n";
		cout << "[1] Fill with Data\n";
		cout << "[2] Clear\n";
		cout << "[3] Balance\n";
		cout << "[4] Draw\n";
		cout << "[5] Info\n";
		cout << "[6] Insert\n";
		cout << "[7] Remove\n";
		cout << "[8] Get by Inorder ID\n";
		cout << "[9] Stresstest\n";
		cout << "[0] Exit\n";
		cout << "> ";

		cin >> iInputOption;

		switch(iInputOption)
		{
		case 0: //fill
			return 0;
			break;
		case 1: //fill
			cout << "Filling with Data.....";
			fill();
			cout << "OK\n";
			break;
		case 2: //clear
			a->clear();
			break;
		case 3: //balance
			a->sort();
			break;
		case 4: //draw
			a->draw();
			break;
		case 5: //Info
			cout << "Size: " << a->size() << ", Depth: " << a->depth() << ", Unbalance: " << a->gradeOfUnbalance() << endl << endl;
			break;
		case 6: //Insert
			cout << "Insert: ";
			cin >> s;
			a->insert(s);
			break;
		case 7: //Remove
			cout << "ID to remove: ";
			cin >> i;
			a->remove((*a)[i]);
			break;
		case 8: //get by ID
			cout << "ID to get: ";
			cin >> i;
			cout << i << ": " << (*a)[i]->getData() << endl;
			break;
		case 9:
			cout << "Started Stress-Loop. Stop with Ctrl+C\n";
			stress();
			break;
		default:
			cout << "Unrecognized Command\n";
			break;
		}
	}
	delete a;

	return 0;
}

void fill(void)
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


void stress(void)
{
	while(1)
	{
		fill();
		a->sort();
		for(unsigned int i = 0; i < a->size(); i++)
		{
			a->remove((*a)[i]);
		}
	}
}
