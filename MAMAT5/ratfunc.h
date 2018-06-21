#ifndef _RATFUNC_F
#define _RATFUNC_F

#include "func.h"
#include "polynom.h"

using namespace std;


class ratfunc : public func {
public:

	ratfunc(polynom p, polynom q);
	ratfunc& operator+(const ratfunc& r2); //sums up two rational finctions
	ratfunc& operator-(const ratfunc& r2); //deducts two rational finctions
	ratfunc& operator*(const ratfunc& r2); //multyplies two rational finctions
	ratfunc& Derivative();

//	ostream& operator<<(ostream& ro, const func& f);
	void printcoefs(ostream&)  const;

protected:

	polynom numerator_; // q(x)
	polynom denominator_; // p(x)
};



#endif
