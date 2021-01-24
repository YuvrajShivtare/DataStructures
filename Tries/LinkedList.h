#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class LinkedList {
private:
    class LNode {
    public:
        string data;
        LNode* next;
        LNode(string v, LNode* next) : data(v), next(next) {}
    };
    LNode* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        LNode* q;
        for (LNode* p = head; p != nullptr; ) {
        q = p;
        p = p->next;
        delete q;
        }
    }
    LinkedList(const LinkedList& orig)  = delete;
    void operator =(const LinkedList& orig) = delete;

    void addStart(const string& v) {
    head = new LNode(v, head);
    }
    void removeString(const string& word){
    if (head == nullptr)
      return;

    LNode* p = head;
    if ((p->data == word)&&(p->next == nullptr)) {
      delete p;
      head = nullptr;
      return;
    }

    if (p->data == word)
    {
        head = p->next;
        delete p;
        return;
    }

    LNode* q = p;
    p = p->next;
    for ( ; p->next != nullptr; q = p, p = p->next)
      {
          if (p->data == word)
          {
                LNode* temp = p;
                q->next = p->next;
                delete temp;
          }
      }
      if (p->data == word)
      {
        delete p;
        q->next = nullptr;
      }
    }
    bool contains(const string& s){
        if (head == nullptr)
            return false;
        LNode* p = head;
        for (;p->next != nullptr; p = p->next)
        {
            if (p->data == s)
                return true;
        }
        return p->data == s;
    }
    int size() const {
        int count = 0;
        for (LNode* p = head; p != nullptr; p=p->next)
            count++;
        return count;
    }

    string get(int i) const {
        for (LNode* p = head; p != nullptr; i--, p = p->next)
        if (i == 0)
            return p-> data;
        throw "Out of bounds";
    }

};
