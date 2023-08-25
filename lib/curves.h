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

class Figure {
  // in radians
  virtual Point GetPoint(float angle) const = 0;
  virtual float GetArea() const = 0;
};

class RoundFig : public Figure {
public:
  RoundFig(int xSemi, int ySemi);

  float GetArea() const;
  Point GetPoint(float angle) const;

private:
  int x_semiaxis_;
  int y_semiaxis_;
};

} // namespace fig
