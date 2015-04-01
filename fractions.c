#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define value(a) (a.precision - log10(a.n + a.d))
#define fraction(a) ((float) a.n / a.d)

struct fraction_precision {
    unsigned n, d;
    float precision;
};

struct fraction_precision closest_fraction(double x, int steps, 
                                           int (*callback)(struct fraction_precision))
{
    struct fraction_precision loop = { 0, 1, 0 }, best = loop, optimum = loop;

    if (x < 0) {
        x = -x;
    }
    
    while (--steps) {
        double y = fraction(loop);
        
        loop.precision = x == y ? 9999 : -log10((y > x ? y / x : x / y) - 1);
        
        if (loop.precision > best.precision) {
            if (value(loop) > value(optimum)) {
                steps = (*callback)(optimum = loop);
            }
            best = loop;
        }
        (y < x) ? ++loop.n : ++loop.d;
    }
    return best;
}
#undef value
#undef fraction

int evaluate(struct fraction_precision f)
{
    printf("%10d / %-10d => %.10f (%4.1f)\n", 
           f.n, f.d, (float) f.n / f.d, f.precision);
    return 1000; /* How many more steps to try */
}


int main(int argc, char *argv[]) 
{
    struct fraction_precision result;

    //result = closest_fraction(2.718281828459045, 1000, &evaluate);
    result = closest_fraction(3.14159265359, 1000, &evaluate);
    printf("Best result:\n");
    evaluate(result);
    
    return EXIT_SUCCESS;
}