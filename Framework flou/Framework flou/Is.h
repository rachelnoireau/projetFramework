#ifndef IS_H
#define IS_H

#include "UnaryExpression.h"

namespace Fuzzy
{
	template <class T>
	class Is : public Core::UnaryExpression<T>
	{
	public:
		Is() {};
		virtual ~Is() {};
		virtual T evaluate(Core::Expression<T>*) const = 0;
	};
}

#endif


