#include <iostream>

template <typename T>
class Single_List {
 public:
  Single_List() : number{0}, header{nullptr} {
    std::cout << "construct Single_List." << std::endl;
  }

  Single_List(const T& v) {
    std::cout << "construct Single_List with value." << std::endl;
    header = new List_Node(v);
    number = 1;
  }

 public:
  struct List_Node {
    List_Node(const T& v) : value{v}, next{nullptr} {
      std::cout << "construct List_Node." << std::endl;
    }

    T value;
    List_Node* next;
  };

 public:
  void insert(const T& v) {
    if (isEmpty()) {
      header = new List_Node(v);
    } else {
      List_Node* node = header;
      while (node->next != nullptr) {
        node = node->next;
      }
      node->next = new List_Node(v);
    }

    number++;
  }

  bool remove(const T& v) {
    if (header->value == v) {
      List_Node* temp = header;
      header = temp->next;
      delete temp;
      number--;
      return true;
    }

    List_Node* node = header;
    while (node->next != nullptr) {
      if (node->next->value == v) {
        List_Node* temp = node->next;
        node->next = temp->next;
        delete temp;
        number--;
        return true;
      }
      node = node->next;
    }

    std::cout << "not found " << v << std::endl;
    return false;
  }

  bool remove(const List_Node* n) {
    if (header == n) {
      List_Node* temp = header;
      header = header->next;
      delete temp;
      number--;
      return true;
    }

    List_Node* node = header;
    while (node->next != nullptr) {
      if (node->next == n) {
        std::cout << "found " << static_cast<const void*>(n) << std::endl;
        List_Node* temp = node->next;
        node->next = temp->next;
        delete temp;
        number--;
        return true;
      }
      node = node->next;
    }

    std::cout << "not found " << static_cast<const void*>(n) << std::endl;
    return false;
  }

  List_Node* find(const T& v) {
    if (header->value == v) {
      return header;
    }

    List_Node* node = header;
    while (node->next != nullptr) {
      node = node->next;
      if (node->value == v) {
        return node;
      }
    }

    std::cout << "not found " << v << std::endl;
    return nullptr;
  }

  bool isEmpty(void) { return number == 0; }

  int size(void) { return number; }

  void show() {
    List_Node* node = header;
    std::cout << "size:" << number << std::endl;
    std::cout << "value:" << node->value << std::endl;
    while (node->next != nullptr) {
      node = node->next;
      std::cout << "value:" << node->value << std::endl;
    }
  }

  void earse(void) {
    List_Node* node = header;
    List_Node* node_del = header;
    while (node != nullptr) {
      node_del = node;
      node = node->next;
      delete node_del;
    }
  }

 private:
  List_Node* header;
  int number;

 public:
  ~Single_List() {
    std::cout << "destruct Single_List." << std::endl;
    earse();
  }
};