#pragma once
#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H
#include "MamdaniDefuzz.h"

namespace Fuzzy {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	public:
		CogDefuzz() {};
		CogDefuzz(T min, T max, T step);

		typedef pair<vector<T>, vector<T> > Shape;
		T Defuzz(Shape) const;
		T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;
		//Shape BuildShape(const T& min, const T& max, const T& step, EvalFunc& f) const;

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
	CogDefuzz<T>::CogDefuzz(T _min, T _max, T _step):
		min(_min) , max(_max) , step(_step)
		{}

	
	template<class T>
	void CogDefuzz<T>::setStep(const T& st) {
		step = st;
	}

	template<class T>
	T CogDefuzz<T>::getStep() const {
		return step;
	}

	template<class T>
	void CogDefuzz<T>::setMin(const T& mini) {
		min = mini;
	}

	template<class T>
	T CogDefuzz<T>::getMin() const {
		return min;
	}

	template<class T>
	void CogDefuzz<T>::setMax(const T& maxi) {
		max = maxi;
	}

	template<class T>
	T CogDefuzz<T>::getMax() const {
		return max;
	}


	template<class T>
	T CogDefuzz<T>::Defuzz(Shape shape) const
	{
		T exit = 0;
		for (unsigned int i = 0; i<shape.first.size(); i++) {
			exit += (shape.first[i] + shape.second[i]) / shape.second[i];//dans defuzz
		}
		return exit;
	}

	template<class T>
	T CogDefuzz<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const
	{
		//T left = l->evaluate();
		//T ri = r->evaluate();
		return Defuzz(MamdaniDefuzz<T>::BuildShape(l, (ValueModel<T>*) r, min, max, step));
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
