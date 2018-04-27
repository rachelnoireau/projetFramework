#ifndef ANDMIN_H
#define ANDMIN_H
#include "And.h"

namespace Fuzzy {
	template <class T>
	class AndMin : public And<T> {
	public:
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template <class T>
	T AndMin<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return (lev < rev) ? lev : rev;
	}
}
#endif