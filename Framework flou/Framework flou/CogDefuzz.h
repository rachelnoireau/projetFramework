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
	
		virtual T Defuzz(const typename Evaluator<T>::Shape&) const;
	};

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

		// (somme des xi*yi) / (somme des yi)
		return std::accumulate(product.begin(), product.end(), sumProduct) / std::accumulate(s.second.begin(), s.second.end(), sumY);
	}
}

#endif

