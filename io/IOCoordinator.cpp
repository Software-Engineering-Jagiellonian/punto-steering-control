#pragma once

#include "IOCoordinator.h"
#include "Input.h"

#include <map>
#include <memory>

template <typename T1, typename T2>
void freeMap(std::unique_ptr<std::map<T1, T2*>>& map) {
	for (auto& [key, ptr] : *map) {
		delete ptr;
	}
	map.reset();
}

IOCoordinator::IOCoordinator(DataProcessor* dataProcessor) : dataProcessor() {}

void IOCoordinator::start() const {
	for (auto* input : inputs) {
		input->init();
	}

	int checksum = 0;
	do {
		for (auto* input : inputs) {
			checksum += input->isWorking();
		}
	} while (checksum > 0);

	if (processor == nullptr) {
		return;
	}

	while (true) {
		pushOutputs();
	}
}

std::unique_ptr<std::map<inputType, Data*>> IOCoordinator::getInputs() const {
	auto map = std::make_unique<std::map<inputType, Data*>>();
	for (const auto* input : inputs) {
		Data* data = input->get();
		inputType type = input->type();
		map->emplace(type, data);
	}
	return map;
}

std::unique_ptr<std::map<outputType, Data*>> IOCoordinator::process() const {
	auto inputsData = getInputs();
	auto result = std::unique_ptr<std::map<outputType, Data*>>(processor->process(inputsData.get()));
	freeMap(inputsData);
	return result;
}

void IOCoordinator::pushOutputs() const {
	auto data = process();
	for (const auto* output : outputs) {
		output->push(data.get());
	}
	freeMap(data);
}
