#ifndef ORMAX_H
#define ORMAX_H
#include "Or.h"
#include "Expression.h"

namespace Fuzzy {
	template <class T>
	class OrMax : public Or<T> {
	public:
		OrMax() {}
		virtual ~OrMax() {};
		T evaluate(Core::Expression<T>*, Core::Expression<T>*) const ;
		
	};

	template <class T>
	T OrMax<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return (lev<rev)?  rev : lev ;
	}
	
}



#endif
