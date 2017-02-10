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
	unsigned int oldSize= _list->size();
	list<cData> tmpList;

	if (oldSize <= 0)
		return;

	for (unsigned int i = 0; i < oldSize / 2; i++)
	{
		tmpList.push_back(_list->front());
		_list->pop_front();
	}

	insert(_list->front().clone());
	_list->pop_front();
	insertList(&tmpList);

	tmpList.clear();

	if(_list->size() <= 0)
		return;

	oldSize = _list->size();
	for (unsigned int i = 0; i < oldSize; i++)
	{
		tmpList.push_back(_list->front());
		_list->pop_front();
	}
	insertList(&tmpList);
}

void cTree::sort()
{
	list<cData> sortetList;
	root->getSortet(&sortetList);
	clear();
	insertList(&sortetList);
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




















