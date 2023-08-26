
There is a library which supports a few types of 3D geometric curves – circles, ellipses and 3D helixes. Each  is able to return a 3D point and a first derivative (3D point of vector assuming that it starts from 0) per parameter t along the curve.
The main function:
1. Populates a container of objects of these types created in random manner with random parameters.
2. Prints coordinates of points and derivatives of all curves in the container at t=PI/4.
3. Populates a second container that would contain only circles from the first container via pointers.
4. Sorts the second container in the ascending order of circles’ radii. That is, the first element has the
smallest radius, the last - the greatest.
5. Computes the total sum of radii of all curves in the second container using multithreading. ***Num of threads is defined in NUM variable of Makefile.***

The implementation:
1. Uses virtual methods.
2. Has neither explicit memory deallocation nor memory leaks.
3. Curves are physically correct (e.g. radii must be positive).
4. Containers and sorting are implemented using STL (C++ Standard Template Library).
5. The implementation uses constructs of C++17.
6. The code is compiled with g++ compiler.

- All curves are parametrically defined.
- Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
- Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.
- Helix is spatial and is defined by its ***semiaxises*** and step.