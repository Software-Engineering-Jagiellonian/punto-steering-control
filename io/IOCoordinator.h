#pragma once
#include <map>
#include <vector>

#include "../logic/DataProcessor.h"
#include "Input.h"
#include "Output.h"

class IOCoorindator {
   public:
	void start();

   private:
	std::vector<Input*> inputs;
	std::vector<Output*> outputs;
	DataProcessor* processor;

	std::map<inputType, Data*>* getInputs();
	std::map<outputType, Data*>* process();
	void pushOutputs();
};