

#include<iostream>
//#include<conio.h>
#include<stdlib.h>

using namespace std;

void Bucket_sort(int arr[], int max){

     int maxsize = max;
     int *bucket_list = new int[maxsize+1];
    // int length = sozeof(bucket_list) / sizeof(bucket[0]);
     int length = maxsize;
     for(int i = 0; i <max;i++){
         bucket_list[i] = 0; //fill with zeros
       }
       for (unsigned int i = 0; i <length; i++){
           bucket_list[arr[i]]++;
        }
        int position = 0;
        for (unsigned int i = 0 ; i < length ; i++){
           for(int k = 0; k<bucket_list[i];k++){
                arr[position++] = i;
             }
          }
       }
      int main() {
         int max = 50;
         int arr[max];
         for (int i = 0; i < max; i++){
            arr[i] = rand()%50;
            }
            cout<<"Here are the numbers before Bucker Sort"<<endl;
            for (int j = 0; j < max; j++){
                 cout<<arr[j];
              }
            Bucket_sort(arr,max);
            for (int k = 0; k<max; k++){
               cout<<arr[k];
              }
             // getch();
              return 0;
           }