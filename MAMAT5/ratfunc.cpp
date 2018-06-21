#include "ratfunc.h"


ratfunc::ratfunc(polynom p, polynom q) : numerator_(q), denominator_(p) {}

ratfunc& ratfunc:: operator+(const ratfunc& r2) {
	polynom new_num, new_den;
	new_num = numerator_ * r2.denominator_ + denominator_*r2.numerator_;
	new_den = denominator_ * r2.denominator_;
	ratfunc r(new_den, new_num);
	return r;
}

ratfunc& ratfunc:: operator-(const ratfunc& r2) { // this - p2
	polynom new_num, new_den;
	new_num = numerator_ * r2.denominator_ - denominator_ * r2.numerator_;
	new_den = denominator_ * r2.denominator_;
	ratfunc r(new_den, new_num);
	return r;
}

ratfunc& ratfunc:: operator*(const ratfunc& r2) {
	polynom new_num, new_den;
	new_num = numerator_ * r2.numerator_;
	new_den = denominator_ * r2.denominator_;
	ratfunc r(new_den, new_num);
	return r;
}

ratfunc& ratfunc::Derivative() {
	polynom new_num, new_den;
	new_num = numerator_.Derivative() * denominator_ - denominator_.Derivative() * numerator_;
	new_den = denominator_ * denominator_;
	ratfunc r(new_den, new_num);
	return r;
}