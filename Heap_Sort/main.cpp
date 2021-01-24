#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void max_heap(int *a,int s,int i)
{
    int l= 2*i+1;
    int r= 2*i+2;
    int largest;
    if (l<s && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if (r<s && a[r]>a[largest])
        largest=r;
    if (largest!=i)
    {
        swap(a[i],a[largest]);
        max_heap(a,s,largest);
    }
}

int main()
{
    int a[]= {0,6,5,0,-5,2,7,1,3};
    int length= sizeof(a)/sizeof(a[0]);
    for(int i=length/2-1;i>=0; i--)
        max_heap(a,length,i);
    for(int i=0; i<length ;i++){
        cout << a[i]<<" ";}
        cout << "\n";
    for (int i=length-1; i>=0;i--)
    {
        swap(a[0], a[i]);
        max_heap(a,i,0);
    }
    for(int i=0; i<length ;i++){
        cout << a[i]<<" ";}
    return 0;
}
