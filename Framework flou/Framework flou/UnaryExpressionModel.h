
#pragma once
#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h"
#include "Expression.h"

namespace Core {
	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T>{ 
	public:
		UnaryExpressionModel(UnaryExpression<T>* ope, Expression<T>* o);

		T evaluate() const;
		T evaluate(Expression<T>*)const;
		Expression<T>* getOperand() const;
		UnaryExpression<T>* getOperator() const;
		void setOperand(Expression<T>*);
		void setOperator(UnaryExpression<T>*);
	private:
			Expression<T>* operand;
			UnaryExpression<T>* operatorVar;
	};


	template<class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* ope, Expression<T>* o) : operand(ope), operatorVar(o)
	{
	}

	template<class T>
	Expression<T>* UnaryExpressionModel<T>::getOperand()const {
		return operand;
	}
	template<class T>
	UnaryExpression<T>* UnaryExpressionModel<T>::getOperator()const {
		return operatorVar;
	}

	template<class T>
	void UnaryExpressionModel<T>::setOperand(Expression<T>* e) {
		operand = e;
	}

	template<class T>
	void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* e) {
		operatorVar = e;
	}

	

	template<class T>
	T UnaryExpressionModel<T>::evaluate() const {
		if (operand == NULL) throw NullOperatorException {

			return evaluate(operand);
		}
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const{
		if (operand == NULL) throw NullOperatorException{

			return operatorVar.evaluate(o);
		}
	}

}
#endif