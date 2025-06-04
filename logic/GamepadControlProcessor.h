#pragma once
#include "DataProcessor.h"

class GamepadControlProcessor : public DataProcessor {
public:
	std::map<outputType, Data>* process(std::map<inputType, Data>*) override;

	~GamepadControlProcessor() override;
};