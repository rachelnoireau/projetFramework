#pragma once
#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "MamdaniDefuzz.h"

namespace Core {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	public:
		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
	};


}



#endif
