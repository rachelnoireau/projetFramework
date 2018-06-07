/*#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H
#include "BinaryExpression.h"
#include <vector>


namespace Fuzzy {
	template <class T>
	class MamdaniDefuzz : public BinaryExpression<T> {
	public:
		typedef pair<vector<T>, vector<T> > Shape;

		class EvalFunc
		{
		public:
			virtual T operator () (const T&) = 0;
		};*/
		
		//MamdaniDefuzz(T, T, T)

		/*virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
		virtual T Defuzz(Shape) const = 0;
		Shape BuildShape(Expression<T>*, ValueModel<T>*,T,T,T) const ;*/ //EvalFunc& f

		/*void setStep(const T&);
		T getStep() const;
		void setMin(const T&);
		T getMin() const;
		void setMax(const T&);
		T getMax() const;*/

	/*	
	private:
		T  step;
		T  min;
		T  max;*/
/*
	};*/
	/*
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
	*/

	/*template<class T>
	typename MamdaniDefuzz<T>::Shape MamdaniDefuzz<T>::BuildShape(Expression<T>* entre, ValueModel<T>* exit, T min, T max, T step ) const {
		vector<T> x, y;

		T memory = exit->evaluate();
		
		for (T i = min; i <= max; i += step)
		{
			//exit->setValue(&i);
			y.push_back(entre->evaluate());//Is<T>://i
			x.push_back(i);
		}
		exit->ValueModel<T>::SetValue(memory);

		return Shape(x, y);
	}
	*/
	/*
	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		T left = l->evaluate();
		T right = r->evaluate();
		return defuzz(BuildShape(left, right,step));
	}*/
/*
}
#endif*/

#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "Evaluator.h"

using namespace Core;

namespace Fuzzy
{
	template <class T>
	class MamdaniDefuzz : public Core::BinaryExpression<T>
	{
	public:
		typedef std::pair<std::vector<T>, std::vector<T>> Shape;

		MamdaniDefuzz() :min(0), max(0), step(0) {};
		MamdaniDefuzz(const T& min, const T& max, const T& step) : min(min), max(max), step(step) {};
		~MamdaniDefuzz() {};

		virtual void setMin(const T& _min) { min = _min; }
		virtual void setMax(const T& _max) { max = _max; }
		virtual void setStep(const T& _step) { step = _step; }

		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;

	
		virtual T Defuzz(const typename Evaluator<T>::Shape&) const = 0;

	private:
		T min, max, step;
	};

	template <class T>
	T MamdaniDefuzz<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const
	{
		Evaluator<T> e;
		Evaluator<T>::Shape s = e.BuildShape(min, max, step, (Core::ValueModel<T>*) l, r);

		return Defuzz(s);
	}
}

#endif