#pragma once
#ifndef NOT_H
#define NOT_H
#include "UnaryExpression.h"
#include "Expression.h"

namespace Fuzzy {
	template <class T>
	class Not : public UnaryExpression<T> {

	public:
		Not() {};
		virtual ~Not() {};
		virtual T evaluate(Core::Expression<T>*) const = 0;
	};

}




#endif
