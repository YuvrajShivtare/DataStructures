#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

template<typename T>
class GrowArray {
private:
    int capacity;
    int used;
    T* data;
    void grow()
    {
        capacity = capacity *2;
    }
public:
	GrowArray() : capacity(1), used(0), data(new T[1]) {}
	~GrowArray()
	{
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
            data[used++] = v;
        }
	}

	void addStart(T v)
	{
	    if (used == capacity) grow();
        const T* old = data;
        data = new T[capacity];
        for (int i = 0; i < used ; i++) data[i+1]= old[i];
        data[0]=v;
        used ++;
        delete [] old;
	}

	void removeStart()
	{
	    const T* old = data;
	    data = new T[--used];
        for (int i = 0; i < used ; i++) data[i]= old[i+1];
        delete [] old;
    }

    void removeEnd()
    {
        const T* old = data;
	    data = new T[--used];
        for (int i = 0; i < used ; i++) data[i]= old[i];
        delete [] old;
        //used--;
    }

    void setValue(int pos, T v)
    {
        if (pos >= used || pos < 0)
        {
            cout<< "\nPosition out of bounds\n";
            return;
        }
        data[pos] = v;
    }

    void insertValue(int pos, T v)
    {
        if (pos > used || pos < 0)
        {
            cout<< "\nPosition out of bounds\n";
            return;
        }
        if (used >= capacity) grow();
        const T* old = data;
	    data = new T[++used];
	    for (int i = 0; i <= used ; i++)
        {
            if (i < pos) data[i] = old[i];
            else if (i == pos) data[pos] = v;
            else if (i > pos) data[i] = old[i-1];
        }
    }

    void removeValue(int pos)
    {
        if (pos >= used || pos < 0)
        {
            cout<< "\nPosition out of bounds\n";
            return;
        }
        const T* old = data;
	    data = new T[--used];
	    for (int i = 0; i < used+1; i++)
        {
            if (i < pos) data[i] = old[i];
            else if (i == pos) continue;
            else if (i > pos) data[i-1] = old[i];
        }
    }

	T get(int i)
	{
		return data[i];
	}

	int size() const
	{
        return used;
    }
};

int main()
{
	GrowArray<int> a;
	for (int i = 0; i < 10; i++) a.addEnd(i);
	cout << "addEnd of array:"<< "\t";
	for (int i = 0; i < a.size(); i++) cout<< a.get(i)<< ' ';
	cout << "\n";
	for (int i = 0; i < 10; i++) a.addStart(i);
	cout << "addStart of array: "<< "\t";
	for (int i = 0; i < a.size(); i++) cout<< a.get(i)<< ' ';
	cout << "\nremoveStart of array: \t";
    a.removeStart();
    for (int i = 0; i < a.size(); i++) cout<< a.get(i)<< ' ';
    cout << "\nremoveEnd of array: \t";
    a.removeEnd();
    for (int i = 0; i < a.size(); i++) cout<< a.get(i)<< ' ';
    a.setValue(0, 5);
    cout << "\nset value 5 at 0: \t";
    for (int i = 0; i < a.size(); i++) cout<< a.get(i)<< ' ';
    cout << "\ninsert 10 at 10:\t";
    a.insertValue(10, 10);
    for (int i = 0; i < a.size(); i++) cout<< a.get(i)<< ' ';
    cout << "\nremove 0th element:\t";
    a.removeValue(0);
    for (int i = 0; i < a.size(); i++) cout<< a.get(i)<< ' ';
    return 0;
}
