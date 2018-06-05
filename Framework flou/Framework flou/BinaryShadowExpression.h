#pragma once
#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H
#include "BinaryExpression.h"


namespace Core {
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
	
	public:
		BinaryShadowExpression(){}
		BinaryShadowExpression(BinaryExpression<T>* tar);
		~BinaryShadowExpression();

		virtual T evaluate(Core::Expression<T>*,Core::Expression<T>*) const;
		virtual BinaryExpression<T>* getTarget() const;
		virtual void setTarget(BinaryExpression<T>*);
	
	private:
		BinaryExpression<T>* target;
	};

	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* tar):
		target(tar)
	{}

	template<class T>
	BinaryShadowExpression<T>::~BinaryShadowExpression() 
	{
		delete target;
	}


	template<class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* e) {
		target = e;
	}

	template <class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() const {
		return target;
	}

	template <class T>
	T BinaryShadowExpression<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const {

		if (target != NULL) //throw nullptr;
			return target->evaluate(l, r);
		else 
			throw nullptr;
	}
}

#endif