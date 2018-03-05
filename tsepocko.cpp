#include<fstream>
#include<iostream>
using namespace std;



struct Node
{ /*string surname;
  string name;
  int year;
  int level;
  string prof;
  Node *next;*/...
};
 void addF(string fname,Node* &head,Node*last)
 {
     ifstream fin(fname);
     while(!fin.eof())
     { 
         Node*person=new Node;
         fin>>person->surname>>person->name>>person->year>>person->level>>person->prof;
         person->=next=NULL;
         last->next=person;
         last=last->next;
         
     }fin.close();
     
 }
 int main()
 {
     Node*head,*last;
     last=head=NULL;
     string fname ...;
     addF(fname,head,last);
     return 0;
 }
 
