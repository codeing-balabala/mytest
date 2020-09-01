#include <iostream>
#include <vector>

// template<T>

class Tree {
 public:
  Tree() {
    std::cout << "construct Tree Tree()" << std::endl;
    tree.left = nullptr;
    tree.rigth = nullptr;
    tree.value = 0;
    last_node = &tree;
  }

  void print_tree() {}

 private:
  struct TreeNode {
    TreeNode *left;
    TreeNode *rigth;
    int value;
  };
  TreeNode tree, *last_node;

 private:
  void add(int value) {
    TreeNode *node = new TreeNode;
    node->value = value;
  }
  void remove() {}
  int number() {}
  int number_left() {}
  int number_right() {}
  //   TreeNode *get_last_node() {}

 public:
  ~Tree() { std::cout << "destruct Tree" << std::endl; }
};