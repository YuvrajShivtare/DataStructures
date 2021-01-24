#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class HashMapLinearChaining {
private:
    int size = 500000;
    LinkedList **table;
    int counter = 0;
    hash<string> str_hash;
public:
    HashMapLinearChaining (){
		table = new LinkedList*[size];
		for (int i =0; i < size; i++)
            table[i]=new LinkedList();
	}
    void add(const string& s) {
        int index = str_hash(s) % size;
        if (table[index]->contains(s) == 1)
            return;
        else
        {
            table[index]->addStart(s);
            counter++;
        }
	}
	void getString(int index){
	for (int i = 0; i<table[index]->size(); i++)
            cout<< table[index]->get(i)<<endl;
	}
	int getSize(int index){
        return table[index]->size();
	}
	int getelements()
	{
        return counter;
	}
	void removeString(const string& s) {
        int index = str_hash(s) % 500000;
        if (table[index]->contains(s) == 1)
            {
                table[index]->removeString(s);
                counter--;
            }
	}
	bool contains(const string& s) {
        int index = str_hash(s) % 500000;
        if (table[index]->contains(s) == 1)
            return true;
        return false;//cout << s << endl;
	}
	void computeHistogram() {
	    int c0=0,c1=0,c2=0,c9=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0;
	    for (int i = 0; i < 500000; i++)
        {

            if (table[i]->size() == 0)
                c0++;
            if (table[i]->size() == 1)
                c1++;
            if (table[i]->size() == 2)
                c2++;
            if (table[i]->size() == 3)
                c3++;
            if (table[i]->size() == 4)
                c4++;
            if (table[i]->size() == 5)
                c5++;
            if (table[i]->size() == 6)
                c6++;
            if (table[i]->size() == 7)
                c7++;
            if (table[i]->size() == 8)
                c8++;
            if (table[i]->size() >= 9)
                c9++;
        }
        cout << "nodes with 0 elements--> "<< c0 << endl;
        cout << "nodes with 1 elements--> "<< c1 << endl;
        cout << "nodes with 2 elements--> "<< c2 << endl;
        cout << "nodes with 3 elements--> "<< c3 << endl;
        cout << "nodes with 4 elements--> "<< c4 << endl;
        cout << "nodes with 5 elements--> "<< c5 << endl;
        cout << "nodes with 6 elements--> "<< c6 << endl;
        cout << "nodes with 7 elements--> "<< c7 << endl;
        cout << "nodes with 8 elements--> "<< c8 << endl;
        cout << "nodes with 9 elements--> "<< c9 << endl;
	}
	void printHashMap(){
	for (int i = 0; i< 500000;i++)
        for (int j =0 ; j < table[i]->size();j++)
            cout<< table[i]->get(j)<< endl;
	}
};
