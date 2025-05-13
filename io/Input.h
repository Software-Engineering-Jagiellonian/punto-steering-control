#pragma once
#include "../data/Data.h"
#include "../data/InputType.h"
#include "StatusInterface.h"

class Input : public StatusInterface {
   public:
	virtual Data* get() const =0;
	virtual inputType type() const =0;
};