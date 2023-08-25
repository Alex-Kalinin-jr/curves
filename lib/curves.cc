#include "curves.h"

#include <cstddef>


namespace fig {
  
Figure::Figure(int xSemi, int ySemi, int x, int y, int z)
    : x_semiaxis_(xSemi),
      y_semiaxis_(ySemi),
      cntr_x_point_(x),
      cntr_y_point_(y),
      cntr_z_point_(z) {}

}

