#include <cstddef>

namespace fig {

class Figure {
 public:
  Figure(int xSemi, int ySemi, int x = 0, int y = 0, int z = 0);

 private:
  int x_semiaxis_;
  int y_semiaxis_;
  int cntr_x_point_;
  int cntr_y_point_;
  int cntr_z_point_;
};

}  // namespace fig
