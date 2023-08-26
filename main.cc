#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <random>
#include <thread>
#include <vector>

#include "lib/curves.h"

std::recursive_mutex muteX;

void SumInRange(std::vector<fig::Circle> *vctr, int start, int end,
                int *result) noexcept {
  int answ = 0;
  for (auto it = vctr->begin() + start; it != vctr->begin() + end; ++it) {
    answ += it->GetRadius();
  }
  muteX.lock();
  *result += answ;
  muteX.unlock();
}

int main() {
  std::vector<fig::Helix *> figVctr;

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
    float step = static_cast<float>(c) / 1000;
    int type = gen_type();
    switch (type) {
    case 0: {
      fig::Circle a(horisontalSemiAxis);
      figVctr.push_back(&a);
      break;
    }
    case 1: {
      fig::Ellipse a(horisontalSemiAxis, verticalSemiAxis);
      figVctr.push_back(&a);
      break;
    }
    case 2:
    default: {
      fig::Helix a(horisontalSemiAxis, verticalSemiAxis, step);
      figVctr.push_back(&a);
      break;
    }
    }
  }

  std::cout << "POINTS ACCORDING TO t" << std::endl;
  for (auto &fg : figVctr) {
    std::cout << fg->GetPoint(M_PI / 4);
  }

  std::cout << "DIFF DIRECTION POINTS (assuming start at 0)" << std::endl;
  for (auto &fg : figVctr) {
    std::cout << fg->GetVectorPoint(M_PI / 4);
  }

  std::vector<fig::Circle> circleVctr;
  for (auto &fig : figVctr) {
    if (dynamic_cast<fig::Circle *>(fig)) {
      circleVctr.push_back(*(dynamic_cast<fig::Circle *>(fig)));
    }
  }
  std::sort(circleVctr.begin(), circleVctr.end());

  std::vector<std::thread> threadVector;
  int answ = 0;
#ifdef NUM_OF_THREADS
  int step = circleVctr.size() / NUM_OF_THREADS;
  for (int i = 0; i < NUM_OF_THREADS; ++i) {
    threadVector.push_back(
        std::thread(SumInRange, &circleVctr, step * i, step * (i + 1), &answ));
  }
  for (auto &threaD : threadVector) {
    threaD.join();
  }
#endif

#ifndef NUM_OF_THREADS
  for (auto &circlE : circleVctr) {
    answ += circlE.GetRadius();
  }
#endif

  std::cout << "sum of radii: " << answ << std::endl;
}