#include "TestIOCoordinator.h"

// Dummy Input
void DummyInput::init() {
    calledInit = true;
}

int DummyInput::isWorking()  {
    return isWorkingVal ? 1 : 0;
}

Data DummyInput::get() const {
    return 123;  // przykładowa wartość
}

inputType DummyInput::type() const {
    return inputType::GamepadInX;
}


// Dummy Output
void DummyOutput::push(std::map<outputType, Data>* data) {
    if (data) {
        received = *data;
    }
}

DummyOutput::~DummyOutput() = default;

// Dummy Processor
std::map<outputType, Data>* DummyProcessor::process(std::map<inputType, Data>* inputs) {
    auto* result = new std::map<outputType, Data>();
    (*result)[outputType::WheelTurn] = 42.0f;
    return result;
}

// DummyInputStart

int DummyInputStart::isWorking() {
	return workingCalls-- > 0 ? 1 : 0;
}