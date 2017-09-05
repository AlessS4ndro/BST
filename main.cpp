#include "clases.h"
#include "metodos.h"
#include <fstream>
#include <math.h>

int main(int argc,char *argv[])
{
  BST<int> arbol;

  int as[]={44,22,88,11,27,66,1,1,12,23,27,57,77,78};

  for(int i=0;i<14;i++)
    arbol.add(as[i]);

  arbol.print();
  cout<<"el numero de nodos es "<<arbol.contar()<<endl;




}
