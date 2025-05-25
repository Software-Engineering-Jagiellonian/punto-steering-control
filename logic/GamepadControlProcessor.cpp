#include "GamepadControlProcessor.h";

std::map<outputType, Data>* GamepadControlProcessor::process(std::map<inputType, Data>* input) {
	auto* output = new std::map<outputType, Data>();

	for (const auto& [key, value] : *input) {
		switch (key) {
			case GamepadInX:
				output->insert({GamepadOutX, value});
				break;
			case GamepadInY:
				output->insert({GamepadOutY, value});
				break;
			default:
				break;
		}
	}

	return output;
}

GamepadControlProcessor::~GamepadControlProcessor() = default;