#include <math.h>
#include <ArxTypeTraits.h>

#include "../Unit.h"

struct Degrees {};
struct Radians {};

template <typename T>
class Angle : public Unit {
    
    public:
        Angle (float value = 0.0f)
            : _value(value) {
                wrap();
            }
        
        // Turns a value into an angle of n magnitude
        static Angle<T> of(float value) {
            return Angle<T>(value);
        }

        // Return the magnitude regardless of unit type
        float getValue() const {
            return _value;
        }

        // Times the angle by 180/π to get Degrees
        float toDegrees() const {
            if constexpr (std::is_same<T, Radians>::value) {
                return _value * (180.0f / M_PI);
            }
            return _value;
        }

        // Times the angle by π/180 to get Eadians
        float toRadians() const {
            if constexpr (std::is_same<T, Degrees>::value) {
                return _value * (M_PI / 180.0f);
            }
            return _value;
        }

    private:
        float _value;

        void wrap() {
            if constexpr (std::is_same<T, Degrees>::value) {
                // Wrap degrees between 0 and 360
                _value = fmod(_value, 360.0f);
                if (_value < 0.0f) {
                    _value += 360.0f;  // Ensure it is between 0 and 360
                }
            } else if constexpr (std::is_same<T, Degrees>::value) {
                // Wrap radians between -π and π
                _value = fmod(_value, 2 * M_PI);
                if (_value < -M_PI) {
                    _value += 2 * M_PI;  // Ensure it's between -π and π
                } else if (_value > M_PI) {
                    _value -= 2 * M_PI;  // Ensure it's between -π and π
                }
            }
        }
};