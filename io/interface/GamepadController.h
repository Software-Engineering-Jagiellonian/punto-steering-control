#ifndef GAMEPAD_CONTROLLER_H
#define GAMEPAD_CONTROLLER_H


class GamepadController {
private:
    unsigned char PS2buf[10]; 

    public:
        GamepadController();
        void PS2_RWByte(unsigned char dat);
        unsigned char Get_PS22DAT(unsigned char* buf);
    };

#endif // GAMEPAD_CONTROLLER_H
