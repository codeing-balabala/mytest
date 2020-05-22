#include <iostream>

class Producer {
public:
  Producer() {
    std::cout << "construct a Producer!" << std::endl;
  }
  ~Producer() {
    std::cout << "disstruct a Producer!" << std::endl;
  }
};