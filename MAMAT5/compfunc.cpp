#include "compfunc.h"


compfunc::compfunc(polynom q, polynom p) : inner_func_(p), outer_func_(q) {}

void compfunc::Print_Func(ostream& ro) const {
	cout << endl;
	if (!(fmap_.empty()))
		plot(ro);
}

int compfunc::Func_output(const int& x) {
	int inner_out = inner_func_.Func_output(x);
	return outer_func_.Func_output(inner_out);
}