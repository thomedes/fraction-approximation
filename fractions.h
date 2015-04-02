#ifndef __FRACTIONS_H__
#define __FRACTIONS_H__

/**
 * @brief Struct holding a fraction and it's precision
 *
 * precision is defined as the number of significant digits.
 */
struct fraction_precision {
    unsigned        n,
                    d;
    float           precision;
};

/**
 * @brief Find fraction close enough to a real
 *
 * @param[in]   x       Real number to find fraction for
 * @param[in]   steps   Maximum number of steps, limits run time
 * @param[in]   callback    Function to evaluate a local maximum. Optional.
 *                          pass NULL if not required
 *
 * @returns The best fraction found. Always positive. invert sign if so required
 */
struct fraction_precision closest_fraction(double x, int steps,
                                           int (*callback) (struct
                                                            fraction_precision));
#endif                                     /* __FRACTIONS_H__ */
