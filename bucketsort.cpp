// C++ program to sort an array using bucket sort
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
 
// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
    // 1) Create n empty buckets
    vector<float> b[n];
    
    // 2) Put array elements in different buckets
    for (int i=0; i<n; i++)
    {
       int bi = n*arr[i]; // Index in bucket
       b[bi].push_back(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}

int main()
{
    double timeInSeconds;
	double initial_time,finishing_time;
	srand(time(0));
	int n;
	char q;
	char yes = 'y';
	cout << "Enter Size Of Array : ";
	cin >> n;
	float *array = new float[n];

	for (int i = 0; i < n; i++) {
		array[i] = (rand() % (n * 3)) / (pow(10.0, 3));//code for number of numbers after the comma 
	}
	
	cout << "See the generated numbers on the screen : (y or n) ";
	cin >> q;
	switch (q == yes) {
	case 1:for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
		   break;
	}
	cout << endl;
	

			initial_time = clock();
			bucketSort(array, n);
			finishing_time = clock();
			cout<<"sorterd array is :"<<endl;
			for (int i = 0; i < n; i++) {
			    
				cout << array[i] << " "<<endl;
			}
		
	cout<<"Time taken to sort using buckeTSort is :"<<(finishing_time-initial_time)/CLOCKS_PER_SEC<<endl;
	
return 0;
}
