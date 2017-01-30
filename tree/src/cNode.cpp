/*
 * cDatanode.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: jonas
 */

#include "cNode.h"
cNode::cNode() {}
cNode::~cNode(){}

//
//=====================================================================================================================
//

cDatanode::cDatanode(cData* _data)
{
	data = _data;
	nextBigger = new cEndnode();
	nextSmaller = new cEndnode();
}//constructor

cDatanode::~cDatanode()
{
	delete data;
	data = NULL;
}//Destructor

cData cDatanode::getDataObject()
{
	return *data;
}//getDataObject

void cDatanode::insert(cData* _data, cNode** _me)
{
	if (*_data > *data)
		//nextBigger->isEnd() ? (void)(nextBigger = new cDatanode(_data)) : nextBigger->insert(_data);
		nextBigger->insert(_data, &nextBigger);
	else
		nextSmaller->insert(_data, &nextSmaller);
		//nextSmaller->isEnd() ? (void)(nextSmaller = new cDatanode(_data)) : nextSmaller->insert(_data);
}//insert

void cDatanode::remove(cData* _data, list<cData>* _list)
{
	if(*_data == *data)
	{
		nextSmaller->getSortet(_list);
		nextBigger->getSortet(_list);
	}
	else if (*_data > *data)
		nextBigger->remove(_data, _list);
	else if (*_data < *data)
		nextSmaller->remove(_data, _list);
}//remove

cData* cDatanode::search(string _search)
{
	if(*data > _search)
		return nextSmaller->search(_search);
	else if(*data < _search)
		return nextBigger->search(_search);
	else if(*data==_search)
		return data;
	return NULL;
}//search

bool cDatanode::isEnd()
{
	return false;
}//isEnd

void cDatanode::getSortet(list<cData>* _list)
{
	nextSmaller->getSortet(_list);
	_list->push_back(*data);
	nextBigger->getSortet(_list);
}//getSorte

void cDatanode::clear()
{
	nextSmaller->clear();
	delete nextSmaller;
	nextBigger->clear();
	delete nextSmaller;
}

//
//==============================================================================================================================
//

cEndnode::cEndnode() {}
cEndnode::~cEndnode() {}

bool cEndnode::isEnd()
{
	delete this; ///TODO Check if it works!!!
	return true;
}

cData cEndnode::getDataObject()
{
	return (cData)NULL;
}

void cEndnode::insert(cData* _data, cNode** _me)
{
	*_me = new cDatanode(_data);
	delete this;
}

void cEndnode::remove(cData*, list<cData>*)
{
	return;
}

cData* cEndnode::search(string)
{
	return NULL;
}

void cEndnode::getSortet(list<cData>* _list)
{
	return;
}

void cEndnode::clear()
{
	return;
}

























