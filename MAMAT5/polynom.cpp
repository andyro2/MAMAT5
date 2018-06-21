#include "polynom.h"

polynom::polynom(int n, int* coefs) :n_(n), coefs_(Copy_Coefs(coefs,n)) {}
int* polynom::Copy_Coefs(const int* coefs , int n) {

	for (unsigned int i = 0; i <= n; i++)
		coefs_[i] = coefs[i];
}

polynom& polynom::operator+(const polynom& p2) {
	int n =(n_ > p2.n_) ? n_ : p2.n_;
	int* coefs = new int[n]; // how to make malloc or new????
	for (unsigned int i = 0; i <= n; i++) {
		if(i > n_)
			coefs[i] = p2.coefs_[i];
		else if (i > p2.n_)
			coefs[i] = coefs_[i];
		else
			coefs[i] = coefs_[i] + p2.coefs_[i];
	}
	polynom p(n, coefs);
	return p;
}

polynom& polynom::operator-(const polynom& p2) { // this - p2
	int n = (n_ > p2.n_) ? n_ : p2.n_;
	int* coefs = new int[n]; 
	for (unsigned int i = 0; i <= n; i++) {
		if (i > n_)
			coefs[i] = (-1)*p2.coefs_[i];
		else if (i > p2.n_)
			coefs[i] = coefs_[i];
		else
			coefs[i] = coefs_[i] - p2.coefs_[i];
	}
	polynom p(n, coefs);
	return p;
}

polynom& polynom::operator*(const polynom& p2) {
	int n = n_ + p2.n_;
	int* coefs = new int[n]; 
	for (unsigned int i = 0; i <= n_; i++) 
	{
		for (unsigned int j = 0; j <= p2.n_; j++)
		{
			coefs_[i + j] = coefs_[i] * p2.coefs_[j];
		}
	}
	polynom p(n, coefs);
	return p;
}

polynom& polynom::Derivative() {
	int* coefs = new int[n_ - 1];
	for (unsigned int i = 1; i <= n_; i++) {
			coefs[i - 1] = coefs_[i] * i;
	}
	polynom p(n_ -1, coefs);
	return p;
}

polynom& polynom::Integral() {
	int* coefs = new int[n_ + 1];
	coefs[0] = 0;
	for (unsigned int i = 1; i <= n_; i++) {
		coefs[i] = coefs_[i - 1] / i;
	}
	polynom p(n_ + 1, coefs);
	return p;
}
/*
ostream& polynom::operator<<(ostream& ro, const func& f) {

}

*/
void polynom::printcoefs(ostream& os)  const {
  int allZero = 1;
  for (int i = n_ ; i>=0; i--) {
    if (coefs_[i]>0) {
      allZero = 0;
      if(i!=n_){
	os << "+";
      }
      if (coefs_[i]!=1 || i==0){
	os << coefs_[i];
      }
      if(i>0) {
	os << "x";
	if (i>1) 
	  os << "^" << i ;
      }
    }
    else if(coefs_[i]<0) {
      allZero = 0;
      if (coefs_[i]!=-1 || i==0){
	os << coefs_[i];
      }
      else 
	os << "-";
      if(i>0) {
	os << "x";
	if (i>1) 
	  os << "^" << i ;
      }
    }
    else if(i==0 && allZero == 1){ //zero polynom
        os << "0";
	continue;
    }
  }
}


polynom::polynom(const polynom& rhs) : n_(rhs.n_), coefs_(Copy_Coefs(rhs.coefs_, rhs.n_)) {}

polynom& polynom::operator=(const polynom& p2) {
	if (this != &p2)
	{
		n_ = p2.n_;
		if (coefs_) delete [] coefs_; // not sure works
		coefs_ = Copy_Coefs(p2.coefs_, p2.n_);
	}
	return *this;
}

bool polynom::operator!=(const polynom& p2) {
	if (n_ != p2.n_)
		return false;

	for (unsigned int i = 0; i <= p2.n_; i++) // p2.n_ and n_ same size
	{
		if (coefs_[i] != p2.coefs_[i])
			return false;
	}

	return true;
}

polynom::~polynom() {
	if (coefs_) delete[] coefs_;
}