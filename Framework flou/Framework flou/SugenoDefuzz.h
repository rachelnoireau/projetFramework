#pragma once
#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "NaryExpression.h"
#include "BinaryExpressionModel.h"
#include "BinaryShadowExpression.h"

namespace Core {

	template <class T>
	class SugenoDefuzz : public NaryExpression<T> {

	public:
		SugenoDefuzz() {};
		~SugenoDefuzz() {};

		T evaluate(std::vector<Expression<T>*> *operands) const;

	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(std::vector<Expression<T>*> *operands) const {
		std::vector<const Expression<T>*>::const_iterator it;
		T numerator = 0;
		T denominator = 0;

		for (it = operands->begin(); it != operands->end(); it++)
		{
			BinaryExpressionModel<T>*  bem = (BinaryExpressionModel<T>*)(*it);
			BinaryShadowExpression<T>* bse = (BinaryShadowExpression<T>*) bem->getOperator();
			SugenoThen<T>* sugThen = (SugenoThen<T>*)bse->getTarget();

			numerator += (*it)->evaluate();
			denominator += sugThen->PremiseValue();
		}

		if (denominator != 0)
			return numerator / denominator;
		else
			return 0;
	}



}


#endif