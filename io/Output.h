#pragma once
#include <map>

#include "../data/Data.h"
#include "../data/OutputType.h"

class Output {
   public:
	virtual void push(std::map<outputType, Data*>*) const = 0;
};