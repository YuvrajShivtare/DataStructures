Please follow these instructions carefully.  If you don’t understand something, ask before you submit your work.  Please do not be surprised if your failure to follow these instructions results in significant loss of points.
Write a class GrowArray as discussed in class.  Your list is composed of 2D-points (floats). 


Read in a file called convexhullpoints.dat containing a large number of x y pairs. 


In a single pass through those x y pairs, find the minimums, xmin, ymin, and maximums xmax, yMax.


Consider a rectangle  [xmin, xmax] × [ymin,ymax]⊂ R2.  Divide the rectangle into an n x n grid. For simplicity, you may set n = 8.


Sort the points from the file into GrowArrays, one for each grid cell.  A point x y should be stored in the grow array for cell(i, j), where i is the row and j is the column:
i = (y - ymin)  / (ymax- ymin) * (n - 1)
j = (x - xmin) / (xmax- xmin) * (n - 1)

note: to reduce the constant slightly you can precompute:
XInterval  = (n - 1)/(xmax - xmin)
YInterval = (n - 1)/(ymax - ymin)
Since multiplying is faster than dividing i = (y - ymin) * YInterval.


Once all the points are sorted into their appropriate Grow arrays, print to the screen 
xmin, xmax,ymin,ymax followed by the size of each of the perimeter cells, each grow array to its own line. 
 
A sample convexhullpoints.dat file follows.  Though the sample file below only contains 3 points, your code should only be limited by the amount of memory available on your computer for the grow arrays.
7.004 34 -9 2 -43.8 0 
