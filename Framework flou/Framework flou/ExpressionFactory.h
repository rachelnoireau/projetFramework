#pragma once
#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H
#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"

namespace Core {
	template <class T>
	class ExpressionFactory {

	public:
		Expression<T> Hold(Expression<T>*);
		Expression<T> newUnary(UnaryExpression<T>* ope, Expression<T>* o);
		Expression<T> newBinary(BinaryExpression<T>* ope, Expression<T>* l,Expression<T>* r);
	
	private:
		Expression<T> memory;
	};

	template<class T>
	Expression<T>  ExpressionFactory<T>::Hold(Expression<T>* e) {
		return e;///////////////////////////////////////////////////////////////////
	}


	template <class T>
	Expression<T> ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o){
		return new UnaryExpressionModel(ope, o);
	}

	template <class T>
	Expression<T> ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) {
		return new BinaryExpressionModel(ope, l, r);
	}
}
#endif