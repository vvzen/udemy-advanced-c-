#include "complex.h"

namespace vv {

    // CONSTRUCTORS
    // default constructor
    ComplexNumber::ComplexNumber(){
        real = 0;
        imaginary = 0;
    }

    // classic constructor
    ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary){}


    // copy constructor
    ComplexNumber::ComplexNumber(const ComplexNumber &other){
        imaginary = other.imaginary;
        real = other.real;
    }

    // equal overloaded
    const ComplexNumber& ComplexNumber::operator=(const ComplexNumber &other){
        imaginary = other.imaginary;
        real = other.real;

        return *this;
    }

    // stream insertion operator
    std::ostream & operator<<(std::ostream &out, const ComplexNumber &number){
        out << "(" << number.imaginary << "," << number.real << ")";
        return out;
    }

} /* namespace: vv */