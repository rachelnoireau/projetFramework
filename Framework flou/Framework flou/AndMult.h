#ifndef ANDMULT_H
#define ANDMULT_H
#include "And.h"
#include "Expression.h"

namespace Fuzzy {
	template <class T>
	class AndMult : public And<T> {
	public:
		AndMult() {};
		virtual ~AndMult() {};
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template <class T>
	T AndMult<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return lev * rev;
	}
}



#endif
