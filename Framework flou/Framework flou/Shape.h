#pragma once
#ifndef SHAPE_H
#define SHAPE_H

namespace Core {

	template <class T>
	class Shape {
	public:
		virtual T evaluate() const = 0;
	};

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
