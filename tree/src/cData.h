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
	cData(string _data);
	/*
	 * Initializes cData with _data as saved Information
	 */
	~cData();

	string getData();
	/*
	 * Returns content of cData instance as String
	 */

	bool operator<(cData);
	bool operator>(cData);
	bool operator<(string);
	bool operator>(string);
	bool operator==(cData);
	bool operator==(string);

private:
	string sData;
};




#endif /* SRC_CDATA_H_ */
