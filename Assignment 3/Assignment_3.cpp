/* Name: YUVRAJ SHIVTARE
 * ASSIGNMENT NO:02
 */
#include<iostream>
#include<bits/stdc++.h>
#include <stdlib.h>

using namespace std;

//GCD calculating function
int gcd(int a, int b) {
  while (b != 0) {
	int temp = b;
	b = a % b;
	a = temp;
  }
  return a;
}

//LCF Calculating function
int lcf(int& a, int& b, int& var_gcd)
{
    return (a*b)/var_gcd;
}


//POWERMOD Calculating function


long long power(long long base, long long exponent, long long mod)
{
    long long prod = 1;
    while (exponent > 0)
    {
        if (exponent % 2 != 0)
            {
                prod = (prod * base) % mod;
                cout << "prod: "<< prod << endl;
            }
        base = (base * base) % mod;
        exponent = exponent / 2;
        cout << "a: " << base <<endl<< "n: " << exponent<< endl;

    }

   return prod;
}

int main(int argc, char *argv[])
{
    int m, n, z;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    z = atoi(argv[3]);
    int gcd_var= gcd(m,n);
    cout << "GCD of "<< m <<" and "<< n << " is: " <<gcd_var<<"\n";
    cout << "LCF of "<< m <<" and "<< n << " is: " <<lcf(m,n,gcd_var)<<"\n";
    cout << "Powermod of "<< m <<" and "<< n <<" mod "<<z<< " is: " <<power(m,n,z)<<"\n";
    return 0;
}
