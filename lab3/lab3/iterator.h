#pragma once
#include "list.h"
#include <string>

using namespace std;

class Iterator {
public:
	virtual void next() = 0;
	virtual bool hasNext() = 0;
	virtual list current_list() = 0;
	virtual string current_code() = 0;
};