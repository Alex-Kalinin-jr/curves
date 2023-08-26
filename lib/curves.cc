#include "curves.h"

#include <cmath>
#include <cstddef>
#include <exception>
#include <iostream>

namespace fig {

std::ostream &operator<<(std::ostream &os, const fig::Point &point) {
  os << point.x << "; " << point.y << "; " << point.z << ";" << std::endl;
  return os;
}

bool Point::operator==(const Point &other) const {
  float dx = x - other.x;
  float dy = y - other.y;
  float dz = z - other.z;
  return fabs(dx) < EPS && fabs(dy) < EPS && fabs(dz) < EPS;
}
// ******************************************************************************
// ******************************************************************************

Helix::Helix(float xSemi, float ySemi, float step) {
  if (xSemi <= 0 || ySemi <= 0 || step < 0) {
    throw "Ellipse:: invalid constructor";
  }
  semi_x_ = xSemi;
  semi_y_ = ySemi;
  step_z_ = step / (2 * M_PI);
}

Point Helix::GetPoint(float angle) const {
  float newAngle = GetParameter(angle);
  float x = semi_x_ * cosf(newAngle);
  float y = semi_y_ * sinf(newAngle);
  float z = step_z_ * angle;
  return Point(x, y, z);
}

Point Helix::GetVectorPoint(float angle) const {
  float newAngle = GetParameter(angle);
  float x = semi_x_ * (-sinf(newAngle));
  float y = semi_y_ * cosf(newAngle);
  float z = step_z_;
  return Point(x, y, z);
}
// ******************************************************************************
// ******************************************************************************

} // namespace fig
