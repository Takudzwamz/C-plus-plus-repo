#include<iostream>
#include<cstdlib>
#include<time.h> 
using namespace std;
 
// Swapping two values.
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
// Partitioning the array on the basis of values at high as pivot value.
int Partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 
	// Getting index of pivot.
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	// Swapping value at high and at the index obtained.
	swap(&a[pivot], &a[index]);
 
	return index;
}
 
// Random selection of pivot.
int RandomPivotPartition(int a[], int low, int high)
{
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);
 
	// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}
 
// Implementing QuickSort algorithm.
int QUICKSORT_RANDOM_PIVOT(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{
		// Partitioning array using randomized pivot.
		pindex = RandomPivotPartition(a, low, high);
		// Recursively implementing QuickSort.
		QUICKSORT_RANDOM_PIVOT(a, low, pindex-1);
		QUICKSORT_RANDOM_PIVOT(a, pindex+1, high);
	}
	return 0;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
	int option,choice;
	double timeInSeconds;
	double initial_time,finishing_time;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	cout<<"to use random values press 1 :";
	cin>>random;
 
    int* arr = new int[n]; //create int array with n size
    init_array(random, n, arr); //fill array using function
    
   
       cout<<"\n-------------"<<endl;
       cout<<"Operations on whether you want to see the unsorted array"<<endl;
       cout<<"\n-------------"<<endl;
       cout<<"1.Do you want to see generated unsorted randomised array  "<<endl;
       cout<<"2.Continue to sorting the array "<<endl;
       cout<<"Enter your Choice: ";
       cin>>option;
       switch(option)
       {
           case 1:
           for (int i = 0; i <= n; i++)
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
    
    
    while(true)
    {
       cout<<"\n-------------"<<endl;
       cout<<"Operations on choosing QuickSort pivot method "<<endl;
       cout<<"\n-------------"<<endl;
       cout<<"1.Choose QuickSorting method using random pivot "<<endl;
       cout<<"2.Choose QuickSorting method using last element as pivot "<<endl;
       cout<<"3.Quit"<<endl;
       cout<<"Enter your Choice: ";
       cin>>choice;
       switch(choice)
       {
          case 1:
          initial_time=clock();
	      QUICKSORT_RANDOM_PIVOT(arr, 0, n-1);
	      finishing_time=clock();
       // Printing the sorted data.
	      cout<<"\nSorted Data using random pivot: "<<endl;
	      for (int i = 0; i < n; i++)
	      {
		     cout<<"->"<<arr[i]<<endl;
	      }
            cout<<"Time taken to  quicksort the array using random pivot "<< (finishing_time-initial_time)/CLOCKS_PER_SEC<<endl;
          break;
          case 2:
          initial_time=clock();
          quickSort(arr, 0, n-1);
          finishing_time=clock();
          cout<<"\nSorted Data using last element pivot : "<<endl;
    	  for (int i = 0; i < n; i++)
          {
		      cout<<"->"<<arr[i]<<endl;
	      }
              cout<<"Time taken to  quicksort the array using last element   pivot: "<< (finishing_time-initial_time)/CLOCKS_PER_SEC<<endl;
          break;
          case 3:
              exit(1);
              break;
          default:
               cout<<"Wrong choice"<<endl;
    
       }
    }
    return 0;
}
   