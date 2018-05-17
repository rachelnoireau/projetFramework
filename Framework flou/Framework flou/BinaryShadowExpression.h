#pragma once
#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H
#include "BinaryExpression.h"
#include "Expression.h"

namespace Core {
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
	
	public:
		virtual T evaluate(Core::Expression<T>*,Core::Expression<T>*) const;
		virtual T getTarget() const;
		virtual void setTarget(BinaryExpression<T>*);
	
	private:
		BinaryExpression<T>* target;
	};

	template<class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* e) {
		target = e;
	}

	template <class T>
	T BinaryShadowExpression<T>::getTarget() const {
		return target;
	}

	template <class T>
	T BinaryShadowExpression<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {
		if (target == NULL) throw NullOperatorException{
			return operator.evaluate(l,r);
		}

	}
}

#endif