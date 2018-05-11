#pragma once
#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H
#include "BinaryExpression.h"
#include <vector>
using namespace std;

namespace Core {
	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {
	public:
		
		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		typedef pair<vector<T>, vector<T> > Shape;
		virtual void Defuzz(Shape) const = 0;
		virtual Shape BuildShape(const T& min, const T& max, const T& step, EvalFunc& f) ;

	};	
	
	Shape MandaniDefuzz<T>::BuildShape(const T& min, const T& max, const T& step, EvalFunc& f) //ici
		{
			vector<T> x, y;
			for (T i = min; i <= max; i += step)
			{
				y.push_back(f(i));
				x.push_back(i);
			}
			return Shape(x, y);
		}
	


}
#endif
