// C++ implementation of Radix Sort
#include<iostream>
using namespace std;
 
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; ++i)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; ++i)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; --i)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; ++i)
        arr[i] = output[i];
}
 

void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
 
  void init_array(bool random, float n, int* arr)
{
    if (random)
    {
        srand(time(0)); //initialize random;
        for (int i = 0; i < n; ++i)
            arr[i] = rand() % 100;
    }
    else
        for (int i = 0; i<n; ++i)
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
    cout<<"Enter number of Elements in Array"<<endl;
    cin>>n;
    cout<<"to use random values press 1 :";
    cin>>random;
    int* arr=new int[n];
    init_array(random, n, arr);
    
       cout<<"Operations on whether you want to see the unsorted array"<<endl;
       cout<<"\n-------------"<<endl;
       cout<<"1.Do you want to see generated unsorted randomised array  "<<endl;
       cout<<"2.Continue to sorting the array "<<endl;
       cout<<"Enter your Choice: ";
       cin>>option;
       switch(option)
       {
           case 1:
           for (int i = 0; i <= n; ++i)
               {//display array
                     
                     cout << "_" << arr[i];
    	
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
	radixsort(arr, n);
	finishing_time=clock();
   
    cout<<"Sorted Array:"<<endl;
    print(arr, n);
    cout<<endl;
    cout<<"Time taken to sort using reddix sort is :"<<(finishing_time-initial_time)/CLOCKS_PER_SEC<<endl;
    return 0;
}