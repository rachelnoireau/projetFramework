#pragma once
#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "NaryExpression.h"
#include "BinaryExpressionModel.h"
#include "BinaryShadowExpression.h"

namespace Fuzzy {

	template <class T>
	class SugenoDefuzz : public NaryExpression<T> {

	public:
		SugenoDefuzz() {};
		virtual ~SugenoDefuzz() {};

		virtual T evaluate(std::vector<const Core::Expression<T>*> *operands) const;

	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(std::vector<const Core::Expression<T>*> *operands) const {
		std::vector<const Core::Expression<T>*>::const_iterator it;
		T numerator = 0;
		T denominator = 0;

		for (it = operands->begin(); it != operands->end(); it++)
		{
			Core::BinaryExpressionModel<T>*  bem = (Core::BinaryExpressionModel<T>*)(*it);
			Core::BinaryShadowExpression<T>* bse = (Core::BinaryShadowExpression<T>*) bem->getOperator();
			SugenoThen<T>* sugThen = (SugenoThen<T>*)bse->getTarget();
			numerator += (*it)->evaluate();
			denominator += sugThen->getPremiseValue();
		}
		if (denominator != 0)
			return numerator / denominator;
		else
			return 0;
	}



}


#endif