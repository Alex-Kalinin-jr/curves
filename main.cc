#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <random>
#include <typeinfo>
#include <vector>

#include "lib/curves.h"

int main() {
  std::vector<fig::Helix> figVctr;

  std::random_device rd;
  std::default_random_engine engine(rd());
  auto gen_param =
      std::bind(std::uniform_int_distribution<>(50, 99999), engine);
  auto gen_type = std::bind(std::uniform_int_distribution<>(0, 3), engine);

  int count = gen_param();
  while (--count != 0) {
    int a = gen_param();
    int b = gen_param();
    int c = gen_param();
    float horisontalSemiAxis = static_cast<float>(a) / 1000;
    float verticalSemiAxis = static_cast<float>(b) / 1000;
    float step = static_cast<float>(b) / 1000;
    int type = gen_type();
    switch (type) {
    case 0: {
      fig::Circle a(horisontalSemiAxis);
      figVctr.push_back(a);
      break;
    }
    case 1: {
      fig::Ellipse a(horisontalSemiAxis, verticalSemiAxis);
      figVctr.push_back(a);
      break;
    }
    case 2:
    default: {
      fig::Helix a(horisontalSemiAxis, verticalSemiAxis, step);
      figVctr.push_back(a);
      break;
    }
    }
  }

  std::cout << "HOLY POINTS" << std::endl;
  for (auto &fg : figVctr) {
    std::cout << fg.GetPoint(M_PI / 4);
  }

  std::cout << "HOLY DIFF DIRECTION POINTS" << std::endl;
  for (auto &fg : figVctr) {
    std::cout << fg.GetVectorPoint(M_PI / 4);
  }

  fig::Circle temp(1);
  const std::type_info &neededType = typeid(temp);

  std::vector<std::shared_ptr<fig::Circle>> circleVctr;
  std::for_each(figVctr.begin(), figVctr.end(),
                [&neededType, &circleVctr](fig::Helix &fig) mutable {
                  if (typeid(fig) == neededType) {
                    // std::shared_ptr<fig::Circle> ptr { std::make_shared<fig::Circle>(fig) };
                    // circleVctr.push_back(ptr);
                    std::cout<<"found";
                  }
                });
}