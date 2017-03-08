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
}//Constructor

cTree::~cTree()
{
	delete root;
}//Destructor

void cTree::insert(cData* _data)
{
	root->insert(_data, &root);
}//insert

void cTree::insert(string _data)
{
	cData* tmp = new cData(_data);
	insert(tmp);
}//insert

void cTree::remove(cData* _data)
{
	//Remove
	sSubTree subTree;
	root->remove(_data, &subTree, &root);

	//Re-Insert subtree
	if(subTree.nextBigger && subTree.nextSmaller)
	{
		cNode* newRoot = subTree.nextSmaller->getFirstNode( &(subTree.nextSmaller)); //returns zero

		if(newRoot) //Only insert if nextSmaller is no Endnode
		{
			root->insert(newRoot, &root );
		}
	}
	if (subTree.nextBigger) {
		if(!subTree.nextBigger->isEndnode()) //Inserting Endnodes is pointless
			root->insert(subTree.nextBigger, &root);
		else
			delete subTree.nextBigger; //Delete pointless Endnode
	}
	if(subTree.nextSmaller) {
		if(!subTree.nextSmaller->isEndnode())
			root->insert(subTree.nextSmaller, &root);
		else
			delete subTree.nextSmaller;
	}
}//remove

void cTree::getList(list<cData>* _list)
{
	root->getSortet(_list);
}//getList

void cTree::draw()
{
	root->draw(0);
}//draw

cData* cTree::search(string _search)
{
	return root->search(_search);
}//search

void cTree::clear()
{
	delete root;
	root = new cEndnode();
}//clear

void cTree::insertList(list<cData>* _list)
{
	unsigned int oldSize = _list->size(); //used bc size of list changes during for-loop
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

	insertList(_list); //Insert second half(bigger value) of list below new root
}//insertList

void cTree::sort()
{
	list<cData> sortetList;
	root->getSortet(&sortetList); //get inorder
	clear(); //clear tree
	insertList(&sortetList); //re insert inorderlist
}//sort

unsigned int cTree::size()
{
	return root->getSubtreeSize();
}//size

unsigned int cTree::depth()
{
	return root->getDepth(0);
}//depth

unsigned int cTree::gradeOfUnbalance()
{
	if(root->getSubtreeSize() == 0)
		return 0;

	double minDepth = log2(size());
	unsigned int iDepth = depth();

	return (iDepth / minDepth) - 1; //-1 so 100% = 0
}//gradeOfUnbalance

cData *cTree::operator [](unsigned int _i)
{
	unsigned int a = 0;
	return root->getById(_i, a);
}



















