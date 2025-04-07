class Unit {
public:
    virtual float getValue() const = 0;
    virtual void of(float value) = 0;
    virtual ~Unit() = default;

    template <typename T>
    static T of(float value) {
        return T(value);
    }
};