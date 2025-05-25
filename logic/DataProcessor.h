#pragma once
#include <map>

#include "data/Data.h"
#include "data/OutputType.h"
#include "data/InputType.h"

class DataProcessor {
   public:
	virtual ~DataProcessor() = default;
	virtual std::map<outputType, Data>* process(std::map<inputType, Data>*) = 0;
};