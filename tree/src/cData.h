/*
 * cData.h
 *
 *  Created on: Jan 26, 2017
 *      Author: jonas
 */

#ifndef NULL
#define NULL 0x00
#endif

#ifndef SRC_CDATA_H_
#define SRC_CDATA_H_

#include <string>

using namespace std;

class cData{
public:
	cData(string _data, bool _empty = false);
	/*
	 * Initializes cData with _data as saved Information
	 */
	~cData();

	string getData();
	/*
	 * Returns content of cData instance as String
	 */

	cData* clone();
	/*
	 * clones current cData instance
	 */

	bool isEmpty();

	//Define operators
	bool operator<(cData);
	bool operator>(cData);
	bool operator<(string);
	bool operator>(string);
	bool operator==(cData);
	bool operator==(string);

private:
	bool empty;
	string sData;
};




#endif /* SRC_CDATA_H_ */
