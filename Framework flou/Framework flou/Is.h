#pragma once
#ifndef IS_H
#define IS_H
#include "UnaryExpression.h"


template <class T>
class Is : public UnaryExpression<T> {

public:
	virtual T evaluate(Core::Expression<T>*) const = 0;
};






#endif
