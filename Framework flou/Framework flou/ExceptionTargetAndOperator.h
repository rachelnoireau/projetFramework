#ifndef EXCEPTIONTARGETANDOPERATOR_H
#define EXCEPTIONTARGETANDOPERATOR_H

#include <exception>
using namespace std;

class ExceptionTargetAndOperator : public exception {
	public :
		ExceptionTargetAndOperator() throw() {}
};
#endif