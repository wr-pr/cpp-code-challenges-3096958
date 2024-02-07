#include "complex_num.h"

complex_num::complex_num(double r, double i):real(r),imag(i){
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    z.real = real + w.real;
    z.imag = imag + w.imag;
    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    z.real = real - w.real;
    z.imag = imag - w.imag;
    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    z.real = real * w.real - imag * w.imag;
    z.imag = real * w.imag + imag * w.real;
    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    double denum = w.real*w.real + w.imag*w.imag;
    z.real = (real * w.real + imag * w.imag)/ denum;
    z.imag = (imag * w.real - real * w.imag)/ denum;
    return z;
}

void complex_num::print(std::ostream &os){
    if (imag >= 0) os << real << " + " << imag << "j";
    else os << real << " -" << -imag << "j";
}