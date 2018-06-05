#pragma once
#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H
#include "UnaryExpression.h"
#include "Expression.h"
#include "ExceptionTargetAndOperator.h"

namespace Core {
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {

	public:
		UnaryShadowExpression(){}
		UnaryShadowExpression(UnaryExpression<T> *);
		//~UnaryShadowExpression();

		virtual T evaluate(Core::Expression<T>*) const;
		virtual UnaryExpression<T>* getTarget() const;
		virtual void setTarget(UnaryExpression<T>*);

	private:
		UnaryExpression<T> *target;// = new UnaryExpression<T>();

	};
	template <class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T> * tar):
		target(tar)
	{}
	/*
	template <class T>
	UnaryShadowExpression<T>::~UnaryShadowExpression() {
		delete target;
	}*/

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
		if (target == NULL) throw new ExceptionTargetAndOperator(); //nullPointer
		return target->evaluate(o);//UnaryExpression<T>::
	
	}


}
#endif