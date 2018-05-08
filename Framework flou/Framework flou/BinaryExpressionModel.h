#pragma once
#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "Expression.h"
#include "BinaryExpression.h"

namespace Core {
	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T> {
	
	public:
		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		virtual T getLeft() const;
		virtual T getRight() const;
		virtual T getOperator() const;

	private:
		BinaryExpression<T> *op;
		Expression<T> *left, *right;	
	};

	template <class T>
	T BinaryExpressionModel<T>::getLeft() const {
		return left;
	}

	template <class T>
	T BinaryExpressionModel<T>::getRight() const {
		return right;
	}

	template <class T>
	T BinaryExpressionModel<T>::getOperator() const {
		return op;
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const {
		if (left == NULL)throw NullOperatorException
			return LeftExpressionException;
		if (right == NULL)throw NullOperatorException
			return RightExpressionException;
		return evaluate(left, right);
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* r,Expression<T>* l) const {
		if (op == NULL)throw NullOperatorException{
			return op.evaluate(l,r);
		}
	}
}



#endif