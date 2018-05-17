#pragma once
#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "MamdaniDefuzz.h"

namespace Core {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	public:
		typedef pair<vector<T>, vector<T> > Shape;
		T Defuzz(Shape) const;
		//T evaluate(Expression<T>*, Expression<T>*) const;
		//Shape BuildShape(const T& min, const T& max, const T& step, EvalFunc& f) const;
		//setStep(const T&);
		//T getStep();

	private:
		T * step;
		T * min;
		T * max;

	};
	/*
	template<class T>
	CogDefuzz<T>::setStep(const T& st) {
		step = st;
	}*/

	/*
	template<class T>
	T CogDefuzz<T>::getStep() {
		return step;
	}*/

	template<class T>
	T CogDefuzz<T>::Defuzz(Shape shape) const
	{
		T exit = 0;
		for (int i = 0; i<shape.first.size; i++) {
			exit += (shape.first[i] + shape.second[i]) / shape.sencond[i];//dans defuzz
		}
		return exit;
	}

	


	 
/*
	template<class T>
	T CogDefuzz<T>::evaluate(Expression<T>*l, Expression<T>*r) const { 
		T left = l->evaluate();
		T right = r->evaluate();
		return defuzz(BuildShape(left,right)
	}
*/
	


}



#endif
