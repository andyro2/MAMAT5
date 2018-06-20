#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using namespace std;


class polynom : public func {
 public:
 
	 polynom(int n, int* coefs);
	 polynom& operator+(const polynom& p2); //sums up two polynoms
	 polynom& operator-(const polynom& p2); //deducts two polynoms
	 polynom& operator*(const polynom& p2); //multyplies two polynoms
	 polynom& Derivative();
	 polynom& Integral();

	 ostream& operator<<(ostream& ro, const func& f);
	void printcoefs(ostream&)  const ;

  protected:

  int n_; //order of the polynom
  int* coefs_; //coefficients 
};



#endif
 
