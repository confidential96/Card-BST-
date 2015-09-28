#ifndef BST_H__
#define BST_H__

#include <iostream>



//The Binary Search tree for Cards
template <class T>
class BST {
 public:
  
  // Default constructor
  BST() { root = NULL; }
  
  //Copy constructor (deep copy)

  BST( const BST &o ) { root = copyTree(o.root); }
  
  //Assignment (deep copy)
  BST& operator=(const BST &o) { 
    deleteTree(root); 
    root = copyTree(o.root); 
    return *this;
  }

  //stream output operator
  friend std::ostream& operator<< (std::ostream& strm, const BST& tree) {
    tree.showTree(tree.root, strm);
    return strm;
  }

  
  ~BST() { deleteTree(root); }

    
  void insert(const T& c){ 
    if(!root) 
      root = new Node(c);
    else
      insert(root, c); 
  }


  T *find(const T& c) const { return find(root, c); }
  int getSize() { return getSize(root); }
  

 private:

  class Node {
  public:
    Node(const T &c): value(c) 
    { 
      leftChild = rightChild = NULL; 
    }

    // These are the attributes of a BST::Node you can use.
    T value;
    Node *leftChild;
    Node *rightChild;
  };


  Node* root;

  // Given

  void showTree(const Node *n, std::ostream &os) const;
  Node* copyTree(const Node *n);
  T* find(Node *n, const T& c) const;

  // Methods from last week
  void deleteTree(Node *n);
  void insert(Node *n, const T& c);
  int getSize(const Node *n) const;
  
};
#include "BST.cpp"

#endif