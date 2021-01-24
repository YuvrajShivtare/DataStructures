/*Name: YUVRAJ SANTOSH SHIVTARE
 *ASSIGNMENT 4: QUICKSORT
 */
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

void quicksort(int *a, int n)
{
    if (n <= 1)
        return;
    int L = 0;
    int R = n-1;
    int pivot = a[L+R/2];
    while (L <= R)
    {
        while (a[L] < pivot)
            ++L;
        while (a[R] > pivot)
            --R;
        if (R >= L)
        {
            swap(a[R],a[L]);
            if(a[R] == a[L])
                R--;
        }
    }
    quicksort(a, L);
    quicksort( &a[L+1], n-1-L);
    return;
}

template<typename T>
class GrowArray {
private:
  int capacity;
  int used;
  T* data;
  const T* start = data;
  void grow() {
    capacity = capacity *2;
  }
public:
	GrowArray() : capacity(1), used(0), data(new T[1]) {}
	~GrowArray() {
		delete [] data;
	}
	GrowArray(const GrowArray& orig) = delete;
	GrowArray& operator =(const GrowArray& orig) = delete;

	void addEnd(T v)
	{
        if (used == capacity)
        {
            grow();
            const T* old = data;
            data = new T[capacity];
            for (int i = 0; i < used ; i++)
                data[i] = old[i];
            data[used++] = v;
            delete [] old;
        }
        else
        {
            data[used] = v;
            used++;
        }
	}
	T get(int i) {
		return data[i];
	}
	int size() const {
	return used;}
};

int main()
{
	GrowArray<int> a;
	ifstream inputfile("hw2a.dat");
    int num;
	if(!inputfile)
		cout<<"Error reading file. Please check file name and try again. \n";
	while(inputfile>>num)
		a.addEnd(num);
    int total_arrray = a.get(0);
    int index = 1;
    for (int i = 0; i<total_arrray;i++)
    {
        int b = index + 1, c = a.get(index) ;
        int x[c];
        index = index + a.get(index) + 1;
        for (int i=0; i<c ; i++)
        {
            x[i]=a.get(b);
            b++;
        }
        quicksort(x,c);
        for (int i=0; i<c ; i++)
            cout<< x[i]<<" ";
        cout <<"\n";
    }
    return 0;
}