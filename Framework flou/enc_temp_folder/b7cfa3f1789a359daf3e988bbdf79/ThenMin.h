#pragma once
#ifndef THENMIN_H
#define THENMIN_H
#include "Then.h"
#include "Expression.h"

namespace Fuzzy {
	template <class T>
	class ThenMin : public Then<T> {
	public:
		ThenMin() {}
		virtual ~ThenMin() {}
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
		
		//template <class T>
		//ThenMin<T>::ThenMin() {
		//}
	};


	template <class T>
	T ThenMin<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return (lev < rev) ?  lev : rev;
	}
}



#endif
