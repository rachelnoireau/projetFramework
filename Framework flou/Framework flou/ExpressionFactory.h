
#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "NaryExpressionModel.h"
#include <vector>

namespace Core
{
	template <class T>
	class ExpressionFactory
	{
	public:
		typedef vector<Expression<T>*> Memory;

		ExpressionFactory() {};
		virtual ~ExpressionFactory();

		Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
		Expression<T>* newNary(NaryExpression<T>*, std::vector<const Expression<T>*>*);
		
		Expression<T>* hold(Expression<T>*);

	private:
		Memory memory;
	};

	template <class T>
	ExpressionFactory<T>::~ExpressionFactory()
	{
		for (Memory::iterator it = memory.begin(); it != memory.end(); it++)
			delete *it;
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o)
	{
		return hold(new UnaryExpressionModel<T>(ope, o));
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r)
	{
		return hold(new BinaryExpressionModel<T>(ope, l, r));
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* ope, std::vector<const Expression<T>*>* operands)
	{
		return hold(new NaryExpressionModel<T>(ope, operands));
	}

	template <class T>
	Expression<T>* ExpressionFactory<T>::hold(Expression<T>* e)
	{
		memory.push_back(e);
		return e;
	}
}

#endif
