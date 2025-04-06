class Unit {
public:
    virtual float getValue() const = 0;
    virtual void setValue(float value) = 0;
    virtual ~Unit() = default;
};