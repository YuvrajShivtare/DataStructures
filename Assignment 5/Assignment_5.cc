/* Name: Yuvraj Shivtare
 * Assignment 5: GrowArray_Convexhullpoints
 */
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

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
	GrowArray<double> a[65];
	ifstream inputfile("convexhullpoints.dat");
		double num;
		if(!inputfile)
		{
			cout<<"Error reading file. Please check file name and try again. \n";
		}
		int c=0, j=0, k =0;
		while(inputfile>>num)
		{
			a[64].addEnd(num);
			c++;
		}
    double x[c/2], y[c/2];
    for (int i = 0; i < c; i++)
    {
        if (i%2 == 0)
        {
            x[k]= a[64].get(i);
            k++;
        }
        else
        {
            y[j]= a[64].get(i);
            j++;
        }
    }
    double x_min = *min_element(x,x+(c/2-1));
    double y_min = *min_element(y,y+(c/2-1));
    double x_max = *max_element(x,x+(c/2-1));
    double y_max = *max_element(y,y+(c/2-1));
    cout << fixed << setprecision(18)<< "min[x]: "<< x_min<< "\t" << "min[y]: "<< y_min<< "\n";
    cout << fixed << setprecision(18)<< "max[x]: "<< x_max<< "\t"<< "max[y]: "<< y_max<< "\n\n";
    int n = 8, i = 0;
    for (k = 0; k< c/2; k++)
    {
        i = (y[k] - y_min)  / (y_max- y_min) * (n - 1);
        j = (x[k] - x_min) / (x_max- x_min) * (n - 1);
        if (j == 0 || i == 0 || i == 7 || j == 7)
        {
            if (i == 0)
            {
                a[j].addEnd(x[k]);
                a[j].addEnd(y[k]);
            }
            if (j == 0)
            {
                a[8+i].addEnd(x[k]);
                a[8+i].addEnd(y[k]);
            }
            if (i == 7)
            {
                a[16+j].addEnd(x[k]);
                a[16+j].addEnd(y[k]);
            }
            if (j == 7)
            {
                a[31-i].addEnd(x[k]);
                a[31-i].addEnd(y[k]);
            }
        }
    }
    for (int r = 0; r< 8; r++)
       {
           cout << "P["<<r <<"][0]: ";
               for (int i = 0; i < a[r].size(); i++)
                {
                    if (i%2 == 0)
                        cout<< fixed << setprecision(18)<<"["<< a[r].get(i);
                    else
                        cout<< fixed << setprecision(18)<<","<< a[r].get(i)<<"]"<<"\t";
                }
            cout<< "\n\n";
        }
    for (int r = 0; r< 8; r++)
       {
           cout << "P[0]["<<r <<"]: ";
               for (int i = 0; i < a[r+8].size(); i++)
                {
                    if (i%2 == 0)
                        cout<< fixed << setprecision(18)<<"["<< a[r+8].get(i);
                    else
                        cout<< fixed << setprecision(18)<<","<< a[r+8].get(i)<<"]"<<"\t";
                }
             cout<< "\n\n";
        }
    for (int r = 0; r< 8; r++)
       {
           cout << "P["<<r <<"][7]: ";
               for (int i = 0; i < a[r+16].size(); i++)
                {
                    if (i%2 == 0)
                        cout<< fixed << setprecision(18)<<"["<< a[r+16].get(i);
                    else
                        cout<< fixed << setprecision(18)<<","<< a[r+16].get(i)<<"]"<<"\t";
                }
             cout<< "\n\n";
        }
    for (int r = 0; r< 8; r++)
       {
           cout << "P[7]["<<r <<"]: ";
               for (int i = 0; i < a[31-r].size(); i++)
                {
                    if (i%2 == 0)
                        cout<< fixed << setprecision(18)<<"["<< a[31-r].get(i);
                    else
                        cout<< fixed << setprecision(18)<<","<< a[31-r].get(i)<<"]"<<"\t";
                }
             cout<< "\n\n";
        }
    return 0;
}
