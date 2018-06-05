#pragma once
#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

namespace Core
{
	template <class T>
	class NaryExpression
	{
	public:

		NaryExpression() {};
		virtual ~NaryExpression() {};

		virtual T evaluate(vector<const Expression<T>*>*) const = 0;
	};
}

#endif