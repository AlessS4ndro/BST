#include "clases.h"

template <class T>
bool BST<T>::find(T data,Node<T> **&marca)
{
  marca=&raiz;

  while(*marca){
    if((*marca)->data==data)return true;
    if((*marca)->data<data)
      marca=&((*marca)->right);
    else
      marca=&((*marca)->left);
  }
  return false;

}

template<class T>
void BST<T>::add(T data)
{
  Node<T> **marca;

  if(!raiz)raiz=new Node<T>(data);
  if(!find(data,marca)){
    *marca=new Node<T>(data);;
  }

}

template<class T>
void BST<T>::view(Node<T> *r)
{
  if(!r)return;
  cout<<r->data<<endl;
  view(r->left);
  view(r->right);
/*  if(!r)return;
  if(!(r->left) && !(r->right)){
    cout<<r->data<<endl;
    return ;
  }
  view(r->left);
  view(r->right);
  cout<<r->data<<endl;
*/
}


template<class T>
long BST<T>::number_nodes(Node<T> *r)
{
  if(!r)return 0;
  return number_nodes(r->left) + number_nodes(r->right) + 1;
}

template<class T>
Node<T> * BST<T>::supreme()
{
  Node<T> *p=raiz;

  while(p){
    if(!(p->right))
      break;
    p=p->right;
  }

  return p;
}


template<class T>
Node<T> * BST<T>::father(T data)
{
  Node<T> *walking=raiz;
  Node<T> **p;

  if(find(data,p)){
    while(walking){
      if(data<walking->data){       /////   consultamos y
        if(data==walking->left->data)   ////  recorremos hacia
          return walking;             ///// la izquierda
        walking=walking->left;
      }
      else{
        if(data==walking->right->data)    ///// consultamos
          return walking;                   /// y recorremos
        walking=walking->right;       //////  hacia la derecha
      }
    }
  }
  return NULL;
}

template<class T>
Node<T>* BST<T>::brother(T data)
{
  Node<T> *padre=father(data);
  if(data<padre->data)              ///// si el hijo es menor que el padre
    return padre->right;            ////  retorna el hijo derecho
  else
    return padre->left;             ///// y viceversa
}

template<class T>
Node<T>* BST<T>::uncle(T data)
{
  Node<T> *padre=father(data);
  if(padre)
    return brother(padre->data);
  return NULL;
}

template<class T>
T BST<T>::mayor()
{
  Node<T> *retornable=supreme();
  if(retornable)
    return retornable->data;
  //else{
    // retornar un valor nulo del
    // tipo T que uno debe de implementar
  //}
}

template<class T>
T BST<T>::padre(T data)
{
  Node<T> *retornable=father(data);
  if(retornable)
    return retornable->data;
  //else{
    // retornar un valor nulo del
    // tipo T que uno debe de implementar
  //}
}

template<class T>
T BST<T>::hermano(T data)
{
  Node<T> *retornable=brother(data);
  if(retornable)
    return retornable->data;
  //else{
    // retornar un valor nulo del
    // tipo T que uno debe de implementar
  //}
}

template<class T>
T BST<T>::tio(T data)
{
  Node<T> *retornable =uncle(data);
  if(retornable)
    return retornable->data;
  //else{
    // retornar un valor nulo del
    // tipo T que uno debe de implementar
  //}
}
