#pragma once
#include "../ExtDevice.h"

class GamepadController : public StatusInterface {
   private:
	unsigned char PS2buf[10];

   public:
	GamepadController();
	void PS2_RWByte(unsigned char dat);
	unsigned char Get_PS22DAT(unsigned char* buf);
};
