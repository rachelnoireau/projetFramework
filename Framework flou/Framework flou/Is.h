#pragma once
#ifndef IS_H
#define IS_H

#include "Expression.h"
#include "UnaryExpression.h"


template <class T>
class Is : public UnaryExpression<T> {

public:
	Is() {};
	virtual ~Is() {};
	virtual T evaluate(Core::Expression<T>*) const = 0;
};






#endif
