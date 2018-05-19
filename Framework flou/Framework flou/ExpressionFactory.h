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
		~ExpressionFactory();
		virtual Expression<T>* Hold(Expression<T>*)=0;
		virtual Expression<T>* newUnary(UnaryExpression<T>* ope, Expression<T>* o)=0;
		virtual Expression<T>* newBinary(BinaryExpression<T>* ope, Expression<T>* l,Expression<T>* r)=0;
	
	private:
		Expression<T>* memory;
	};

	template<class T>
	ExpressionFactory<T>::~ExpressionFactory() {
		delete memory;/////////////////////////////////////////////////////////////////////
	}

	/*
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
	*/

}
#endif