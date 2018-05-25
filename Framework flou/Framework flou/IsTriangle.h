#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H
#include "Is.h"

namespace Fuzzy {
	template <class T>
	class IsTriangle : public Is<T> {

	public:
		
		IsTriangle();
		IsTriangle(const T&,const T&,const T&);

		virtual T evaluate(Core::Expression<T>*) const;

		T getMin()const;
		T getMid()const;
		T getMax()const;
	private:
		T min, mid, max;
	/*
	template <class T>
	IsTriangle<T>::IsTriangle() : min(0), mid(1), max(2)
	{}
	*/
	
};

	template <class T>
	IsTriangle<T>::IsTriangle() : min(0), mid(0.5), max(1)
	{}

	template <class T>
	IsTriangle<T>::IsTriangle(const T& _min, const T& _mid, const T& _max) : min(_min), mid(_mid), max(_max)
	{}

	template <class T>
	T IsTriangle<T>::getMin() const { return min; }

	template <class T>
	T IsTriangle<T>::getMid() const { return mid; }

	template <class T>
	T IsTriangle<T>::getMax() const { return max; }
	
	template <class T>
	T IsTriangle<T>::evaluate(Core::Expression<T>* e) const {
		T eval = e->evaluate();
		if (eval < min) { return 0; }
		else if (eval < mid) {
			return (eval - min) / (mid - min);
		}
		else if (eval < max) {
			return (max - eval) / (max - mid);
		}
		else { return 0; }
	}

}

#endif
