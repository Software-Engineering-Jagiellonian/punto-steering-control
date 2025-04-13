#pragma once
#include "../data/Data.h"
#include "../data/InputType.h"
#include "../data/OutputType.h"
#include <map>

class DataProcessor {
  virtual std::map<outputType, Data> process(std::map<inputType, Data>) = 0;
};