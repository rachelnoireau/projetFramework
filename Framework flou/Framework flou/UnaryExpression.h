#pragma once
#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

namespace Core {
	template <class T>
	class UnaryExpression {

	public:
		virtual T evaluate(Expression<T>*) const = 0;
	};
}





#endif
