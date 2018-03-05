#include <iostream>
#include <cstdlib>
using namespace std;
 
// define default capacity of stack
#define SIZE 10
 
// Class for stack
template <class X>
class stack
{
	X *arr;
	int top;
	int capacity;
 
public:
	stack(int size = SIZE);	// constructor
 
	void push(X);
	X pop();
	X peek();
 
	int size();
	bool isEmpty();
	bool isFull();
};
 
// Constructor to initialize stack
template <class X>
stack<X>::stack(int size)
{
	arr = new X[size];
	capacity = size;
	top = -1;
}
 
// function to add an element x in the stack
template <class X>
void stack<X>::push(X x)
{
	if (isFull())
	{
		X *newArray = new [SIZE*2];
		for (int i = 0; i<SIZE; i++) {
			newArray[i]=arr[i];
		}
		delete arr;
		arr = newArray;
		//cout << "OverFlow\nProgram Terminated\n";
		//exit(EXIT_FAILURE);
	}
 
	cout << "Inserting " << x << endl;
	arr[++top] = x;
}
 
// function to pop top element from the stack
template <class X>
X stack<X>::pop()
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
 
	cout << "Removing " << peek() << endl;
 
	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}
 
// function to return top element in a stack
template <class X>
X stack<X>::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}
 
// Utility function to return the size of the stack
template <class X>
int stack<X>::size()
{
	return top + 1;
}
 
// Utility function to check if the stack is empty or not
template <class X>
bool stack<X>::isEmpty()
{
	return top == -1;	// or return size() == 0;
}
 
// Utility function to check if the stack is full or not
template <class X>
bool stack<X>::isFull()
{
	return top == capacity - 1;	// or return size() == capacity;
}

/*template<class X>
bool stack<X>::printStack()
{
	for( int ix=size-1; ix>=0;ix--)
	cout<<"|"<<setw(4)<<stackPtr[ix]<<endl;
}*/
 
// main function
int main()
{
	stack<string> pt(2);
/*	stack<int>myStack(5);*/
 
	pt.push("A");
	pt.push("B");
	
	pt.pop();
	pt.pop();
	

 
	pt.push("12");

 
 	// Prints the top of the stack
 	cout << "Top element is: " << pt.peek() << endl;
 
 
	// Returns the number of elements present in the stack
	cout << "Stack size is " << pt.size() << endl;
	
 
	pt.pop();

 
	// check if stack is empty or not
	if (pt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

   /* cout<<"adding elements into stack:";
    int ct=0;
    while(ct++!=5);
    {
    	int temp;
    	cin>>temp;
    	myStack.push(temp);
    }
    
    //myStack.printStack();
    cout<<"\nDeleting two elements from the stack:\n";
    myStack.pop();
    myStack.pop();
   // myStack.printStack();*/
    
	return 0;
}


