#include <cmath>
#include <cstddef>

namespace fig {

struct Point {
  Point(float x, float y, float z) : x(x), y(y), z(z) {}
  bool operator==(const Point &other) const;
  float x;
  float y;
  float z;
};
// ******************************************************************************
// ******************************************************************************
class Figure {
  virtual float GetArea() const = 0;
  virtual Point GetPoint(float angle) const = 0;       // angle is in radians
  virtual Point GetVectorPoint(float angle) const = 0; // angle is in radians
};
// ******************************************************************************
// ******************************************************************************
class Ellipse : public Figure {
public:
  Ellipse(float xSemi, float ySemi);

  float GetArea() const;
  Point GetPoint(float angle) const;
  Point GetVectorPoint(float angle) const;

private:
  float x_semiaxis_;
  float y_semiaxis_;

  inline float GetParameter(float angle) const {
    return atan2(x_semiaxis_ * sinf(angle), y_semiaxis_ * cosf(angle));
  }
};
// ******************************************************************************
// ******************************************************************************
class Circle : public Ellipse {
public:
  Circle(float rad) : Ellipse(rad, rad) {}
  Point GetPoint(float angle) const { return Ellipse::GetPoint(angle); }
  Point GetVectorPoint(float angle) const {
    return Ellipse::GetVectorPoint(angle);
  }
};

// ******************************************************************************
// ******************************************************************************
class Helix : public Ellipse {
public:
  explicit Helix(float rad, float step) : Ellipse(rad, rad) {
    z_step_ = step / (2 * M_PI);
  }
  Point GetPoint(float angle) const;
  Point GetVectorPoint(float angle) const;
private:
  float z_step_;
};

} // namespace fig
