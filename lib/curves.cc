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

RoundFig::RoundFig(int xSemi, int ySemi) {
  if (xSemi <= 0 || ySemi <= 0) {
    throw "RoundFig:: invalid constructor";
  }
  x_semiaxis_ = xSemi;
  y_semiaxis_ = ySemi;
}

float RoundFig::GetArea() const { return M_PI * x_semiaxis_ * y_semiaxis_; }

Point RoundFig::GetPoint(float angle) const {
  float newAngle = atan2(x_semiaxis_ * sinf(angle), y_semiaxis_ * cosf(angle));
  float x = x_semiaxis_ * cosf(newAngle);
  float y = y_semiaxis_ * sinf(newAngle);
  return Point(x, y, 0);
}

} // namespace fig
