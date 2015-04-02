#ifndef __FRACTIONS_H__
#define __FRACTIONS_H__

struct fraction_precision {
    unsigned        n,
                    d;
    float           precision;
};

struct fraction_precision closest_fraction(double x, int steps,
                                           int (*callback) (struct
                                                            fraction_precision));
#endif                                     /* __FRACTIONS_H__ */
