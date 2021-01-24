#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
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
