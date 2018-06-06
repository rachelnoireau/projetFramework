#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Then.h"

namespace Fuzzy {
	template <class T>
	class SugenoThen : public Then<T> {
	public:
		SugenoThen() {};
		virtual ~SugenoThen() {};
		virtual T evaluate(Expression<T>*, Expression<T>*) const;

		virtual T getPremiseValue();

	private:
		mutable T premiseValue;
	};

	template<class T>
	T SugenoThen<T>::getPremiseValue()
	{
		return premiseValue;
	}

	

	template <class T>
	T SugenoThen<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const
	{
		premiseValue = l->evaluate();
		return premiseValue * r->evaluate();
	}

}



#endif 