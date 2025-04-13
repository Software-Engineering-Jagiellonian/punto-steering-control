#pragma once
#include "../data/Data.h"
#include "../data/OutputType.h"
#include <map>

class Output {
public:
  virtual void push(std::map<outputType, Data>) = 0;
};