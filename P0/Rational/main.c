#include <stdio.h>

#include "rational_struct.h"

int main() {
    Rational r1, r2, r3, r4, s;
    r1 = createRational(2,3);
    r2 = createRational(5,7);
    r3 = createRational(7,3);
    r4 = createRational(5,4);
    s=sum(r1,r2);
    printf("La suma entre %d y %d es %d/%d\n",r1, r2, numerator(s), denominator(s));
    s=sum(r3,r4);
    printf("La suma entre %d y %d es %d/%d\n", r3, r4, numerator(s), denominator(s));
}
