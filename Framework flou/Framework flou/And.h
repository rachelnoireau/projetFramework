#ifndef AND_H
#define AND_H
#include "BinaryExpression.h"
using namespace Core;

namespace Fuzzy {
	template <class T>
	class And : public BinaryExpression<T> {
	public:
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const = 0; 
	};


}



#endif
