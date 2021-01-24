#include <bits/stdc++.h>
#include<iostream>
#define max_n 1000
#include <fstream>
#include<string>
using namespace std;
//LCS Calculating Function
int lcs(const string& X,const string& Y, int m, int n, int c[][max_n])
{

    if (m == 0 || n == 0)
        return 0;
    if (c[m-1][n-1] != 0)
        {
            return c[m-1][n-1];
        }
    if (X[m-1] == Y[n-1])
        {
            c[m-1][n-1] = 1 + lcs(X, Y, m - 1, n - 1, c);
            return c[m-1][n-1];
        }
    else
        {
            c[m-1][n-1] = max(lcs(X, Y, m, n - 1, c),lcs(X, Y, m - 1, n, c));
            return c[m-1][n-1];
        }
}
int main()
{
    /*Please specify the file name instead of mytext.txt to read the file.
    Make sure the file is in the same path as program is. */

    //Reading mytext.txt #file 1
    string A;
    ifstream file_("mytext.txt");
    if(file_.is_open())
        {
            while(getline(file_,A)){}
            file_.close();
        }
    else
        {
            cout<<"File is not open file 1";
        }

    /*Please specify the file name instead of mytext.txt to read the file.
    Make sure the file is in the same path as program is. */
    //Reading mytext1.txt #file 2
    string B;
    ifstream file2_("mytext1.txt");
    if(file2_.is_open())
        {
            while(getline(file2_,B)){}
            file2_.close();
        }
    else
        {
            cout<<"File is not open file 2";
        }
    int m = A.length();
    int n = B.length();
    int memo[m][max_n];
    for (int i= 0; i< m; i++)
        {
            for(int j=0; j<max_n; j++)
                {
                    memo[i][j] = 0;
                }
        }
    cout << "Both files have "<<lcs(A, B, m, n, memo)<< " bytes in common as LCS."<<"\n";
    return 0;
}
