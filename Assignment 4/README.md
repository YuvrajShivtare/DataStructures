# Quicksort
Open a file which must be called hw2a.dat in the current directory. No directory names must be specified. For example, if your program includes the file  c:/Users/mydir/hw2a.dat it will not work on anyone else's computer but yours and the program will score 50%.
 
input file format:
 
number of test cases
number of elements to sort in test 1
data for test1
number of elements to sort in test 2
data for test2
...
etc.
 
For example, the following input file (must be called hw2a.dat)

5\
10\
1 2 3 4 5 6 7 8 9 10\
10\
10 9 8 7 6 5 4 3 2 1\
11\
1 2 3 4 5 6 7 8 9 10 11\
11\
11 10 9 8 7 6 5 4 3 2 1\
6\
5 4 4 4 4 1
 
should output:\
1 2 3 4 5 6 7 8 9 10\
1 2 3 4 5 6 7 8 9 10\
1 2 3 4 56 7 8 9 10 11\
12 3 4 5 6 7 8 9 10 11\
1 4 4 4 4 5
