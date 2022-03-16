#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int count;

void bubble_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++){
        count++;
        for(int j=0;j<n-i-1;j++){
            count++;
            count++;
            if(arr[j]>arr[j+1]){
                count++;
                count++;
                count++;
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        count++;
    }
    count++;
}

int main(void)
{
 int arr[25], n, x;
 count=0;
 cout<<"enter no. of elements";
 cin>>n;
 cout<<"enter "<< n <<" elements";
 for(int i=0;i<n;i++) cin>>arr[i];

 auto start = high_resolution_clock::now();
 bubble_sort(arr, n);
 auto stop = high_resolution_clock::now();

 cout<<"the sorted array is";
 for(int i=0;i<n;i++) cout<<arr[i];
 cout<<"Number of steps for search function "<<count;

 auto duration = duration_cast<microseconds>(stop - start);
 cout << "time taken to run  function: "<<duration.count() << endl;
 return 0;
}
