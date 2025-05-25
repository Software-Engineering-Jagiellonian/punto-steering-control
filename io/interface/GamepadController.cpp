#include "GamepadController.h"
#include <algorithm>
#include <libgamepad.hpp>
#include <cstdio>
#include <memory>

GamepadController::GamepadController() = default;

void GamepadController::init() {
	std::shared_ptr<gamepad::hook> hook = gamepad::hook::make();
	hook->set_plug_and_play(true, gamepad::ms(3000));
	auto axis_handler = [this](std::shared_ptr<gamepad::device> dev) {

		auto* event = dev->last_axis_event();
		switch (event->vc) {
			case gamepad::axis::LEFT_STICK_X:
				this->axisX = event->virtual_value;
				break;
			case gamepad::axis::LEFT_STICK_Y:
				this->axisY = event->virtual_value;
				break;
			default:
				break;
		}
		// this->print();
	};

	auto connect_handler = [this](std::shared_ptr<gamepad::device> dev) {
		printf("Connected \n");
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
		printf("Couldn't start gamepad hook \n");
		this->workingState = 2;
	}
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

void GamepadController::print() const {
	printf("x: %f y: %f \n", this->axisX, this->axisY);
}