#pragma once
#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H


#include <vector>
#include "Expression.h"
#include "NaryExpression.h"
namespace Core
{
	template <class T>
	class NaryExpressionModel : public NaryExpression<T>, public Expression<T>
	{
	public:
		NaryExpressionModel() {};
		NaryExpressionModel(NaryExpression<T>* operateur, std::vector<Expression<T>*>* operandes) :operateur(operateur), operandes(operandes) {};
		virtual ~NaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(vector<Expression<T>*>*) const;

	private:
		NaryExpression<T>* operateur;
		vector<Expression<T>*>* operandes;
	};

	/*template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* _operateur, typename vector<Expression<T>*> * _operands) :
		operateur(_operateur), operands(_operands)
	{
	}*/

	template<class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (operandes != NULL)
			return evaluate(operandes);
		else
			throw std::exception();
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate(vector<Expression<T>*> * operands) const
	{
		if (operateur != NULL)
			return operateur->evaluate(operands);
		else
			throw std::exception();
	}
}

#endif //