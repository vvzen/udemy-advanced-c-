#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

namespace vv {

    class ComplexNumber {

        private:
            double real;
            double imaginary;

        public:

            ComplexNumber();
            ComplexNumber(double real, double imaginary);

            // copy constructor
            ComplexNumber(const ComplexNumber &other);

            // equal operator
            const ComplexNumber& operator=(const ComplexNumber &other);

            // stream insertion operator
            friend std::ostream & operator<<(std::ostream &out, const ComplexNumber &number);
    };
}

#endif /* COMPLEX_H_ */