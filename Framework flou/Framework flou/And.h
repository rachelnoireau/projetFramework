#ifndef AND_H
#define AND_H
#include "BinaryExpression.h"


namespace Fuzzy {
	template <class T>
	class And : public BinaryExpression<T> {
	public:
		virtual ~And() {};
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const = 0; 
	};


}



#endif
