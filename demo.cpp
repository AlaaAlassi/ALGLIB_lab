#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "interpolation.h"

using namespace alglib;

int main(int argc, char **argv)
{
    try
    {
        //
        // We build bilinear spline for f(x,y)=x+2*y+3*xy for (x,y) in [0,1].
        // Then we demonstrate how to unpack it.
        //
        real_1d_array x = "[0.0, 1.0]";
        real_1d_array y = "[0.0, 1.0]";
        real_1d_array f = "[0.00,1.00,2.00,6.00]";
        real_2d_array c;
        ae_int_t m;
        ae_int_t n;
        ae_int_t d;
        spline2dinterpolant s;

        // build spline
        spline2dbuildbilinearv(x, 2, y, 2, f, 1, s);

        // unpack and test
        spline2dunpackv(s, m, n, d, c);
        printf("%s\n", c.tostring(4).c_str()); // EXPECTED: [[0, 1, 0, 1, 0,2,0,0, 1,3,0,0, 0,0,0,0, 0,0,0,0, 1]]
    }
    catch(alglib::ap_error alglib_exception)
    {
        printf("ALGLIB exception with message '%s'\n", alglib_exception.msg.c_str());
        return 1;
    }
    return 0;
}