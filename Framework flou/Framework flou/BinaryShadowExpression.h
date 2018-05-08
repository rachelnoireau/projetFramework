#pragma once
#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H
//#include "Not.h"


namespace Core {
	template <class T>
	class BinaryShadowExpression :: BinaryExpression {
	
	public:
		virtual T evaluate(Core::Expression<T>*,Core::Expression<T>*) const;
	};

	template <class T>
	T BinaryShadowExpression<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		T lev = l->evaluate();
		T rev = r->evaluate();
		return (lev < rev) ? lev : rev;
	}
}

#endif