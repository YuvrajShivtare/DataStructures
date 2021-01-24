#include <iostream>
using namespace std;
int sumofnum(int a=3, int b=3)
{
    return a+b;
}

double sumofnum(double a=3.14, double b=3.14)
{
    return a+b;
}

void printarray(int arr[], int size)
{
    for (int x=0; x < size; x++)
    {
        cout<< arr[x]<<endl;
    }
}
int main()
{
    //int a, b;
    //double c,d;
    int arr[]={1,2,2,3,4};
    int size = (sizeof(arr)/sizeof(arr[0]));
    cout<<"Size of array: "<< size<< endl;
    printarray(arr,size);
    cout<<"this is sum of int: "<<sumofnum(3)<<endl;
    cout<<"this is sum of double: "<<sumofnum(3.14)<<endl;
    return 0;
}
