#include <iostream>
using namespace std;


template <typename T>
void BST<T>::showTree(const BST<T>::Node *n, std::ostream &os) const {
  // This is in order traversal
  if(!n)
    return;
  else {
    if(n->leftChild)
      showTree(n->leftChild, os);

    cout << n->value << endl;

    if(n->rightChild)
      showTree(n->rightChild, os);
  }
}
template <typename T>
typename BST<T>::Node* BST<T>::copyTree(const BST<T>::Node *n) {
  if(!n)
    return NULL;
  else {
    BST::Node * mine = new BST::Node(n->card);
    mine->leftChild = copyTree(n->leftChild);
    mine->rightChild = copyTree(n->rightChild);
    return mine;
  }
}
template <typename T>
T* BST<T>::find(BST<T>::Node *n, const T& c) const {
  if(!n)
    return NULL;

  if(c == n->value)
    return &(n->value);
  else if(c < n->value)
    return find(n->leftChild, c);
  else
    return find(n->rightChild, c);
}



template <typename T>
void BST<T>::deleteTree(BST<T>::Node *n) {
  if (n == NULL) return;
  deleteTree(n->leftChild);
  deleteTree(n->rightChild);

  delete n;

}
template <typename T>
void BST<T>::insert(BST<T>::Node *n, const T &c) {
  if (n == NULL)
    return;

  if (c < n->value) {
    insert(n->leftChild, c);

    if (n->leftChild == NULL) {
      Node *tmp = new Node(c);
      n->leftChild = tmp;
    }
  }
  else {
    insert(n->rightChild, c);

    if (n->rightChild == NULL) {
      Node *tmp = new Node(c);
      n->rightChild = tmp;
    }
  }
}
template <typename T>
int BST<T>::getSize(const BST<T>::Node *n) const {
  if (n == NULL)
    return 0;
  else
    return(1 + getSize(n->leftChild) + getSize(n->rightChild));
}