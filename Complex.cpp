#include "Complex.h"
#include <cmath>
#include <cstdlib>

Complex::Complex()
{
	_real = 0.0;
	_imag = 0.0;
}


// Constructors

Complex::Complex(double re, double im)
{
	_real = re;
	_imag = im;
}

Complex::Complex(const Complex& z)
{
	_real = z.real();
	_imag = z.imag();
}

// access values
double Complex::real() const
{
	return _real;
}

double Complex::imag() const 
{
	return _imag;
}


// assignment
Complex& Complex::operator=(double r)
{
	_real = r;
	_imag = 0;	
	return *this;
}


Complex& Complex::operator+=(const Complex& z)
{
	_real += z.real();
	_imag += z.imag();

	return *this;

}

Complex& Complex::operator-=(const Complex& z)
{
	
	_real -= z.real();
	_imag -= z.imag();

	return *this;
}

Complex& Complex::operator*=(const Complex& z)
{
	double n_real = (_real *z.real()) - (_imag * z.imag());
	double n_imag = (_imag * z.real()) + (_real * z.imag());
	_real = n_real;
	_imag = n_imag;

	return *this;

}

Complex& Complex::operator/=(const Complex&z)
{

	double denom;
	denom = (z.real()*z.real()) + (z.imag()*z.imag());
	double n_real = (_real * z.real()) - (_imag * -z.imag());
        double n_imag = (_imag * z.real()) + (_real * -z.imag());
	_real = n_real / denom;
	_imag = n_imag /denom;
	return *this;

}
// basic math operations
Complex& Complex::operator=(const Complex& z)
{
        _real = z.real();
        _imag = z.imag();

        return *this;
}

Complex operator+(const Complex& a, const Complex& b)
{
	double reals = a.real() + b.real();
	double imags = a.imag() + b.imag();

	Complex total(reals,imags);

	return total;
}

Complex operator-(const Complex& a, const Complex& b)
{
	double reals = a.real() - b.real();
        double imags = a.imag() - b.imag();

	Complex total(reals,imags);

	return total;
}

Complex operator*(const Complex& a, const Complex& b)
{
	double first = a.real() * b.real();
        double outside = a.real() * b.imag(); 
	double inside = b.real() * a.imag();
	double last  = -1 * a.imag() * b.imag();

	double imags = outside + inside;
	double reals = first + last;

	Complex total(reals,imags);

	return total;
}

Complex operator/(const Complex& a, const Complex& b)
{
	double top_first = a.real() * b.real();
	double top_inNout = a.real() * -1 * b.imag() + b.real() * a.imag();
	double top_last = a.imag() * b.imag();

	double bot_first = b.real() * b.real();
	double bot_last =  b.imag() * b.imag();
	
	double top_reals = top_last + top_first;
	double top_imags = top_inNout;
	double bottom = bot_first + bot_last;
	
	double reals = top_reals / bottom;
	double imags = top_imags / bottom;

	Complex total(reals,imags);


	return total;
}

// norm returns the squared magnitude of z
double norm(const Complex& z)			
{						
	double total = z.real() * z.real() + z.imag() * z.imag();

	return total;
}


// conj returns the complex conjugate of z
Complex conj(const Complex& z)
{
	Complex total(z.real(), -(z.imag()));

	return total;
}

// comparison
bool operator==(const Complex& a, const Complex& b)
{
	if ((a.real() == b.real()) && (a.imag() == b.imag()))
		return true;
	else
		return false;	

}

bool operator==(const Complex& a, double r)
{

	if (a.real() == r && a.imag() == 0)

		return true;
	else
		return false;

}

bool operator!=(const Complex& a, const Complex& b)
{
	if ((a.real() != b.real()) && (a.imag() != b.imag()))
		return true;
        else
		return false;


}

bool operator!=(const Complex& a, double r)
{	
	if (a.real() != r && a.imag() != 0)
		return true;
	else
		return false;
}

// write the complex number z to the output stream in the
// format "6+5i" or "6-5i"

std::ostream& operator<<(std::ostream& out, const Complex& z)
{
	out<< z.real() << (z.imag() > 0? "+": "") << z.imag();

	return out;

}

