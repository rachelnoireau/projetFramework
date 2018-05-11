#pragma once
#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "MamdaniDefuzz.h"

namespace Core {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	public:
		typedef pair<vector<T>, vector<T> > Shape;
		T evaluate(Expression<T>*, Expression<T>*) const;
		Shape BuildShape(const T& min, const T& max, const T& step, EvalFunc& f) const;
		setStep(const T&);
		T getStep();

	private:
		T * step;
		T * min;
		T * max;

	};
	template<class T>
	CogDefuzz<T>::setStep(const T& st) {
		step = st;
	}

	template<class T>
	T CogDefuzz<T>::getStep() {
		return step;
	}

	template<class T>
	 Shape CogDefuzz<T>::BuildShape(const T & min, const T & max, const T & step, EvalFunc & f) const
	{
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			y.push_back(f(i));
			x.push_back(i);
		}
		return Shape(x, y);
	}
	template<class T>
	T CogDefuzz<T>::evaluate(Expression<T>*l, Expression<T>*r) const { //figure et value model
		//T left = l->evaluate();
		T right = r->evaluate();
		T exit = 0;
		for (int i=0;i<left.first.size;i++){
			exit += (left.first[i] + left.second[i]) / left.sencond[i];//dans defuzz
		}
		r = exit; /////////////////////////////////////////////////////////////////////////

		defuzz(BuildShape(l,r)
		return exit;
	}

	


}



#endif
