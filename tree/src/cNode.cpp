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
	else if (*_data == *data)
		return; //data already exists, abort
	else
		nextSmaller->insert(_data, &nextSmaller);
}//insert

void cDatanode::insert(cNode* _data, cNode** _me)
{
	if( _data->getDataObject().isEmpty())
		return; //_data is endnode, return

	if (_data->getDataObject() > *data)
		nextBigger->insert(_data, &nextBigger);
	else if (_data->getDataObject() == *data)
		return; //data already exists, abort
	else
		nextSmaller->insert(_data, &nextSmaller);
}

void cDatanode::remove(cData* _data, sSubTree* _subtree, cNode** _me)
{
	if(*_data == *data)
	{
		//save subtree before deleting
		*_subtree = getSubTree();
		*_me = new cEndnode(); //set pointer to this in parent to new cEndnode
		delete this;
	}
	else if (*_data > *data)
		nextBigger->remove(_data, _subtree, &nextBigger);
	else if (*_data < *data)
		nextSmaller->remove(_data, _subtree, &nextSmaller);
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

cData* cDatanode::getById(unsigned int _id, unsigned int &_cntr)
{
	cData* tmpData = nextSmaller->getById(_id, _cntr);

	if(tmpData)
		return tmpData;

	if(_id == _cntr)
		return data;

	_cntr++;

	return nextBigger->getById(_id, _cntr);
}

void cDatanode::getSortet(list<cData>* _list)
{
	nextSmaller->getSortet(_list);
	_list->push_back(*data);
	nextBigger->getSortet(_list);
}//getSortet

void cDatanode::draw(int _depth)
{
	for (int i = 0; i <= _depth; i++)
		cout << " ";
	cout << "|-" << data->getData() << endl;

	nextSmaller->draw(_depth + 1);
	nextBigger->draw(_depth + 1);

}//draw

unsigned int cDatanode::getDepth(unsigned int _depth)
{
	unsigned int depth1, depth2;

	depth1 = nextSmaller->getDepth(_depth + 1);
	depth2 = nextBigger->getDepth(_depth + 1);

	return depth1 < depth2 ? depth2:depth1; //return bigger depth
}//getDepth

unsigned int cDatanode::getSubtreeSize()
{
	return nextSmaller->getSubtreeSize() + nextBigger->getSubtreeSize() + 1;
}//getSubtreeSize

sSubTree cDatanode::getSubTree()
{
	sSubTree s;
	s.nextBigger = nextBigger;
	s.nextSmaller = nextSmaller;

	nextBigger = new cEndnode();
	nextSmaller = new cEndnode();

	return s;
}

cNode *cDatanode::getFirstNode(cNode** _me)
{
	cNode* ret = nextSmaller->getFirstNode(&nextSmaller);
	if(ret) //Pointer not empty, return ret
	{
		return ret;
	}
	else //Pointer is empty, Return me
	{
		cNode* tmp = *_me;
		*_me = new cEndnode();
		return tmp;
	}
}

//
//==============================================================================================================================
//

cEndnode::cEndnode() { }
cEndnode::~cEndnode() { }

cData cEndnode::getDataObject()
{
	cData tmp("", true);
	return tmp;
}

void cEndnode::insert(cData* _data, cNode** _me)
{
	*_me = new cDatanode(_data);
	delete this;
}

void cEndnode::insert(cNode* _data, cNode** _me)
{
	*_me = _data;
	delete this;
}

void cEndnode::remove(cData*, sSubTree*, cNode**)
{
	return;
}

cData* cEndnode::search(string)
{
	return NULL;
}

cData* cEndnode::getById(unsigned int _id, unsigned int& _cntr)
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

	cout << "|::\n";
}

unsigned int cEndnode::getSubtreeSize()
{
	return 0;
}

unsigned int cEndnode::getDepth(unsigned int _depth)
{
	return _depth;
}

sSubTree cEndnode::getSubTree()
{
	return sSubTree{NULL, NULL};
}

cNode *cEndnode::getFirstNode(cNode** _me){
	return NULL;
}


















