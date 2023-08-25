#include "curves.h"

#include <cmath>
#include <cstddef>
#include <exception>

#define EPS 1e-6

namespace fig {

bool Point::operator==(const Point &other) const {
  float dx = x - other.x;
  float dy = y - other.y;
  float dz = z - other.z;
  return fabs(dx) < EPS && fabs(dy) < EPS && fabs(dz) < EPS;
}
// ******************************************************************************
// ******************************************************************************
Ellipse::Ellipse(float xSemi, float ySemi) {
  if (xSemi <= 0 || ySemi <= 0) {
    throw "Ellipse:: invalid constructor";
  }
  x_semiaxis_ = xSemi;
  y_semiaxis_ = ySemi;
}

float Ellipse::GetArea() const { return M_PI * x_semiaxis_ * y_semiaxis_; }

Point Ellipse::GetPoint(float angle) const {
  float newAngle = GetParameter(angle);
  float x = x_semiaxis_ * cosf(newAngle);
  float y = y_semiaxis_ * sinf(newAngle);
  return Point(x, y, 0);
}

Point Ellipse::GetVectorPoint(float angle) const {
  float newAngle = GetParameter(angle);
  float x = x_semiaxis_ * (-sinf(newAngle));
  float y = y_semiaxis_ * cosf(newAngle);
  float z = 0;
  return Point(x, y, z);
}
// ******************************************************************************
// ******************************************************************************

Point Helix::GetPoint(float angle) const { 
  Point buffPoint(Ellipse::GetPoint(angle)); 
  buffPoint.z = z_step_ * angle;
  return buffPoint;
}

Point Helix::GetVectorPoint(float angle) const {
  Point buffPoint(Ellipse::GetVectorPoint(angle));
  buffPoint.z = 0;
  return buffPoint;
}





} // namespace fig
