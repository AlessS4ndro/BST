#ifndef __CLASES_H__
#define __CLASES_H__

#include <iostream>

using namespace std;

template<class T>
struct Node
{
  T data;
  Node<T> *left;
  Node<T> *right;
  Node(){}
  Node(T d):data(d),left(NULL),right(NULL){}
};

template<class T>
class BST
{
  Node<T> *raiz;
  bool find(T ,Node<T> **&);
  void view(Node<T> *);
  long number_nodes(Node<T> *);
  Node<T> * supreme();
  Node<T> * father(T);
  Node<T> * brother(T);
  Node<T> * uncle(T);

public:

  BST():raiz(NULL){}
  void add(T );
  void print(){view(raiz);}
  long contar(){return number_nodes(raiz);}
  T mayor();
  T padre(T);
  T hermano(T);
  T tio(T);

};



#endif
