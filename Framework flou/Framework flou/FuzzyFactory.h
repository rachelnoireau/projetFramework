#pragma once
#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "Expression.h"
//#include "ExpressionModel.h"
#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"
#include "ExpressionFactory.h"
#include "And.h"
#include "Or.h"
#include "Then.h"
#include "Agg.h"
#include "CogDefuzz.h"
#include "Not.h"
#include "Is.h"

namespace Fuzzy {
	template <class T>
	class FuzzyFactory : public Core::ExpressionFactory<T> {

	public:
		FuzzyFactory<T>::FuzzyFactory(UnaryShadowExpression<T>* not, BinaryShadowExpression<T>* and, BinaryShadowExpression<T>* or , BinaryShadowExpression<T>* then, BinaryShadowExpression<T> defuzz);

		Core::Expression<T> newAnd(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T> newOr(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T> newThen(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T> newAgg(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T> newDefuzz(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T> newNot(Core::Expression<T>* o);
		Core::Expression<T> newIs(Core::Expression<T>* r, Core::Expression<T>* l);///////?

		void changeAnd(And<T>* o);
		void changeOr(Or<T>* o);
		void changeThen(Then<T>* o);
		void changeAgg(Agg<T>* o);
		void changeDefuzz(MamdaniDefuzz<T>* o);////////cog ou mamdani
		void changeNot(Not<T>* o);
		void changeIs(Is<T>* o);

	private:
		Core::BinaryShadowExpression<T> and, or, then, agg, defuzz;
		Core::UnaryShadowExpression<T> not, is;
	};

	template<class T>
	FuzzyFactory<T>::FuzzyFactory(UnaryShadowExpression<T> * not, BinaryShadowExpression<T>* and, BinaryShadowExpression<T>* or , BinaryShadowExpression<T>* then, BinaryShadowExpression<T> defuzz):
	and(and), or(or), then(then), not(not), defuzz(defuzz)
	{
		
	}

	template<class T>
	Core::Expression<T> FuzzyFactory<T>::newAnd(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(and, l, r);
	}
	template<class T>
	Core::Expression<T> FuzzyFactory<T>::newOr(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(or, l, r);
	}

	template<class T>
	Core::Expression<T> FuzzyFactory<T>::newThen(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(then, l, r);
	}

	template<class T>
	Core::Expression<T> FuzzyFactory<T>::newAgg(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(agg, l, r);
	}

	template<class T>
	Core::Expression<T> FuzzyFactory<T>::newDefuzz(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(defuzz, l, r);
	}

	template<class T>
	Core::Expression<T> FuzzyFactory<T>::newNot(Core::Expression<T>* o) {
		return newUnary(not, o);
	}

	template<class T>
	Core::Expression<T> FuzzyFactory<T>::newIs(Core::Expression<T>* l, Core::Expression<T>* r) {
		return newBinary(is, l, r);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>* o) {
		and.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>* o) {
		or.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(Then<T>* o) {
		then.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* o) {
		agg.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeDefuzz(MamdaniDefuzz<T>* o) {
		defuzz.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(Not<T>* o) {
		not.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeIs(Is<T>* o) {
		is.setTarget(o);
	}
}
#endif