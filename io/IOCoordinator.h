#pragma once
#include <map>
#include <memory>
#include <vector>

#include "../io/Input.h"
#include "../io/Output.h"
#include "../logic/DataProcessor.h"

class IOCoordinator {
   public:
	IOCoordinator(DataProcessor* processor);
	~IOCoordinator();
	void start() const;
	void addInputObject(Input* input);
	void addOutputObject(Output* output);

   private:
	std::vector<Input*> inputs;
	std::vector<Output*> outputs;
	DataProcessor* processor = nullptr;

	std::unique_ptr<std::map<inputType, Data>> getInputs() const;
	std::unique_ptr<std::map<outputType, Data>> process() const;
	void pushOutputs() const;

};