#pragma once
#ifndef NARY_SHADOW_EXPRESSION
#define NARY_SHADOW_EXPRESSION

#include <vector>
#include "NaryExpression.h"
#include "Expression.h"
#include "ExpressionException.h"

namespace Core {
	template<class T>
	class NaryShadowExpression : public NaryExpression<T>
	{
	public:
		NaryShadowExpression() {};
		NaryShadowExpression(NaryExpression<T> * e);
		virtual ~NaryShadowExpression() {};

		virtual T evaluate(vector<const Expression<T>*> * operands) const;

		void setTarget(NaryExpression<T> * e);
		NaryExpression<T> * getTarget() const;

	private:
		NaryExpression<T> * target;
	};

	
	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T> * e) :
		target(e)
	{}


	template<class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T> * e)
	{
		target = e;
	}

	template<class T>
	NaryExpression<T>* NaryShadowExpression<T>::getTarget() const
	{
		return target;
	}

	template<class T>
	T NaryShadowExpression<T>::evaluate(typename vector<const Expression<T>*> * operands) const
	{
		if (target == NULL)
			throw new ExpressionException("target null");
		return target->evaluate(operands);
	}




}

#endif