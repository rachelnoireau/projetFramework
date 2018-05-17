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
		typedef pair<vector<T>, vector<T> > Shape;

		class EvalFunc
		{
		public:
			virtual T operator () (const T&) = 0;
		};


		virtual T evaluate(Expression<T>*, Expression<T>*) const;
		virtual T Defuzz(Shape) const = 0;
		Shape BuildShape(const T& min, const T& max, const T& step, EvalFunc& f) ;

		void setStep(const T&);
		T getStep() const;

		
	private:
		T * step;
		T * min;
		T * max;

	};
	template<class T>
	void MamdaniDefuzz<T>::setStep(const T& st) {
		step = st;
	}

	template<class T>
	T MamdaniDefuzz<T>::getStep() const {
		return step;
	}


	template<class T>
	MamdaniDefuzz<T>::Shape MamdaniDefuzz<T>::BuildShape(const T& min, const T& max, const T& step, EvalFunc& f){ //ici
	
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			y.push_back(f(i));
			x.push_back(i);
		}
		return Shape(x, y);
	}
	


	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		T left = l->evaluate();
		T right = r->evaluate();
		return defuzz(BuildShape(left, right));
	}


}
#endif
