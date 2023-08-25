#include <functional>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::random_device rd;
  std::default_random_engine engine(rd());
  auto gen_param =
      std::bind(std::uniform_int_distribution<>(50, 99999), engine);
  auto gen_type = std::bind(std::uniform_int_distribution<>(0, 3), engine);
  std::vector

      int count = gen_param();
  int a = gen_param();
  int b = gen_param();
  int c = gen_param();
  float horisontalSemiAxis = static_cast<float>(a) / 1000;
  float verticalSemiAxis = static_cast<float>(b) / 1000;
  float step = static_cast<float>(b) / 1000;
  int type = gen_type();

  while (--count != 0) {
  }
}