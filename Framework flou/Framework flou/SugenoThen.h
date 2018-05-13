#pragma once
#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Then.h"

namespace fuzzy {
	template <class T>
	class SugenoThen : public Then<T> {
	public:
		SugenoThen();
		virtual ~SugenoThen();
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;

		T PremiseValue();

	private:
		T premiseValue;
	};

	template <class T>
	SugenoThen<T>::~SugenoThen()
	{}

	template <class T>
	T SugenoThen<T>::premiseValue() const
	{
		return this->premisevalue;
	}

	template <class T>
	T SugenoThen<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const
	{
		T lev = l->evaluate();
		T revt = r->evaluate();
		premisevalue = lev * rev;
		return premisevalue = lev * rev;
	}

}



#endif 