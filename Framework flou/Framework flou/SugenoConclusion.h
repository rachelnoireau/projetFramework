#pragma once
#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "SugenoDefuzz.h"
#include "NaryExpression.h"
#include "BinaryExpressionModel.h"
#include "BinaryShadowExpression.h"

namespace core {

	template <class T>
	class SugenoConclusion : public NaryExpression<T> {

	public:
		SugenoConclusion(const std::vector<T>);
		virtual ~SugenoConclusion();

		virtual T evaluate(std::vector<Expression<T> >) const;

	private:
		std::vector<T> coeff;
	};

	template<class T>
	inline SugenoConclusion<T>::SugenoConclusion(const std::vector<T> coef) : coeff(coef)
	{
	}

	template<class T>
	inline SugenoConclusion<T>::~SugenoConclusion()
	{
		delete[] coeff;
	}

	template<class T>
	T SugenoConclusion<T>::evaluate(std::vector<Expression<T> > vector) const {
		/*T sum;
		typename std::vector<T>::const_iterator it = vector.begin();
		for (; it != vector.end(); ++it)
			coeff.push_back(vector[it]);

		it = coeff.begin();
		for (; it != coeff.end(); ++it)
			sum += coeff[it];

		return sum;*/
	}

}


#endif