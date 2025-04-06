#pragma once

#include "Arduino.h"

#include "Servo.h"
#include "HardwareDevices.h"


class TVCIO {
    public:
        TVCIO(HardwareDevices& hardware);
        void setup();
        void setYawMS(int power);
        void setPitchMS(int power);
        void setYaw(int angle);
        void setPitch(int angle);
    private:
        HardwareDevices& hardware;
        Servo yawServo;
        Servo pitchServo;
};