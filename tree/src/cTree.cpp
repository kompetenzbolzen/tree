/*
 * cTree.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: jonas
 */

#include "cTree.h"

cTree::cTree()
{
	root = new cEndnode();
}

cTree::~cTree()
{
	delete root;
}

void cTree::insert(cData* _data)
{
	root->insert(_data, &root);
}

void cTree::insert(string _data)
{
	cData* tmp = new cData(_data);
	insert(tmp);
}

void cTree::remove(cData* _data)
{
	list<cData> dataList; //List of Data that has to be re-inserted into the tree
	root->remove(_data, &dataList, &root);

	///TODO: Optimize!!!
	while(!dataList.empty())
	{
		insert(dataList.front().clone());
		dataList.pop_front();
	}
}

void cTree::getList(list<cData>* _list)
{
	root->getSortet(_list);
}

void cTree::draw()
{
	root->draw(0);
}

cData* cTree::search(string _search)
{
	return root->search(_search);
}

void cTree::clear()
{
	//root->clear();
	cout << "clearTree\n";
	delete root;
	root = new cEndnode();
}




















