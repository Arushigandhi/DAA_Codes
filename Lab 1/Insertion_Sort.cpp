#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int count;

void insertion_sort(int arr[], int n)
{
    for(int i=1;i<n;i++){
        count++;
        count++;
        count++;
        int temp=arr[i];
        int j=i-1;
        count++;
        while(arr[j]>temp && j>=0){
            count++;
            count++;
            count++;
            arr[j+1]=arr[j];
            j--;
        }
        count++;
        count++;
       arr[j+1]=temp;
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
 insertion_sort(arr, n);
 auto stop = high_resolution_clock::now();
 cout<<"the sorted array is";
 for(int i=0;i<n;i++) cout<<arr[i];
 cout<<"Number of steps for search function "<<count;

 auto duration = duration_cast<microseconds>(stop - start);
 cout << "time taken to run  function: "<<duration.count() << endl;
 return 0;
}
