#pragma once
#include "DataProcessor.h"

class GamepadControlProcessor : public DataProcessor {
	std::map<outputType, Data>* process(std::map<inputType, Data>*) override;

   public:
	~GamepadControlProcessor() override;
};