#include <bits/stdc++.h>
#include <string>
#include<fstream>
#include <iostream>
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

class Trie {
private:
	class Node {
        public:
            Node *next[26];
            bool isWord = false;
            Node()
            {
                isWord = false;
                for (int i = 0; i < 26; i++)
                   next[i] = NULL;
            }
        };
	Node* root;
	int counter = 0;
public:
    Trie() {
        root = new Node();
	};
	~Trie(){
        delete root;
	};
    Trie(const Trie& orig) = delete;
    Trie& operator =(const Trie& orig) = delete;

    void add(const string& key)
        {
            Node *p = root;
            for(int i = 0; i < key.length(); i++)
            {
                int c = key[i] - 'a';
                if(p->next[c] == NULL)
                {
                    Node *temp = new Node();
                    p->next[c]=temp;
                    p = temp;
                }
                else
                    p = p->next[c];
            }
            p->isWord = true;
            counter++;
        }
    void remove(const string& word)
    {
        Node *p = root;
        for(int i = 0; i < word.length(); i++)
        {
            int c = word[i] - 'a';
            if(p->next[c] == NULL)
                return;
            else
                p = p->next[c];
        }
        p->isWord = false;
        counter--;
    };

    bool contains(const string& word)
        {
            Node *p = root;
            for(int i = 0; i < word.length(); i++)
            {
                int c = word[i] - 'a';
                if(p->next[c] == NULL)
                    return false;
                else
                    p = p->next[c];
            }
            return p->isWord;
        }

    bool containsPrefix(const string& word)
    {
        Node *p = root;
        for(int i = 0; i < word.length(); i++)
        {
            int c = word[i] - 'a';
            if(p->next[c] == NULL)
                return false;
            else
                p = p->next[c];
        }
        printhelper(p,word);
    };

    void print()
    {
        printhelper(root, "");
    }
    void printhelper(Node *root,string prex)
    {
        if (root->isWord)
            cout << prex<< endl;
        for (int i = 0; i < 26 ; i++)
        {
            if (root->next[i]!= NULL)
            {
                printhelper(root->next[i], prex + char('a'+ i));
            }
        }
    }
    int getSize()
    {
        return counter;
    }
};

bool wordcheck(const string& s)
{
    for(int i = 0; i < s.size(); ++i)
        if (!((s[i] >= 'a' && s[i]<='z')))
                return false;
    return true;
}

int main (){
    Trie a;
   /*
    *Add Words:
    */
    ifstream file;
    string s, filename;
    int c = 0;
    filename = "testAdd.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
            a.add(s);
        file.close();
    }
    else
        cout << "Failed to open testAdd.txt\n";
    /*
     *Contains Words:
     */

    cout<< "Words from testContains in trie: "<< endl;
    filename = "testContains.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
            {
                if (a.contains(s))
                {
                    cout << s <<endl;
                }

            }
        file.close();
    }
    else
        cout << "Failed to open testContains.txt\n";

    /*
     *Print Word with Prefix:
     */

    cout<<endl;
    filename = "testPrefix.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
            {
                cout<< "words with prefix '" << s << "':"<<endl;
                a.containsPrefix(s);
            }
        file.close();
    }
    else
        cout << "Failed to open testPrefix.txt\n";

    /*
     *Remove Words:
     */
    cout<<endl;
    filename = "testRemove.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
            {
                a.remove(s);
            }
        file.close();
    }
    else
        cout << "Failed to open testRemove.txt\n";
    cout <<"Words in trie: " <<endl;
    a.print();

    Trie dict;
    /*
     * Add Dictionary:
     */
    filename = "dict.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
            {
                dict.add(s);
            }
        file.close();
    }
    else
        cout << "Failed to open dict.txt\n";
    cout<<endl<< "Total words in dict.txt: "<<dict.getSize()<<endl;

    /*
     * Read prideandprejudice.txt
     */

    filename = "prideandprejudice.txt";
    int ct = 0,total_words =0;
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file >> s)
            {
                total_words++;
                if (wordcheck(s))
                    {
                        if(dict.contains(s))
                            c++;
                        else
                            ct++;
                    }
            }
        file.close();
    }
    else
        cout << "Failed to open prideandprejudice.txt\n";

    cout << "Total words in prideandprejudice: "<<total_words<<endl;
    cout<< "Total words from dict in prideandprejudice: " << c << "\n";
    cout<< "Total words from dict not in prideandprejudice: " << ct << "\n";

    /*
     *HashMap Implementation using Linear Chaining:
     */

    HashMapLinearChaining hashstring;
    cout<< endl<<"-------------x----------------x---------------x------------"<<endl;

    /*
     * Add words from testAdd.txt
     */

    filename = "testAdd.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
            hashstring.add(s);
        file.close();
    }
    else
        cout << "Failed to open testAdd.txt\n";
    cout<< "Histogram: "<<endl;
    hashstring.computeHistogram();

    /*
     * Print words from testContains which are present in Hash Table:
     */

    cout<< endl<<endl<<"Words from testContains in Hash Table: "<< endl;
    filename = "testContains.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
                if (hashstring.contains(s) == true)
                    cout<<s<<endl;
        file.close();
    }
    else
        cout << "Failed to open testContains.txt\n";

    /*
     * Remove words from testRemove which are present in Hash Table:
     */

     cout<<endl;
    filename = "testRemove.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
            hashstring.removeString(s);
        file.close();
    }
    else
        cout << "Failed to open testRemove.txt\n";
    cout<< "Elements in Hash Map:"<< endl;
    hashstring.printHashMap();

    HashMapLinearChaining hashdict;
    /*
     *Add words from dict.txt to Hash Table
     */
    cout<<endl;
    filename = "dict.txt";
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file>>s)
            hashdict.add(s);
        file.close();
    }
    else
        cout << "Failed to open dict.txt\n";
    cout<< endl<<"Total words in dict: "<< hashdict.getelements()<<endl;

    /*
     *Compare words from prideandjudice.txt with the words in Hash Table
     */

    filename = "prideandprejudice.txt";
    ct = 0,total_words =0,c=0;
    file.open(filename.c_str());
    if (file.is_open())
    {
        while(file >> s)
            {
                total_words++;
                if(hashdict.contains(s)==true)
                    c++;
                else
                    ct++;
            }
         file.close();
    }
    else
        cout << "Failed to open prideandprejudice.txt\n";

    cout << "Total words in prideandprejudice: "<<total_words<<endl;
    cout<< "Total words from dict in prideandprejudice: " << c << "\n";
    cout<< "Total words from dict not in prideandprejudice: " << ct << "\n";
    return 0;
}
