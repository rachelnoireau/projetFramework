#pragma once
#ifndef NOTMINUS1_H
#define NOTMINUS1_H
#include "Not.h"
#include "Expression.h"
#include "UnaryExpression.h"

namespace Fuzzy {
	template <class T>
	class NotMinus1 : public Not<T> {

	public:
		NotMinus1() {};
		virtual ~NotMinus1() {};
		T evaluate(Core::Expression<T>*) const;
	};

	template <class T>
	T NotMinus1<T>::evaluate(Core::Expression<T>* e) const {
		T eval = e->evaluate();
		return (1 - eval);
	};
}

#endif
