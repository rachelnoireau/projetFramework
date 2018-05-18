#pragma once
#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H
#include "Expression.h"
//#include "ExpressionModel.h"
#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"
#include "ExpressionFactory.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "Then.h"
#include "Agg.h"
#include "CogDefuzz.h"
#include "Not.h"
#include "Is.h"
#include "And.h"
#include "Or.h"

#include <set>

namespace Fuzzy {
	template <class T>
	class FuzzyFactory : public Core::ExpressionFactory<T> {

	public:
		//FuzzyFactory(UnaryShadowExpression<T>*, BinaryShadowExpression<T>*, BinaryShadowExpression<T>*, BinaryShadowExpression<T>*, BinaryShadowExpression<T>*);
		FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, MamdaniDefuzz<T>*);

		virtual Expression<T>* Hold(Expression<T>*);
		virtual Expression<T>* newUnary(UnaryExpression<T>* ope, Expression<T>* o);
		virtual Expression<T>* newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r);

		Core::Expression<T>* newAnd(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* newOr(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* newThen(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* newAgg(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* newDefuzz(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* newNot(Core::Expression<T>* o);
		Core::Expression<T>* newIs(Core::Expression<T>* r, Core::Expression<T>* l);///////?
		
		void changeAnd(And<T>* o);
		void changeOr(Or<T>* o);
		void changeThen(Then<T>* o);
		void changeAgg(Agg<T>* o);
		void changeDefuzz(MamdaniDefuzz<T>* o);////////cog ou mamdani
		void changeNot(Not<T>* o);
		void changeIs(Is<T>* o);

	private:
		//Core::BinaryShadowExpression<T>and, or , then, agg, defuzz;
		//Core::UnaryShadowExpression<T> not, is;
		Core::BinaryShadowExpression<T>* andVar;
		Core::BinaryShadowExpression<T>* orVar;
		Core::BinaryShadowExpression<T> then;
		Core::BinaryShadowExpression<T> agg;
		Core::BinaryShadowExpression<T> defuzz;
		Core::UnaryShadowExpression<T> notVar;
		Core::UnaryShadowExpression<T> is;

		std::set<Core::Expression<T>*> memory;
	};
	/*
	template<class T>
	FuzzyFactory<T>::FuzzyFactory(UnaryShadowExpression<T>* _not, BinaryShadowExpression<T>* _and, BinaryShadowExpression<T>* _or, BinaryShadowExpression<T>* _then, BinaryShadowExpression<T>* _defuzz) :
	andvar(_and), orVar(_or), then(_then), notVar(_not), defuzz(_defuzz)
	{	
	}
	*/
	
	template<class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or , Then<T>* _then, MamdaniDefuzz<T>* _defuzz)//:
	//andVar(_and), orVar(_or), then(_then), notVar(_not), defuzz(_defuzz)
	{
		changeAnd(_and);
		changeOr(_or);
		changeThen(_then);
		changeNot(_not);
		changeDefuzz(_defuzz);
	}

	template<class T>
	Expression<T>*  FuzzyFactory<T>::Hold(Expression<T>* e) {
		memory.insert(e);
		return e;
	}


	template <class T>
	Expression<T>* FuzzyFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o) {
		return Hold(new UnaryExpressionModel<T>(ope, o));
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) {
		return Hold(new BinaryExpressionModel<T>(ope, l, r));
	}


	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::newAnd(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(andVar, l, r);
	}
	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::newOr(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(orVar, l, r);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::newThen(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(then, l, r);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::newAgg(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(agg, l, r);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::newDefuzz(Core::Expression<T>* r, Core::Expression<T>* l) {
		return newBinary(defuzz, l, r);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::newNot(Core::Expression<T>* o) {
		return newUnary(notVar, o);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::newIs(Core::Expression<T>* l, Core::Expression<T>* r) {
		return newBinary(is, l, r);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>* o) {
		andVar.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>* o) {
		orVar.setTarget(o);
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
		notVar.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeIs(Is<T>* o) {
		is.setTarget(o);
	}
}
#endif