#pragma once
#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H
#include "UnaryExpression.h"
#include "Expression.h"

namespace Core {
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {

	public:
		virtual T evaluate(Core::Expression<T>*) const;
		virtual UnaryExpression<T>* getTarget() const;
		virtual void setTarget(UnaryExpression<T>*);

	private:
		UnaryExpression<T> *target;
	};

	template <class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* e){
		target=e;
	}		
	
	template<class T>
	UnaryExpression<T>* UnaryShadowExpression<T>::getTarget() const
	{
			return target;
	}

/*
	template <class T>
	UnaryExpression<T>* UnaryShadowExpression<T>::getTarget() const {
		return target;
	}*/

	template <class T>
	T UnaryShadowExpression<T>::evaluate(Core::Expression<T>* o) const {
		if (target == NULL) throw NullOperatorException{
			return target.evaluate(o);
		}
	
	}


}
#endif