/*Name: YUVRAJ SANTOSH SHIVTARE
 *Assignment 5: LinkedList
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int v, Node* next) : data(v), next(next) {}
    };
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* q;
        for (Node* p = head; p != nullptr; ) {
        q = p;
        p = p->next;
        delete q;
        }
    }
    LinkedList(const LinkedList& orig)  = delete;
    void operator =(const LinkedList& orig) = delete;

    void addEnd(int v) {
        if (head == nullptr) {
        head = new Node(v, nullptr);
        return;
        }
        Node* p;
        for (p = head; p->next != nullptr; p = p->next)
        ;
        p->next = new Node(v, nullptr);
    }
    int size() const {
        int count = 0;
        for (Node* p = head; p != nullptr; p=p->next)
            count++;
        return count;
    }

    int get(int i) const {
        for (Node* p = head; p != nullptr; i--, p = p->next)
        if (i == 0)
            return p-> data;
        throw "Out of bounds";
    }

    void removeodd()
    {
        Node* current = head;
        Node* temp = current;
        Node* previous = head;

        if (head->data%2 == 0)
            {
                head = head->next;
                current = head;
                delete temp;
            }
        else
        {
            previous = current;
            current= current->next;
        }

        while(current->next!= nullptr)
        {
            if (current->data %2 == 0)
                {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            else
                {
                    previous->next=current;
                    previous = current;
                    current = current->next;
                }
        }
        if(current->data %2 == 0)
            {
                Node* temp = current;
                previous->next =nullptr;
                delete temp;
            }
        else
            {
                previous->next=current;
                previous = current;
            }
    }

    class Iterator {
    private:
        Node* c;
    public:
        Iterator(LinkedList& list) : c(list.head) {}
        bool operator !() const { return c != nullptr; }
        void operator ++() { c = c->next; }
        int& operator *() const { return c->data; }
        bool hasnext() {return c->next!=nullptr;}
    };

    void insertAt(LinkedList& a, int data, int position)
    {
        Node *add = new Node(data,nullptr);

        if(a.head == NULL)
            a.head = add;
        else if(position == 0)
        {
            add->next = a.head;
            a.head = add;
        }
        else
        {
            Node *cur = a.head;
            int d = 1;
            while(cur != NULL)
            {
                if(d == position)
                {
                    add->next = cur->next;
                    cur->next = add;
                    break;
                }
                cur = cur->next;
                d++;
            }
        }
    }
};

void mergelist(LinkedList& a, LinkedList& b, int a_size, int b_size)
{
    if (b_size > 0)
    {
        int b_index = 0;
        for (int i= 0; i<=a_size;i+=2)
        {
                if (b_index < b_size)
                {
                    a.insertAt(a,b.get(b_index),i);
                    b_index++;
                    a_size++;
                }
                else
                    break;
        }
        while (b_index < b_size)
        {
            a.insertAt(a,b.get(b_index),a_size);
            a_size++;
            b_index++;
        }
    }
    else return;
}

void printlist(LinkedList& a, int n)
{
    for (int i =0; i<n; i++) cout << a.get(i) << ' ';
    cout<< "\n";
}

int main() {
    LinkedList a;
    LinkedList b;
    ifstream inputfile("hw5.dat");
    int num;
    if(!inputfile)
        cout<<"Error reading file. Please check file name and try again. \n";
    while(inputfile>>num)
        a.addEnd(num);
    for (LinkedList::Iterator i = a; !i; ++i)
        if (*i % 2 == 0)
            b.addEnd(*i);
    a.removeodd();
    mergelist(a,b,a.size(),b.size());
    cout<<"\nA: "; printlist(a , a.size());
    return 0;
}
