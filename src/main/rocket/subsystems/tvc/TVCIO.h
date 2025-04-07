#include "Arduino.h"

#include "Servo.h"
#include "../constants/HardwareDevices.h"
#include "../../../utils/units/angle/Angle.h"

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