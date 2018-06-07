#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Then.h"

namespace Fuzzy {
	template <class T>
	class SugenoThen : public Then<T> {
	public:
		SugenoThen() :premiseValue(0) {};
		virtual ~SugenoThen() {};
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const;

		T getPremiseValue();


	private:
		mutable T premiseValue;
	};

	template<class T>
	T SugenoThen<T>::getPremiseValue() 
	{
		return premiseValue;
	}

	

	template <class T>
	T SugenoThen<T>::evaluate( Core::Expression<T>* l, Core::Expression<T>* r) const
	{
		premiseValue = l->evaluate();
		return premiseValue * r->evaluate();
	}

}



#endif 