/*
Team : B-CC Model Rocketry Team 2
Contributors : Aidan Somerville
Comments:
This class defines the PIDProfile, a class that contains all necessary values for PID correction.
*/

#pragma once

class PIDProfile {
    public:
        PIDProfile();
        PIDProfile(float kP, float kI, float kD);
        //TBI
        PIDProfile(float kP, float kI, float kD, float maxInput, float minInput);

        float getkP();
        float getkI();
        float getkD();
    private:
        float m_kP = 0.0f;
        float m_kI = 0.0f;
        float m_kD = 0.0f;
        float m_maxInput;
        float m_minInput;
};