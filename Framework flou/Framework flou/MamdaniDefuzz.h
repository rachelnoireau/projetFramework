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

		virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
		virtual T Defuzz(Shape) const = 0;
		Shape BuildShape(Expression<T>*, Expression<T>*) const ; //EvalFunc& f

		void setStep(const T&);
		T getStep() const;
		void setMin(const T&);
		T getMin() const;
		void setMax(const T&);
		T getMax() const;

		
	private:
		T  step;
		T  min;
		T  max;

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
	void MamdaniDefuzz<T>::setMin(const T& mini) {
		min = mini;
	}

	template<class T>
	T MamdaniDefuzz<T>::getMin() const {
		return min;
	}

	template<class T>
	void MamdaniDefuzz<T>::setMax(const T& maxi) {
		max = maxi;
	}

	template<class T>
	T MamdaniDefuzz<T>::getMax() const {
		return max;
	}

	template<class T>
	typename MamdaniDefuzz<T>::Shape MamdaniDefuzz<T>::BuildShape(Expression<T>* shapeEval, Expression<T>* e) const { //ici	EvalFunc& f
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			y.push_back(i);//Is<T>::evaluate(i)
			x.push_back(i);
		}
		return Shape(x, y);
	}
	
	/*
	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		T left = l->evaluate();
		T right = r->evaluate();
		return defuzz(BuildShape(left, right,step));
	}*/

}
#endif
