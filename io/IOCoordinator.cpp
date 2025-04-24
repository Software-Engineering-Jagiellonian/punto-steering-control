#pragma once
#include "IOCoordinator.h"

#include <map>
#include <utility>

#include "Input.h"

template <typename T1, typename T2>
void freeMap(std::map<T1, T2*>* map) {
	for (auto& p : *map) {
		delete p.second;
	}
	delete map;
	map = nullptr;
}

std::map<inputType, Data*>* IOCoorindator::getInputs() {
	std::map<inputType, Data*>* map = new std::map<inputType, Data*>;
	for (Input* i : inputs) {
		auto* data = i->get();
		auto type = i->type();
		map->insert(std::pair{type, data});
	}
	return map;
}

std::map<outputType, Data*>* IOCoorindator::process() {
	auto inputsData = getInputs();
	auto result = processor->process(inputsData);
	freeMap(inputsData);
	return result;
}

void IOCoorindator::pushOutputs() {
	auto data = process();
	for (Output* o : outputs) {
		o->push(data);
	}
}
