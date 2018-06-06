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

		/*void updatePremiseValue(Expression<T> * p);*/

		virtual T getPremiseValue();

	private:
		T premiseValue;
	};



	

	/*template<class T>
	void SugenoThen<T>::updatePremiseValue(Expression<T> * p)
	{
		premiseValue = p->evaluate();
	}*/

	template<class T>
	T SugenoThen<T>::getPremiseValue()
	{
		return premiseValue;
	}

	

	template <class T>
	T SugenoThen<T>::evaluate(Core::Expression<T>* l, Core::Expression<T>* r) const
	{
		T lev = l->evaluate();
		T rev = r->evaluate();
		premiseValue = lev * rev;
		return premiseValue;
	}

}



#endif 