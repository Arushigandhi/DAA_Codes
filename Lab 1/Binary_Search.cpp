#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int count;

int binary_search(int a[], int n, int x)
{
    int l = 0, h = n-1, m, pos;
    count++;
    for (int j = 0; j < n; j++)
    {
        count++;
        count++;
        m = (l + h) / 2;
        count++;
        if (a[m] == x)
        {
            count++;
           pos = m;
            break;
        }
        else if (a[m] > x)
        {
            count++;
            count++;
            h = m - 1;
        }
        else
        {
            count++;
            count++;
            l = m + 1;
        }
    }
    count++;
    count++;
    return pos;
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
 result = binary_search(arr, n, x);
 auto stop = high_resolution_clock::now();
 (result == -1)? cout<<"Element is not present in array"
 : cout<<"Element is present at index " <<result;
 cout<<endl;
 cout<<"Number of steps for search function "<<count;
 auto duration = duration_cast<microseconds>(stop - start);
 cout << "time taken to run  function: "<<duration.count() << endl;
 return 0;
}
