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
Node<T> * BST<T>::mayor()
{
  Node<T> *p=raiz;

  while(p){
    if(!(p->right))
      break;
    p=p->left;
  }

  return p;
}

template<class T>
Node<T> * BST<T>::father(T data)
{
  Node<T> *p=raiz;
  while(!p){
    if(data<*p){
      if(data->left==data)
        return p;
    }

  }

}
