#pragma once
#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Then.h"

namespace core {
	template <class T>
	class SugenoThen : public Then<T> {
	public:
		SugenoThen();
		virtual ~SugenoThen();
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;

		void updatePremiseValue(Expression<T> * p);

		T PremiseValue();

	private:
		T premiseValue;
	};

	template<class T>
	inline SugenoThen<T>::SugenoThen()
	{
	}

	template <class T>
	SugenoThen<T>::~SugenoThen()
	{}

	

	template<class T>
	void SugenoThen<T>::updatePremiseValue(Expression<T> * p)
	{
		premiseValue = p->evaluate();
	}

	template<class T>
	inline T SugenoThen<T>::PremiseValue()
	{
		return premiseValue;
	}

	

	template <class T>
	T SugenoThen<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const
	{
		T lev = l->evaluate();
		T revt = r->evaluate();
		premisevalue = lev * rev;
		return premisevalue;
	}

}



#endif 