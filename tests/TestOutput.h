#pragma once
#include "io/Output.h"
#include "data/OutputType.h"

class TestOutput : public Output {
private:
	Data lastRead;
	outputType outType;
	bool print;

   public:
	explicit TestOutput(outputType, bool);
	Data getLastRead() const;
	void push(std::map<outputType, Data>*);
};
