#ifndef _FUNC_H_
#define _FUNC_H_

#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using std::map;
using std::ostream;
using std::string;

class func {

public:
	func& operator<<(const int& x); // asign value of x into f(x)
	friend ostream& operator<<(ostream& ro, const func& f);

	virtual ~func();

 protected:
   
  
  int maxVal_; //maximum of all inputs
  int minVal_; //minimum of all inputs
  map<int,int> fmap_; //holds inputs and corresponding outputs
  void plot(ostream& os) const ; //plot fmap_

 
  virtual int Func_output(const int& x) = 0; // pure virtual
  virtual void Print_Func(ostream& ro) const = 0; //constant function of virtual print function.
};


#endif
