#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void quicksort(int *a, int L, int R) {
  if (R <= L)
    return;
  int pivot = a[(L + R) / 2];
  int i = L, j = R;


  while (i < j) {
    while (a[i]< pivot)
      i++;
    while(a[j] >= pivot)
      j--;
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;;
  }
  // guarateed i == j
  quicksort(a, L, i);
  quicksort(a, i+1, R);
}
/*
int partition_sort(int *a, int l, int h)
{
    int pivot = a[(a[l] + a[h]) / 2];
    int i=l;
    int j=h;
    while (i<j)
    {
        while (a[i]< pivot)
            i++;
        while(a[j] >= pivot)
            j--;
          int temp=a[i];
          a[i]=a[j];
          a[j]=temp;
    }
    int temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}
void quicksort(int *a,int l, int h)
{
    if(l < h){
        int j = partition_sort(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}
*/
int main() {
    int a[] = {10,9,8,7,6};
    quicksort(a, 0, 4);
    for (int i=0; i<5; i++)
     {cout << a[i]<< ' ';}
return 0;
}


/*
void fun(int *arr, int n)
{
   for (int i=0; i<n; i++)
     {arr[i] = arr[i]+ 1;}
}

// Driver program
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
   fun(arr,8);
   for (int i=0; i<8; i++)
     {cout << arr[i]<< ' ';}
   return 0;
}
*/
