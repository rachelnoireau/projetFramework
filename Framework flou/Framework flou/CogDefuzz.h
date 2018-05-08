#pragma once
#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "MamdaniDefuzz.h"

namespace Core {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	public:
		T evaluate(Expression<T>*, Expression<T>*) const;
	};


	template<class T>
	T CogDefuzz<T>::evaluate(Expression<T>*l, Expression<T>*r) const {
		T left = l->evaluate();
		T right = r->evaluate();


	}


}



#endif
