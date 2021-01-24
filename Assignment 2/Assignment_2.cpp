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
int power(int a, int n, int m)
{
	int prod = 1;

	while (y > 0)
	{

		if (y%2!= 0)
			prod = (prod*a) % m;


        y = y/2;
		x = (x*x) % p;
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
