#pragma once
#ifndef VALUEMODEL_H
#define VALUEMODEL_H
#include "Expression.h"

namespace Core {

	template <class T>
	class ValueModel : public Expression<T> {
	public:
		ValueModel() {};
		virtual ~ValueModel() {};
		ValueModel(T _value);
		T evaluate() const;
		void SetValue(const T&);

	private:
		T value;
	};


	template<class T>
	ValueModel<T>::ValueModel(T _value) : value(_value)
	{
	}

	template<class T>
	T ValueModel<T>::evaluate() const
	{
		return value;
	}


	template<class T>
	void ValueModel<T>::SetValue(const T& _value)
	{
		value = _value;
	}


}



#endif
