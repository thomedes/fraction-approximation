#include "fractions.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define value(a) (a.precision - log10(a.n + a.d))
#define fraction(a) ((double) a.n / a.d)

struct fraction_precision closest_fraction(double r, int steps,
                                           int (*callback) (struct
                                                            fraction_precision))
{
    const double    x = r > 0 ? r : -r;
    struct fraction_precision loop = { x, 1, 0 }, best = loop, optimum = loop;

    while (steps--) {
        double          y = fraction(loop);

        loop.precision = x == y ? 9999 : -log10((y > x ? y / x : x / y) - 1);

        if (loop.precision > best.precision) {
            if (callback != NULL && value(loop) > value(optimum)) {
                steps = (*callback) (optimum = loop);
            }
            best = loop;
        }
        (y < x) ? ++loop.n : (loop.n = x * ++loop.d);
    }
    return best;
}

#undef value
#undef fraction

#if TEST

static unsigned steps;

static int evaluate(struct fraction_precision f)
{
    printf("%10d / %-10d => %.10f (%4.1f)\n",
           f.n, f.d, (float) f.n / f.d, f.precision);
    /* How many more steps to try, return 0 if goog enough */
    return steps;
}

int main(int argc, char *argv[])
{
    struct fraction_precision result;
    double          x;

    if (argc != 3) {
        fprintf(stderr, "Syntax: %s <number> <steps>\n", argv[0]);
        return EXIT_FAILURE;
    }
    sscanf(argv[1], "%lg", &x);
    sscanf(argv[2], "%u", &steps);

    printf("Computing %f with %u steps limit\n", x, steps);
    result = closest_fraction(x, steps, &evaluate);
    printf("Best result:\n");
    evaluate(result);
    return EXIT_SUCCESS;
}
#endif                                     /* TEST */
