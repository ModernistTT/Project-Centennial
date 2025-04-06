#include "TVCIO.h"

TVCIO::TVCIO(HardwareDevices& hardware)
    : hardware(hardware) {}

void TVCIO::setup() {
    yawServo.attach(hardware.telServoYawPort);
    pitchServo.attach(hardware.telServoPitchPort);
}

void TVCIO::setYawMS(int power) {
    yawServo.writeMicroseconds(constrain(power, 1000, 2000));
}

void TVCIO::setPitchMS(int power) {
    pitchServo.writeMicroseconds(constrain(power, 1000, 2000));
}

// Write is in DEGREES by default
void TVCIO::setYaw(int angle) {
    yawServo.write(constrain(angle, 0, 180));
}

// Write is in DEGREES by default
void TVCIO::setPitch(int angle) {
    pitchServo.write(constrain(angle, 0, 180));
}