#include "GamepadController.h"

#include <algorithm>
#include <cstdio>
#include <libgamepad.hpp>

GamepadController::GamepadController() {
}
void GamepadController::init() {
	std::shared_ptr<gamepad::hook> hook = gamepad::hook::make();
	auto axis_handler = [](std::shared_ptr<gamepad::device> dev) {
		printf("Received axis event: Native id: %i, Virtual id: 0x%X (%i) val: %f", dev->last_axis_event()->native_id,
			   dev->last_axis_event()->vc, dev->last_axis_event()->vc, dev->last_axis_event()->virtual_value);
	};

	auto connect_handler = [this](std::shared_ptr<gamepad::device> dev) {
		printf("Connected");
		this->workingState = 0;
		if (!dev->has_binding()) {
			printf("Binding");
		}
	};

	auto disconnect_handler = [this](std::shared_ptr<gamepad::device> dev) {
		this->workingState = 1;
		printf("Disconnected");
	};

	hook->set_axis_event_handler(axis_handler);
	hook->set_connect_event_handler(connect_handler);
	hook->set_disconnect_event_handler(disconnect_handler);

	if (!hook->start()) {
		printf("Couldn't start gamepad hook");
		this->workingState = 2;
	}

	while (true)
		std::this_thread::sleep_for(gamepad::ms(50));
}
int GamepadController::isWorking() {
	return this->workingState;
}
Data* GamepadController::get() const {
	return nullptr;
}
inputType GamepadController::type() const {
	return inputType::Gamepad;
}