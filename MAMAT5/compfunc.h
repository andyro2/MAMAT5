#ifndef _COMP_F
#define _COMP_F

#include "func.h"
#include "polynom.h"

using namespace std;

class compfunc : public func {

public:
	compfunc(polynom p, polynom q);

	int Func_output(const int& x);
	void Print_Func(ostream& ro) const;

protected:
	polynom inner_func_;
	polynom outer_func_;
};


#endif