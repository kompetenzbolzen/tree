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
	delete nextSmaller;
	delete nextBigger;
}//Destructor

cData cDatanode::getDataObject()
{
	return *data;
}//getDataObject

void cDatanode::insert(cData* _data, cNode** _me)
{
	if (*_data > *data)
		nextBigger->insert(_data, &nextBigger);
	else
		nextSmaller->insert(_data, &nextSmaller);
}//insert

void cDatanode::remove(cData* _data, list<cData>* _list, cNode** _me)
{
	if(*_data == *data)
	{
		nextSmaller->getSortet(_list);
		nextBigger->getSortet(_list);
		*_me = new cEndnode();
		delete this;
	}
	else if (*_data > *data)
		nextBigger->remove(_data, _list, &nextBigger);
	else if (*_data < *data)
		nextSmaller->remove(_data, _list, &nextSmaller);
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

void cDatanode::getSortet(list<cData>* _list)
{
	nextSmaller->getSortet(_list);
	_list->push_back(*data);
	nextBigger->getSortet(_list);
}//getSorte

void cDatanode::draw(int _depth)
{
	for (int i = 0; i <= _depth; i++)
		cout << " ";
	cout << "|-" << data->getData() << endl;

	nextSmaller->draw(_depth + 1);
	nextBigger->draw(_depth + 1);

}
//
//==============================================================================================================================
//

cEndnode::cEndnode() {}
cEndnode::~cEndnode() {}


cData cEndnode::getDataObject()
{
	return (cData)NULL;
}

void cEndnode::insert(cData* _data, cNode** _me)
{
	*_me = new cDatanode(_data);
	delete this;
}

void cEndnode::remove(cData*, list<cData>*, cNode**)
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

void cEndnode::draw(int _depth)
{
	for (int i = 0; i <= _depth; i++)
		cout << " ";

	cout << "|-$\n";
}























