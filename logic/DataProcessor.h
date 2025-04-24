#pragma once
#include <map>

#include "../data/Data.h"
#include "../data/InputType.h"
#include "../data/OutputType.h"

class DataProcessor {
   public:
	virtual std::map<outputType, Data*>* process(std::map<inputType, Data*>*) = 0;
};