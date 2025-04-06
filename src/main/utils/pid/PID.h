/*
Team : B-CC Model Rocketry Team 2
Contributors : Aidan Somerville
Comments:
This class provides PID (Proportional, Integral, Derivative) control for the rocket Thrust Vectoring System (TVCS.)
*/

#pragma once

#include "PIDProfile.h"

class PID {
public:
    PID(PIDProfile profile);

    float calculate(float setpoint, float measured);
private:
    PIDProfile _profile;
    float integral = 0.0f;
    float deltaTime = 0.0f;
    float lastError = 0.0f;
    float lastTime = 0.0f;
    float currentTime = 0.0f;
};