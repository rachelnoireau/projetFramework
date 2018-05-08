#pragma once
#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "Expression.h"
#include "BinaryExpression.h"

namespace Core {
	template <class T>
	class BinaryExpressionModel :: {
	private:
		BinaryExpression<T> *op;
		Expression<T> *left, *right;
	
	public:
		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		virtual T getLeft();
		virtual T getRight();

	};
	template <class T>
	T BinaryExpressionModel<T>::evaluate() const {
		if (left == NULL)
			return LeftExpressionException;
		if (right == NULL)
			return RightExpressionException;
	}

}



#endif