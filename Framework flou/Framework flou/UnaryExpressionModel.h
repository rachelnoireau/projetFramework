
#pragma once
#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

namespace Core {
	template <class T>
	class UnaryExpressionModel : UnaryExpression<T> {
	public:
		T evaluate() const;
		T evaluate(Expression<T>*)const;
		Expression<T> getOperand() const;
		UnaryExpression<T>* getOperator() const;
		void setOperand(Expression<T>*);
		void setOperator(UnaryExpression<T>*);
	private:
			Expression<T> operand;
			UnaryExpression<T> operator;
	};

	template<class T>
	Expression<T> UnaryExpressionModel<T>::getOperand()const {
		return operand;
	}
	template<class T>
	UnaryExpression<T> UnaryExpressionModel<T>::getOperator()const {
		return operator;
	}

	template<class T>
	void UnaryExpressionModel<T>::setOperand(Expression<T>* e) {
		operand = e;
	}

	template<class T>
	void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* e) {
		operator = e;
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

			return operator.evaluate(o);
		}
	}

}
#endif