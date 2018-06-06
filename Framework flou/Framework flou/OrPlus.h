#ifndef ORPLUS_H
#define ORPLUS_H
#include "Or.h"
#include "Expression.h"

namespace Fuzzy {
	template <class T>
	class OrPlus : public Or<T> {
	public:
		OrPlus() {}
		virtual ~OrPlus() {}
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};


	


	template <class T>
	T OrPlus<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return rev + lev;
	}

}



#endif
