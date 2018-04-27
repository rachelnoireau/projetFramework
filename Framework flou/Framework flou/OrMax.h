#ifndef ORMAX_H
#define ORMAX_H
#include "Or.h"

namespace Fuzzy {
	template <class T>
	class OrMax : public Or<T> {
	public:
		//OrMax();
		~OrMax() {}
		T evaluate(Core::Expression<T>*, Core::Expression<T>*) const ;//=0
		
		//template <class T>
		//OrMax<T>::OrMax() {
		//}
	};
	
	


	template <class T>
	T OrMax<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return (lev<rev)?  rev : lev ;
	}
	
}



#endif
