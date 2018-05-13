#pragma once
#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H


#include <vector>
#include "Expression.h"
#include "NaryExpression.h"
namespace core
{
	template <class T>
	class NaryExpressionModel : public NaryExpression<T>, public Expression<T>
	{
	public:
		NaryExpressionModel() {};
		NaryExpressionModel(NaryExpression<T>* operateur, vector<const Expression<T>*>* operandes);
		virtual ~NaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(vector<const Expression<T>*>* operands) const;

	private:
		NaryExpression<T>* operateur;
		vector<const Expression<T>*>* operands;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel()
	{
	}

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* _operateur, typename vector<Expression<T>*> * _operands) :
		operateur(_operateur), operands(_operands)
	{
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (operands != NULL)
			return evaluate(operands);
		else
			throw std::exception();
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate(typename vector<Expression<T>*> * operands) const
	{
		if (operateur != NULL)
			return operateur->evaluate(operands);
		else
			throw std::exception();
	}
}

#endif //