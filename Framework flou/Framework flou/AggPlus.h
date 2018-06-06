#ifndef AGGPLUS_H
#define AGGPLUS_H

#include "Agg.h"
#include "Expression.h"

namespace Fuzzy {
	template <class T>
	class AggPlus : public Agg<T> {
	public:
		AggPlus() {};
		virtual ~AggPlus() {};
		T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};


	template <class T>
	T AggPlus<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return rev + lev;
	}
}



#endif
