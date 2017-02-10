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

	insertList(&dataList);
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
	delete root;
	root = new cEndnode();
}

void cTree::insertList(list<cData>* _list)
{
	unsigned int oldSize = _list->size(); //used bc size of list changes during for loop
	list<cData> tmpList;

	if (oldSize <= 0) //Nothing to do if list is empty
		return;

	for (unsigned int i = 0; i < oldSize / 2; i++) //copy first half of list into tmpList, deleting in _list
	{
		tmpList.push_back(_list->front());
		_list->pop_front();
	}

	insert(_list->front().clone()); //middle element of _list is inserted as new root of subtree
	_list->pop_front();

	insertList(&tmpList); //Insert first half(smaller value) of list below new root

	tmpList.clear();

	if(_list->size() <= 0) //Nothing to do if list is empty
		return;

	//TODO Redundant! For loop not needed!
	oldSize = _list->size();
	for (unsigned int i = 0; i < oldSize; i++)
	{
		tmpList.push_back(_list->front());
		_list->pop_front();
	}
	insertList(&tmpList); //Insert second half(bigger value) of list below new root
}

void cTree::sort()
{
	list<cData> sortetList;
	root->getSortet(&sortetList); //get inorder
	clear(); //clear tree
	insertList(&sortetList); //re insert inorderlist
}

unsigned int cTree::size()
{
	return root->getSubtreeSize();
}

unsigned int cTree::depth()
{
	return root->getDepth(0);
}

unsigned int cTree::gradeOfUnbalance()
{
	double minDepth = log2(size());
	unsigned int iDepth = depth();

	return (iDepth / minDepth) - 1; //-1 so 100% = 0
}




















