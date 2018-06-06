#ifndef AGGMAX_H
#define AGGMAX_H

#include "Agg.h"
#include "Expression.h"

namespace Fuzzy {
	template <class T>
	class AggMax : public Agg<T> {
	public:
		AggMax() {};
		virtual ~AggMax() {};
		T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};

	template <class T>
	T AggMax<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return (lev<rev) ? rev : lev;
	}


}



#endif
