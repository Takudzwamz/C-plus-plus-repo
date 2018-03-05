// C++ program for implementation of Heap Sort
#include <iostream>
#include<time.h>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
 void init_array(bool random, int n, int* arr)
{
    if (random)
    {
        srand(time(0)); //initialize random;
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000000;
    }
    else
        for (int i = 0; i<n; i++)
        {
            cout << "arr[" << i << "]: ";
            cin >> arr[i];
        	
        }
} 


int main()
{
    int n;
	bool random;
	int option;
	double timeInSeconds;
	double initial_time,finishing_time;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	cout<<"to use random values press 1 :";
	cin>>random;
	
	 int* arr = new int[n]; //create int array with n size
    init_array(random, n, arr); //fill array using function
    
       
       cout<<"Operations on whether you want to see the unsorted array"<<endl;
       cout<<"\n-------------"<<endl;
       cout<<"1.Press 1 if you want to see generated unsorted randomised array  "<<endl;
       cout<<"2.Continue  sorting the array "<<endl;
       cout<<"Enter your Choice: ";
        cin>>option;
       switch(option)
       {
           case 1:
           for (int i = 0; i <= n; i++)
               {//display array
                     
                     cout << "_" << arr[i]<<endl;
    	
               } 
            break;   
            case 2:
            cout<<"your randomized array has been saved :"<<endl;
           // exit(1);
            break;
            default:
               cout<<"enter 1 or 2 to continue:"<<endl;
            
           
       }
    
    initial_time=clock();	
    heapSort(arr,n);
    finishing_time=clock();
 
    cout << "Heap Sorted array is: \n"<<endl;
  /**  printArray(arr, n);*/
    cout<<"Time taken to HeapSort the array is : "<< (finishing_time-initial_time)/CLOCKS_PER_SEC<<endl;
}
