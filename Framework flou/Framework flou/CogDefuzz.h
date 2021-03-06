#pragma once
#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "stdafx.h"
#include <vector>
#include "MamdaniDefuzz.h"
#include <numeric>
#include <exception>

namespace Fuzzy
{
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T>
	{
	public:
		CogDefuzz() {};
		~CogDefuzz() {};
		CogDefuzz(const T&, const T&, const T&);
		virtual T Defuzz(const typename Evaluator<T>::Shape&) const;
	};

	template <class T>
	CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step) :
		MandaniDefuzz(_min, _max, _step)
	{}

	template <class T>
	T CogDefuzz<T>::Defuzz(const typename Evaluator<T>::Shape& s) const
	{
		std::vector<T> product;
		std::vector<T>::const_iterator itY = s.second.begin();
		std::vector<T>::const_iterator itX = s.first.begin();

		
		for (; itY != s.second.end(); ++itY, ++itX)
			product.push_back(*itX * *itY);

		T sumProduct = 0;
		T sumY = 0;
		
		T deno = std::accumulate(s.second.begin(), s.second.end(), sumY);
		//std::cout << "deno : "<< deno << std::endl;
		//if (deno == 0) throw exception();

		// (sum xi*yi) / (sum yi)
		return std::accumulate(product.begin(), product.end(), sumProduct) / std::accumulate(s.second.begin(), s.second.end(), sumY);
	}
}

#endif
