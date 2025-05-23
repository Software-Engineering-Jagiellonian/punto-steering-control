#pragma once
class StatusInterface {
   public:
	virtual ~StatusInterface() = default;
	virtual void init() = 0;
	virtual int isWorking() = 0;
};