#pragma once
#include "IOCoordinator.h"

#include <map>
#include <utility>

#include "Input.h"

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
	return processor->process(getInputs());
}

void IOCoorindator::pushOutputs() {
	auto data = process();
	for (Output* o : outputs) {
		o->push(data);
	}
}