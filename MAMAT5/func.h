#ifndef _FUNC_H_
#define _FUNC_H_
#include <map>
#include <iostream>



using std::map;
using std::ostream;


class func {

public:
	func& operator<<(const int& x);
//	ostream& operator<<(ostream& ro, const func&);


 protected:
   
  
  int maxVal_; //maximum of all inputs
  int minVal_; //minimum of all inputs
  map<int,int> fmap_; //holds inputs and corresponding outputs
  void plot(ostream& os) const ; //plot fmap_
};


#endif
