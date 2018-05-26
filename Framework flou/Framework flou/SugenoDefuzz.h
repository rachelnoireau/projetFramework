#pragma once
#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "NaryExpression.h"
#include "BinaryExpressionModel.h"
#include "BinaryShadowExpression.h"

namespace core {

	template <class T>
	class SugenoDefuzz : public NaryExpression<T> {

	public:
		SugenoDefuzz() = default;
		virtual ~SugenoDefuzz() = default;

		virtual T evaluate(std::vector<Expression<T>*> * operands) const;

	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(std::vector<Expression<T>*> *operands) const {
		/*typename std::vector<const Expression<T>*>::const_iterator it;
		T numerator = 0;
		T denominator = 0;

		for (it = operands->begin(); it != operands->end(); it++)
		{
			core::BinaryExpressionModel<T>*  bem = (core::BinaryExpressionModel<T>*)(*it);
			core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->getOperator();
			SugenoThen<T>* sugThen = (SugenoThen<T>*)bse->getTarget();

			numerator += (*it)->evaluate();
			denominator += sugThen->premiseValue();
		}

		if (den != 0)
			return num / den;
		else
			return 0;*/
	}



}


#endif