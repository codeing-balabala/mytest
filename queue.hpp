#include <iostream>
#include <vector>

namespace queue {
enum STATE {
  OK = 0,
  EMPTY = 1,
  ERROR = 2,
};

std::vector<std::string> STATE_STRING{"OK", "EMPTY", "ERROR"};

// template <typename T>
class Queue {
public:
  // Queue() {
  //   std::cout << "construct a empty Queue!" << std::endl;
  // }
  Queue(size_t size) : buff_size_{size} {
    buffer = new int[buff_size_];
    std::cout << "construct a Queue!" << std::endl;
  }

  STATE push(int value) {
    std::cout << "push:" << value << std::endl;

    buffer[index_w_] = value;
    buff_num_++;
    update_index_(index_w_);

    return OK;
  }

  STATE pop(int &value) {
    if (0 == buff_num_) {
      return EMPTY;
    }
    value = buffer[index_r_];
    buff_num_--;
    update_index_(index_r_);
    std::cout << "pop:" << value << std::endl;
    return OK;
  }

  void printf_status() {
    std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;

    std::cout << "buff_size_:" << buff_size_ << ", buff_num_:" << buff_num_ << std::endl;
    std::cout << "index_w_:" << index_w_ << ", index_r_:" << index_r_ << std::endl;
    // std::cout << "temp1:" << temp1 << ", temp2:" << temp2 << std::endl;

    std::cout << "!!!!!!!!!!!!!!!!!" << std::endl;
  }

  //   STATE write(T *value, size_t num) {
  //   }

  ~Queue() {
    std::cout << "destruct a Queue!" << std::endl;
  }

private:
  inline void update_index_(size_t &index) {
    index++;
    if (index == buff_size_) {
      index = 0;
    }
  }

private:
  //   T *buffer;
  int *buffer;
  size_t index_w_ = 0;
  size_t index_r_ = 0;
  size_t buff_size_ = 0;
  size_t buff_num_ = 0;
  size_t temp1;
  size_t temp2;
};
} // namespace queue