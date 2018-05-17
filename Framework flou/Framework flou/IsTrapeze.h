
#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H
#include "Is.h"

namespace Fuzzy {
	template <class T>
	class IsTrapeze : public Is<T> {

	public:
		IsTrapeze();
		IsTrapeze(T, T, T, T);

		virtual T getMin()const;
		virtual T getMid1()const;
		virtual T getMid2()const;
		virtual T getMax()const;


		virtual T evaluate(Expression<T>*) const;

	private:
		 T min, mid1, mid2, max; /////peut etre change nom

	};

	template <class T>
	IsTrapeze<T>::IsTrapeze(T _min, T _mid1, T _mid2, T _max) : min(_min), mid1(_mid1), mid2(_mid2), max(_max)
	{ }

	template <class T>
	IsTrapeze<T>::IsTrapeze() : min(0), mid1(1), mind2(2), max(3)
	{ }

	template <class T>
	T IsTrapeze<T>::getMin() const { return min; }

	template <class T>
	T IsTrapeze<T>::getMid1() const { return mid1; }

	template <class T>
	T IsTrapeze<T>::getMid2() const { return mid2; }

	template <class T>
	T IsTrapeze<T>::getMax() const { return max; }



	template <class T>
	T IsTrapeze<T>::evaluate(Core::Expression<T>* e) const {
		T eval = e->evaluate(); /////// pas sûre
		if (eval < min) { return 0; }
		else if (eval < mid1) {
			return (eval - min) / (mid1 - min);
		}
		else if (eval < mid2) { return 1; }
		else if (eval < max) {
			return (max - eval) / (max - mid2);
		}
		else { return 0; }
	};

}

#endif