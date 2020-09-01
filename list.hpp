#include <iostream>

template <typename T>
struct List_Node {
  List_Node(const T& v) : value(v), next(nullptr) {
    std::cout << "construct List_Node." << std::endl;
  }

  void insert(const T& v) {
    List_Node* node = this;
    while (node->next != nullptr) {
      node = node->next;
    }
    node->next = new List_Node(v);
  }

  List_Node* find(const T& v) {
    List_Node* node = this;
    while (node->next != nullptr) {
      if (node->next->value == v) {
        return node->next;
      }
      node = node->next;
    }
    return nullptr;
  }

  bool remove(const T& v) {
    List_Node* node = this;
    while (node->next != nullptr) {
      if (node->next->value == v) {
        List_Node* temp = node->next;
        node->next = node->next->next;
        delete temp;
        return true;
      }
      node = node->next;
    }
    return false;
  }

  bool remove(const List_Node* n) {
    List_Node* node = this;
    while (node->next != nullptr) {
      if (node->next->value == n->value) {
        List_Node* temp = node->next;
        node->next = node->next->next;
        delete temp;
        return true;
      }
      node = node->next;
    }
    return false;
  }

  T value;
  List_Node* next;
};

template <typename T>
class Single_List {
 public:
  Single_List() {
    std::cout << "construct Single_List." << std::endl;
    header = nullptr;
    number = 0;
  }

  Single_List(const T& v) {
    std::cout << "construct Single_List with value." << std::endl;

    header = new List_Node<T>(v);
    header->insert(v);
    number = 1;
  }

  void insert(const T& value) {
    if (isEmpty()) {
      header = new List_Node<T>(value);
    } else {
      header->insert(value);
    }
    number++;
  }

  void remove(const T& value) {
    if (header->remove(value)) {
      number--;
    } else {
      std::cout << "not found " << value << std::endl;
    }
  }

  void remove(const List_Node<T>* node) {
    if (header->remove(node)) {
      number--;
    }
  }

  List_Node<T>* find(const T& value) {
    List_Node<T>* node = header->find(value);
    return node;
  }

  bool isEmpty(void) { return number == 0; }

  int size(void) { return number; }

  void print() {
    List_Node<T>* node = header;
    while (node->next != nullptr) {
      node = node->next;
      std::cout << "value:" << node->value << std::endl;
    }
  }

  void earse(void) {
    List_Node<T>* node = header;
    List_Node<T>* node_del = header;
    while (node != nullptr) {
      node_del = node;
      node = node->next;
      delete node_del;
    }
  }

 private:
  List_Node<T>* header;
  int number;

 public:
  ~Single_List() {
    std::cout << "destruct Single_List." << std::endl;
    earse();
  }
};