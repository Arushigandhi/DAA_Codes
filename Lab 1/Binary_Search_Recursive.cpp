#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int count;

int binary_search_rec(int arr[], int l, int r, int x)
{
    count++;
    if (r >= l) {
        count++;
        int mid = l + (r - l) / 2;
        count++;
        if (arr[mid] == x){
            count++;
            return mid;
        }
        count++;
        if (arr[mid] > x){
            count++;
            return binary_search_rec(arr, l, mid - 1, x);
        }
        count++;
        return binary_search_rec(arr, mid + 1, r, x);
    }
    count++;
    return -1;

}

int main(void)
{
 int arr[25], n, x;
 count=0;
 cout<<"enter no. of elements";
 cin>>n;
 cout<<"enter "<< n <<" elements";
 for(int i=0;i<n;i++) cin>>arr[i];
 cout<<"enter the element to be searched";
 cin>> x;
 int result = -1;
 auto start = high_resolution_clock::now();
 result = binary_search_rec(arr,0, n-1, x);
 auto stop = high_resolution_clock::now();
 (result == -1)? cout<<"Element is not present in array"
 : cout<<"Element is present at index " <<result;
 cout<<endl;
 cout<<"Number of steps for search function "<<count;
 auto duration = duration_cast<microseconds>(stop - start);
 cout << "time taken to run  function: "<<duration.count() << endl;
 return 0;
}
