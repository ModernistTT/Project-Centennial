/*
Team : B-CC Model Rocketry Team 2
Contributors : Aidan Somerville
Comments:
This class provides PID (Proportional, Integral, Derivative) control for the rocket Thrust Vectoring System (TVCS.)
*/

#include "PID.h"

PID::PID(PIDProfile profile) : _profile(profile) {}

float PID::calculate(float setpoint, float measured) {
    currentTime = micros();
    deltaTime = (currentTime - lastTime) / 1000000.0f;

    // Calculate proportional
    float error = setpoint - measured;

    // Calculate integral
    integral += error * deltaTime;

    // Calculate derivative
    float derivative = (error - lastError) / deltaTime;

    lastTime = currentTime;
    lastError = error;

    return _profile.getkP() * error + _profile.getkI() * integral + _profile.getkD() * derivative;
}
