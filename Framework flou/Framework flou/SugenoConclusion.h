#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "NaryExpression.h"


namespace Fuzzy {

	template <class T>
	class SugenoConclusion : public Core::NaryExpression<T> {

	public:
		SugenoConclusion(std::vector<T>* coeff):coeff(coeff) {};
		~SugenoConclusion() {};

		T evaluate(std::vector<const Core::Expression<T>*>* operands) const;

	private:
		std::vector<T> *coeff;
	};


	template <class T>

	T SugenoConclusion<T>::evaluate(std::vector<const Core::Expression<T>*>* operands) const

	{
		std::vector<T>::const_iterator itcoef = coeff->begin();
		std::vector<const Core::Expression<T>*>::const_iterator itexpr = operands->begin();
		T result;
		result= 0;
		T eval;
		for (; itexpr != operands->end() && itcoef != coeff->end(); itexpr++, itcoef++)
		{
			eval = (*itexpr)->evaluate();
			result+= (*itcoef) * eval;
		}
		return result;
	}


}


#endif