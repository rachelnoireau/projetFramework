#ifndef THENMULT_H
#define THENMULT_H
#include "Then.h"
#include "Expression.h"

namespace Fuzzy {
	template <class T>
	class ThenMult : public Then<T> {
	public:
		ThenMult() {}
		virtual ~ThenMult() {}
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};



	template <class T>
	T ThenMult<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return lev * rev;
	}

}

#endif
