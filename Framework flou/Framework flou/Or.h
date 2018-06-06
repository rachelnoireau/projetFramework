#ifndef OR_H
#define OR_H

#include "BinaryExpression.h"

namespace Fuzzy {
	template <class T>
	class Or : public BinaryExpression<T> {
	public:
		virtual ~Or() {};
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const = 0;
	};


}



#endif
