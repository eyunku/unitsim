#ifndef UNITVAL_H
#define UNITVAL_H

struct unitval {
    // numerical value
    float value;
    // stores the exponent of the 7 base SI units in the following order
    // s, m, kg, A, K, mol, cd
    // eg. all zeroes is unitless, [-2, 1, 1, 0, 0, 0, 0, 1] is Newtons
    // final value is the exponent, [-2, 1, 1, 0, 0, 0, 0, 3] is kN
    int units[8];
    // stores string representing the unit
    char unitstr[32];
};

#endif