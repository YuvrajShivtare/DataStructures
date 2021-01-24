/*Name: Yuvraj Santosh Shivtare
 *Assignment 7:Matrix
 */
#include <iostream>
#include <cmath>
#include <vector>
#include<fstream>
#include<algorithm>
using namespace std;

template<typename T>
class GrowArray {a
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

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        double maxElement = abs(A[i][i]);
        int get_maxRow = i;
        for (int j=i+1; j<n; j++) {
            if (abs(A[j][i]) > maxElement) {
                maxElement = abs(A[j][i]);
                get_maxRow = j;
            }
        }

        for (int k=i; k<n+1;k++) {
            double tmp1 = A[get_maxRow][k];
            A[get_maxRow][k] = A[i][k];
            A[i][k] = tmp1;
        }

        for (int l=i+1; l<n; l++) {
            double temp2 = -A[l][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j)
                    A[l][j] = 0;
                else
                    A[l][j] += temp2 * A[i][j];
            }
        }
    }

    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int j=i-1;j>=0; j--) {
            A[j][n] -= A[j][i] * x[i];
        }
    }
    return x;
}

int main() {
    GrowArray<double> a;
    ifstream inputfile("mat.dat");
    double num;
	if(!inputfile)
		cout<<"Error reading file. Please check file name and try again. \n";
	while(inputfile>>num)
		a.addEnd(num);
    double n = a.get(0);
    // Initialize Matrix A
    vector<double> line(n+1,0);
    vector< vector<double> > A(n,line);
    //Adding values to Matrix A
    int index = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A[i][j] = a.get(index);
            index++;
        }
    }
    //Creating augmented Matrix A
    for (int i=0; i<n; i++) {
        A[i][n] = a.get(index);
        index++;
    }
    //Creating Variable vector Matrix
    vector<double> B(n);
    B = gauss(A);

    cout << "Result:\n";
    for (int i=0; i<n; i++) {
        cout << B[i] << endl;
    }
    cout << endl;
}
