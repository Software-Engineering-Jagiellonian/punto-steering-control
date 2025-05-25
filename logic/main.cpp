#include <iostream>
#include <thread>

#include "GamepadControlProcessor.h"
#include "io/IOCoordinator.h"
#include "io/interface/GamepadController.h"
#include "io/interface/GamepadInX.h"
#include "io/interface/GamepadInY.h"
#include "tests/TestOutput.h"

int main() {
	auto* gamepad = new GamepadController();
	std::thread gamepad_thread(&GamepadController::init, gamepad);
	gamepad_thread.detach();

	DataProcessor* data_processor = new GamepadControlProcessor();
	auto* ioc = new IOCoordinator(data_processor);
	//inputs
	ioc->addInputObject(new GamepadWrapper::GamepadInX(gamepad));
	ioc->addInputObject(new GamepadWrapper::GamepadInY(gamepad));
	//outputs
	ioc->addOutputObject(new TestOutput(outputType::GamepadOutX, true));
	ioc->addOutputObject(new TestOutput(outputType::GamepadOutY, true));

	ioc->start();
	delete ioc;
	delete gamepad;
}
