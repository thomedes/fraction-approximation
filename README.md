# fraction-approximation

C function / program to find an integer fraction that approximates a double

The output is similar to

```
Computing 3.141593 with 1000 steps limit
         3 / 1          => 3.0000000000 ( 1.3)
        22 / 7          => 3.1428570747 ( 3.4)
       333 / 106        => 3.1415095329 ( 4.6)
       355 / 113        => 3.1415929794 ( 7.0)
Best result:
       355 / 113        => 3.1415929794 ( 7.0)
```

This program uses the naive algorithm of progressively increassing the numerator
or the denominator as the resulting fraction is over/under the desired value. 
This is certainly slow, specially for big numbers but the resulting function is 
very simple and can be easily understood.

The resulting fraction allows for fast multiplication / division in embedded 
systems where the processor does not have a FPU (Foating Point Unit) or 
simulates it in firmware / microcode.

Be carefull when choosingn the numerator to avoid overflowing your integer
size when multipliying by the maximum input allowed.

Right now I'm studing the continued fractions algorithm to see it it would be a
better fit for this. If this is the case I'll change the function to use it.