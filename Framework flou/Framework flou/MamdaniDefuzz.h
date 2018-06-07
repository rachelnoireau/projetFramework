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

		MamdaniDefuzz() :min(0), max(25), step(1) {};
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