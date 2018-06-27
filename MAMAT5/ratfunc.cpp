#include "ratfunc.h"


ratfunc::ratfunc(polynom p, polynom q) : numerator_(q), denominator_(p) {}

ratfunc ratfunc:: operator+(const ratfunc& r2) {
	polynom new_num, new_den;
	new_num = numerator_ * r2.denominator_ + denominator_*r2.numerator_;
	new_den = denominator_ * r2.denominator_;
	ratfunc r(new_den, new_num);
	return r;
}

ratfunc ratfunc:: operator-(const ratfunc& r2) { // this - p2
	polynom new_num, new_den;
	new_num = numerator_ * r2.denominator_ - denominator_ * r2.numerator_;
	new_den = denominator_ * r2.denominator_;
	ratfunc r(new_den, new_num);
	return r;
}

ratfunc ratfunc:: operator*(const ratfunc& r2) {
	polynom new_num, new_den;
	new_num = numerator_ * r2.numerator_;
	new_den = denominator_ * r2.denominator_;
	ratfunc r(new_den, new_num);
	return r;
}

ratfunc ratfunc::Derivative() {
	polynom new_num, new_den;
	new_num = numerator_.Derivative() * denominator_ - denominator_.Derivative() * numerator_;
	new_den = denominator_ * denominator_;
	ratfunc r(new_den, new_num);
	return r;
}

int ratfunc::Func_output(const int& x)
{
	//mathexception excep = mathexception("divide by zero");
	int result1 = numerator_.Func_output(x);
	int result2 = denominator_.Func_output(x);
	//if (!result2)
	//{
	//	throw excep;
	//}

	return result1 / result2;
}

ratfunc::~ratfunc() {
	denominator_.~polynom();
	numerator_.~polynom();
}

ratfunc::ratfunc(const ratfunc& rhs) {
	numerator_ = rhs.numerator_;
	denominator_ = rhs.denominator_;
	fmap_ = rhs.fmap_;
}

ratfunc& ratfunc::operator=(const ratfunc& rhs) {
	if (this != &rhs) {
	numerator_ = rhs.numerator_;
	denominator_ = rhs.denominator_;
	fmap_ = rhs.fmap_;
	}
}

void ratfunc::Print_Func(ostream& ro) const
{
	ro << "(";
	numerator_.printcoefs(ro);
	ro << ")";
	ro << "/";
	cout << "(";
	denominator_.printcoefs(ro);
	ro << ")";
	ro << endl;
	
	ro << "Derivative: ";
	cout << "(";
	this->Derivative.numerator_.printcoefs(ro);
	ro << ")";
	ro << "/";
	ro << "(";
	this->Derivative.denominator_.printcoefs(ro);
	cout << ")";
	ro << endl;
	if (!(fmap_.empty()))
		plot(ro);
}