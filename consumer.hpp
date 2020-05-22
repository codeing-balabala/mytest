#include <iostream>

class Consumer {
public:
  Consumer() {
    std::cout << "construct a Consumer!" << std::endl;
  }
  ~Consumer() {
  }
};