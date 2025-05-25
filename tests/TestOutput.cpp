#include "TestOutput.h"

#include <iostream>

#include "data/OutputType.h"

TestOutput::TestOutput(outputType out, bool print = false) : outType(out), print(print) {
}
Data TestOutput::getLastRead() const {
	return this->lastRead;
}
void TestOutput::push(std::map<outputType, Data>* map) {
	auto data = map->at(outType);
	this->lastRead = data;
	if (print) {
		std::cout << this->outType << ": ";
		std::visit([](auto&& value) {
			std::cout << value << std::endl;
		}, data);
	}
}