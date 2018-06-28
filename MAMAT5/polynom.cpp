#include "polynom.h"

polynom::polynom(unsigned int n, int* coefs) :n_(n) { Copy_Coefs(coefs, n); }

void polynom::Copy_Coefs(const int* coefs , unsigned int n) {
	if (coefs == NULL) {
		coefs_ = NULL;
		return;
	}
	coefs_ = new int[n + 1];
	for (unsigned int i = 0; i <= n; i++)
		coefs_[i] = coefs[i];
	return;
}

polynom polynom::operator+(const polynom& p2) const {
	unsigned int n =(n_ > p2.n_) ? n_ : p2.n_;
	int* coefs = new int[n + 1]; // n+1 elements for n degree [0..n]
	unsigned int i;
	for (i = 0; i <= n; i++) {
		if(i > n_)
			coefs[i] = p2.coefs_[i];
		else if (i > p2.n_)
			coefs[i] = coefs_[i];
		else
			coefs[i] = coefs_[i] + p2.coefs_[i];
	}
	for (i = n; i >= 0; i--) { // search for first non zero coeficient
		if (coefs_[i] != 0)
			break;
	}
	polynom p(i, coefs);
	delete[] coefs;
	return p;
}

polynom polynom::operator-(const polynom& p2) const { // this - p2
	unsigned int n = (n_ > p2.n_) ? n_ : p2.n_;
	int* coefs = new int[n + 1]; 
	unsigned int i;
	for ( i = 0; i <= n; i++) {
		if (i > n_)
			coefs[i] = (-1)*p2.coefs_[i];
		else if (i > p2.n_)
			coefs[i] = coefs_[i];
		else
			coefs[i] = coefs_[i] - p2.coefs_[i];
	}
	for (i = n; i >= 0; i--) { // search for first non zero coeficient
		if (coefs_[i] != 0)
			break;
	}
	polynom p(i, coefs);
	delete[] coefs;
	return p;
}

polynom polynom::operator*(const polynom& p2) const {
	unsigned int n = n_ + p2.n_;
	int* coefs = new int[n+1]; 
	unsigned int i;
	for (i = 0; i <= n; i++) // assign zeroes to all coefs as default
		coefs[i] = 0;

	for ( i = 0; i <= n_; i++) 
	{
		for (unsigned int j = 0; j <= p2.n_; j++)
		{
			coefs_[i + j] += coefs_[i] * p2.coefs_[j];
		}
	}
	for (i = n; i >= 0; i--) { // search for first non zero coeficient
		if (coefs_[i] != 0)
			break;
	}
	polynom p(i, coefs);
	delete[] coefs;
	return p;
}

polynom polynom::Derivative() const {
	int* coefs = new int[n_];
	for (unsigned int i = 1; i <= n_; i++) {
			coefs[i - 1] = coefs_[i] * (int)i;
	}
	polynom p(n_ -1, coefs);
	delete[] coefs;
	return p;
}

polynom polynom::Integral() const {
	int* coefs = new int[n_ + 2];
	coefs[0] = 0;
	for (unsigned int i = 1; i <= n_; i++) {
		coefs[i] = coefs_[i - 1] / (int)i;
	}
	polynom p(n_ + 1, coefs);
	delete[] coefs;
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


int polynom::Func_output(const int& x)
{
	int sum = 0;
	for (unsigned int i = 0; i <= n_; i++)
		sum += coefs_[i] *int(pow(x, i));
	return sum;
}

 void polynom::Print_Func(ostream& ro) const {
	 this->printcoefs(ro);
	 ro << endl;
	 ro << "Derivative: ";
	 this->Derivative().printcoefs(ro);
	 // polynom derivative = this.Derivative;
	 // derivative.printcoefs(ro);
	 ro << endl;
	 ro << "Integral: ";
	 this->Integral().printcoefs(ro);
	 ro << "+C" << endl;
	 return;
}


polynom::polynom(const polynom& rhs) : n_(rhs.n_) { 
Copy_Coefs(rhs.coefs_, rhs.n_);
fmap_ = rhs.fmap_;
}

polynom& polynom::operator=(const polynom& p2) {
	if (this != &p2)
	{
		n_ = p2.n_;
		if (coefs_) delete [] coefs_; // if not null
		Copy_Coefs(p2.coefs_, p2.n_);
		fmap_ = p2.fmap_;
	}
	return *this;
}

/*
bool polynom::operator!=(const polynom& p2) {
	if (n_ != p2.n_)
		return false;

	for (unsigned int i = 0; i <= p2.n_; i++) // p2.n_ and n_ same size
	{
		if (coefs_[i] != p2.coefs_[i])
			return false;
	}

	return true;
}*/

polynom::~polynom() {
	if (coefs_) delete[] coefs_;
}