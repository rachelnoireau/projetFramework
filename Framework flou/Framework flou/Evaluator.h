#pragma once
#ifndef EVALUATOR_H
#define EVALUATOR_H
//#include "Shape.h"
#include <vector>
using namespace std;
 
namespace Core {

	template <class T>
	class Evaluator {
	public:
		//virtual T evaluate() const = 0;
		//virtual T operator () (const T&) = 0;
		typedef pair<vector<T>, vector<T> > Shape;
		static Shape BuildShape(const T& min, const T& max, const T& step, EvalFunc&);
		//static ostream& PrintShape(ostream&, const Shape& s);
	};

	


	template <class T>
	typename Evaluator<T>::Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step, EvalFunc& f)
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