#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "Expression.h"
#include "BinaryExpression.h"

namespace Core {
	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
	
	public:
		BinaryExpressionModel(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r);
		~BinaryExpressionModel();
		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		virtual Expression<T>* getLeft() const;
		virtual Expression<T>* getRight() const;
		virtual BinaryExpression<T>* getOperator() const;

	private:
		BinaryExpression<T> *op;
		Expression<T> *left, *right;	
	};

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r):
		op(ope), left(l), right(r){}
	/*
	template<class T>
	BinaryExpressionModel<T>::~BinaryExpressionModel() {
		delete op;
		delete left;
		delete right;
	}*/

	template <class T>
	Expression<T>* BinaryExpressionModel<T>::getLeft() const {
		return left;
	}

	template <class T>
	Expression<T>* BinaryExpressionModel<T>::getRight() const {
		return right;
	}

	template <class T>
	BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() const {
		return op;
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const {
		if (left == NULL) throw nullptr;
		if (right == NULL) throw nullptr;
		return evaluate(left, right);
	}

	template <class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* r,Expression<T>* l) const {
		if (op == NULL) throw new ExceptionTargetAndOperator();
		return op->evaluate(l,r);
		
	}
}



#endif