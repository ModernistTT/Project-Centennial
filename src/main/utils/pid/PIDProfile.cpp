/*
Team : B-CC Model Rocketry Team 2
Contributors : Aidan Somerville
Comments:
This class defines the PIDProfile, a class that contains all necessary values for PID correction.
*/

#include "PIDProfile.h"

PIDProfile::PIDProfile(float kP, float kI, float kD)
    : m_kP(kP), m_kI(kI), m_kD(kD), m_maxInput(0.0f), m_minInput(0.0f) {}

PIDProfile::PIDProfile(float kP, float kI, float kD, float maxInput, float minInput)
    : m_kP(kP), m_kI(kI), m_kD(kD), m_maxInput(maxInput), m_minInput(minInput) {}

float PIDProfile::getkP() {
    return m_kP;
}

float PIDProfile::getkI() {
    return m_kI;
}

float PIDProfile::getkD() {
    return m_kD;
}