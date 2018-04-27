#ifndef AGGPLUS_H
#define AGGPLUS_H

namespace Fuzzy {
	template <class T>
	class AggPlus : public Agg<T> {
	public:
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
	};


	template <class T>
	T AggPlus<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return rev + lev;
	}
}



#endif
