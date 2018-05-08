#pragma once
#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "MamdaniDefuzz.h"

namespace Core {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	public:
		virtual T evaluate(Expression<T>*, Expression<T>*);
	};


	template<class T>
	T CogDefuzz<T>::evaluate(Expression<T>*l, Expression<T>*r) {
		T left = l->evaluate();
		T right = r->evaluate();
	}


}



#endif
