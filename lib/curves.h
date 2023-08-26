#include <cmath>
#include <cstddef>
#include <iostream>

#define EPS 1e-6

namespace fig {

struct Point {
  Point(float x, float y, float z) : x(x), y(y), z(z) {}
  float x;
  float y;
  float z;
  bool operator==(const Point &other) const;
  bool operator!=(const Point &other) const { return !(*this == other); }
  friend std::ostream &operator<<(std::ostream &os, const fig::Point &point);
};
//****************************************************************************
//****************************************************************************
class Figure {
  virtual Point GetPoint(float angle) const = 0;       // angle is in radians
  virtual Point GetVectorPoint(float angle) const = 0; // angle is in radians
};
//****************************************************************************
//****************************************************************************
class Helix : public Figure {
public:
  explicit Helix(float xSemi, float ySemi, float step);
  Point GetPoint(float angle) const;
  Point GetVectorPoint(float angle) const;

protected:
  float x_semiaxis_;
  float y_semiaxis_;
  float z_step_;

  inline float GetParameter(float angle) const {
    return atan2(x_semiaxis_ * sinf(angle), y_semiaxis_ * cosf(angle));
  }
};

class Ellipse : public Helix {
public:
  Ellipse(float xSemi, float ySemi) : Helix(xSemi, ySemi, 0) {}

  Point GetPoint(float angle) const { return Helix::GetPoint(angle); };
  Point GetVectorPoint(float angle) const {
    return Helix::GetVectorPoint(angle);
  }
};
//****************************************************************************
//****************************************************************************
class Circle : public Ellipse {
public:
  Circle(float rad) : Ellipse(rad, rad) {}
  bool operator<(const Circle &other) {
    return (x_semiaxis_ < other.x_semiaxis_);
  }
  bool operator>(const Circle &other) {
    return (x_semiaxis_ > other.x_semiaxis_);
  }
  bool operator!=(const Circle &other) {
    return ((*this < other) || (*this > other));
  }
  bool operator==(const Circle &other) { return !(*this != other); }
  bool operator<=(const Circle &other) {
    return (*this == other || *this < other);
  }
  bool operator>=(const Circle &other) {
    return (*this == other || *this > other);
  }

  inline float GetRadius() { return x_semiaxis_; }
  Point GetPoint(float angle) const { return Ellipse::GetPoint(angle); }
  Point GetVectorPoint(float angle) const {
    return Ellipse::GetVectorPoint(angle);
  }
};

} // namespace fig
