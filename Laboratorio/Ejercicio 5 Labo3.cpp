#include <cstdlib>
#include <iostream>
using namespace std;
struct Node{
  int dato;
  Node * sig;
};

void insert(Node * &list,int d){
  Node * newNode=new Node();
  newNode->dato=d;
  newNode->sig=0;

  if(list==0){

    list=newNode;
    return;

  }

  newNode->sig=list;
  list=newNode;
}

void print(Node * list){
  Node * temp=list;

  while(temp!=0){

    cout<< temp->dato<<endl;
    temp=temp->sig;
  }
}

Node * reverse(Node * list){
{
  if(list->sig!=0)
  return list;
}
   reverse(list->sig);

    (list->sig)->sig=list;
    list->sig=0;
 
}

int main(){
  Node * list = 0;

  insert(list,3);
  insert(list,2);
  insert(list,1);
  list = reverse(list); 

  print(list);
  
	system("pause");
	return 0;
}
