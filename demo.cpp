#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "interpolation.h"

using namespace alglib;

int main(int argc, char **argv)
{
        real_1d_array x = "[0.0, 1.0, 2.0]";
        real_1d_array y = "[0.0, 1.0, 2.0]";
        real_1d_array f = "[5.00, 5.00, 5.00,5.00,5.00,5.00,5.00, 5.00,5.00]";
        spline2dinterpolant s;
        real_2d_array c;
        ae_int_t m;
        ae_int_t n;
        ae_int_t d;

        // Build the bicubic vector-valued spline
        spline2dbuildbicubicv(x, y, f, 1, s);

        // unpack and test
        spline2dunpackv(s, m, n, d, c);
        printf("%s\n", c.tostring(4).c_str());

        // Check the number of rows and columns
        int numRows = c.rows();
        int numCols = c.cols();

        // Print the size
        printf("Number of rows: %d\n", numRows);
        printf("Number of columns: %d\n", numCols);


    return 0;
    
}
