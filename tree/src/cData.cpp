/*
 * cData.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: jonas
 */

#include "cData.h"

cData::cData(string _data)
{
	sData = _data;
}

cData::~cData()
{

}

string cData::getData()
{
	return sData;
}


bool cData::operator<(cData _data)
{
	if(sData.compare(_data.getData()) < 0)
		return true;
	else
		return false;
}
bool cData::operator>(cData _data)
{
	if(sData.compare(_data.getData()) > 0)
		return true;
	else
		return false;
}
bool cData::operator<(string _string)
{
	if(sData.compare(_string) < 0)
		return true;
	else
		return false;
}
bool cData::operator>(string _string)
{
	if(sData.compare(_string) > 0)
		return true;
	else
		return false;
}
bool cData::operator==(cData _data)
{
	if(_data.getData() == sData)
		return true;
	 return false;
}
bool cData::operator==(string _data)
{
	if(sData ==  _data)
		return true;
	return false;
}
cData *cData::clone()
{
	return new cData(sData);
}


