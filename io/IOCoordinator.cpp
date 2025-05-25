#include "IOCoordinator.h"

#include <iostream>
#include <map>
#include <memory>

#include "Input.h"

IOCoordinator::IOCoordinator(DataProcessor* dataProcessor) : processor(dataProcessor) {}

IOCoordinator::~IOCoordinator() {
	for (auto* input : inputs) {
		delete input;
	}
	for (auto* output : outputs) {
		delete output;
	}
	delete processor;
}

void IOCoordinator::start() const {

	for (auto* input : inputs) {
		input->init();
	}
	int checksum = 0;
	do {
		checksum = 0;
		for (auto* input : inputs) {
			checksum += input->isWorking();
		}
		std::cout << checksum << std::endl;
	} while (checksum > 0);

	if (processor == nullptr) {
		return;
	}

	while (true) {
		pushOutputs();
	}
}

std::unique_ptr<std::map<inputType, Data>> IOCoordinator::getInputs() const {
	auto map = std::make_unique<std::map<inputType, Data>>();
	for (const auto* input : inputs) {
		Data data = input->get();
		inputType type = input->type();
		map->emplace(type, data);
	}
	return map;
}

std::unique_ptr<std::map<outputType, Data>> IOCoordinator::process() const {
	auto inputsData = getInputs();
	auto result = std::unique_ptr<std::map<outputType, Data>>(processor->process(inputsData.get()));
	return result;
}

void IOCoordinator::pushOutputs() const {
	auto data = process();
	for (auto* output : outputs) {
		output->push(data.get());
	}
}


void IOCoordinator::addInputObject(Input* input) {
	this->inputs.push_back(input);
}

void IOCoordinator::addOutputObject(Output* output) {
	this->outputs.push_back(output);
}