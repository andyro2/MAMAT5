#include "polynom.h"

polynom::polynom(int n, int* coefs) :n_(n) {
	for (unsigned int i = 0; i <= n; i++)
		coefs_[i] = coefs[i];
}

polynom& polynom::operator+(const polynom& p2) {
	int n =(this->n_ > p2.n_) ? this->n_ : p2.n_;
	int* coefs = new int[n]; // how to make malloc or new????
	for (unsigned int i = 0; i <= n; i++) {
		if(i > this->n_)
			coefs[i] = p2.coefs_[i];
		else if (i > p2.n_)
			coefs[i] = this->coefs_[i];
		else
			coefs[i] = this->coefs_[i] + p2.coefs_[i];
	}
	polynom p(n, coefs);
	return p;
}

polynom& polynom::operator-(const polynom& p2) { // this - p2
	int n = (this->n_ > p2.n_) ? this->n_ : p2.n_;
	int* coefs = new int[n]; 
	for (unsigned int i = 0; i <= n; i++) {
		if (i > this->n_)
			coefs[i] = (-1)*p2.coefs_[i];
		else if (i > p2.n_)
			coefs[i] = this->coefs_[i];
		else
			coefs[i] = this->coefs_[i] - p2.coefs_[i];
	}
	polynom p(n, coefs);
	return p;
}

polynom& polynom::operator*(const polynom& p2) {
	int n = this->n_ + p2.n_;
	int* coefs = new int[n]; 
	for (unsigned int i = 0; i <= this->n_; i++) 
	{
		for (unsigned int j = 0; j <= p2.n_; j++)
		{
			coefs_[i + j] = this->coefs_[i] * p2.coefs_[j];
		}
	}
	polynom p(n, coefs);
	return p;
}

polynom& polynom::Derivative() {
	int* coefs = new int[this->n_ - 1];
	for (unsigned int i = 1; i <= this->n_; i++) {
			coefs[i - 1] = this->coefs_[i] * i;
	}
	polynom p(this->n_ -1, coefs);
	return p;
}

polynom& polynom::Integral() {
	int* coefs = new int[this->n_ + 1];
	coefs[0] = 0;
	for (unsigned int i = 1; i <= this->n_; i++) {
		coefs[i] = this->coefs_[i - 1] / i;
	}
	polynom p(this->n_ + 1, coefs);
	return p;
}
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
