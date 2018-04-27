#pragma once
#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H
#include "BinaryExpression.h"

namespace Core {
	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {
	public:
		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
	};


}



#endif
