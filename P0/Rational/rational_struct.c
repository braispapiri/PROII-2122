//
// Created by brais on 04/02/2022.
//

#include "rational_struct.h"

//      Operacion para crear un numero racional
Rational createRational(int n, int d) {
    Rational temp;          //temporal
    temp.num = n;
    temp.den = d;
    return temp;
}

//      Devolver numerador de un racional
int numerator(Rational r){
    return r.num;
}

//      Devolver denominador de un racional
int denominator(Rational r) {
    return r.den;
}

//      Suma de dos racionales
Rational sum(Rational r1, Rational r2) {
    Rational s;             //suma
    s.num = r1.num * r2.den + r2.num * r1.den;
    s.den = r1.den * r2.den;
    return s;
}
