#include "GamepadController.h"

#include <algorithm>

GamepadController::GamepadController() {
	std::fill(std::begin(PS2buf), std::end(PS2buf), 0);
}

void GamepadController::PS2_RWByte(unsigned char dat) {}

unsigned char GamepadController::Get_PS22DAT(unsigned char* buf) {
	return 10;
}
