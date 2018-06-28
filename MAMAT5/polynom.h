#ifndef _POLY_F
#define _POLY_F

#include "func.h"
#include <cmath>

using namespace std;


class polynom : public func {
 public:
 
	 polynom(unsigned int n = 0, int* coefs = NULL );
	 polynom operator+(const polynom& p2) const; //sums up two polynoms
	 polynom operator-(const polynom& p2) const; //deducts two polynoms
	 polynom operator*(const polynom& p2) const; //multyplies two polynoms
	 polynom Derivative() const;
	 polynom Integral() const;

	 polynom(const polynom& rhs); // copy constructor
	 polynom& operator=(const polynom& p2); // = operator
	 ~polynom();

	 int Func_output(const int& x);
	 void Print_Func(ostream& ro) const; //constant function of virtual print function.



//	 bool operator!=(const polynom& p2);

	 void Copy_Coefs(const int* coefs, unsigned int n);
	void printcoefs(ostream&)  const ;

  protected:
	  
  unsigned int n_; //order of the polynom
  int* coefs_; //coefficients 
};



#endif
 
