#pragma once
#include <vector>

#include "Input.h"
#include "Output.h"

class IOCoorindator {
   public:
	void start();

   private:
	std::vector<Input> inputs;
	std::vector<Output> outputs;
};