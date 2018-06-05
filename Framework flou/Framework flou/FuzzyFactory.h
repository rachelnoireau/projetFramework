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
#include "SugenoDefuzz.h"
#include "SugenoConclusion.h"


#include <set>

namespace Fuzzy {
	template <class T>
	class FuzzyFactory : public Core::ExpressionFactory<T> {

	public:
		//FuzzyFactory(UnaryShadowExpression<T>*, BinaryShadowExpression<T>*, BinaryShadowExpression<T>*, BinaryShadowExpression<T>*, BinaryShadowExpression<T>*);
		FuzzyFactory() {};
		~FuzzyFactory();
		FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, MamdaniDefuzz<T>*);
		FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, MamdaniDefuzz<T>*, SugenoDefuzz<T>*, SugenoConclusion<T>*);

		virtual Expression<T>* Hold(Expression<T>*);
		virtual Expression<T>* NewUnary(UnaryExpression<T>* ope, Expression<T>* o);
		virtual Expression<T>* NewBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r);

		Core::Expression<T>* NewAnd(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* NewOr(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* NewThen(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* NewAgg(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* NewDefuzz(Core::Expression<T>* r, Core::Expression<T>* l);
		Core::Expression<T>* NewDefuzz(Core::Expression<T>* r, Core::Expression<T>* l, T, T, T);
		Core::Expression<T>* NewNot(Core::Expression<T>* o);
		Core::Expression<T>* NewIs( Is<T>* i,Core::Expression<T>*o);
		Core::Expression<T>* NewSugeno(std::vector<Core::Expression<T>*>*);
		Core::Expression<T>* NewConclusion(std::vector<Core::Expression<T>*>*);
		
		void changeAnd(And<T>* o);
		void changeOr(Or<T>* o);
		void changeThen(Then<T>* o);
		void changeAgg(Agg<T>* o);
		void changeDefuzz(MamdaniDefuzz<T>* o);
		void changeNot(Not<T>* o);
		//void changeIs(Is<T>* o);

	private:
		//Core::BinaryShadowExpression<T>and, or , then, agg, defuzz;
		//Core::UnaryShadowExpression<T> not, is;
		Core::BinaryShadowExpression<T> andVar;
		Core::BinaryShadowExpression<T> orVar;
		Core::BinaryShadowExpression<T> then;
		Core::BinaryShadowExpression<T> agg;
		Core::BinaryShadowExpression<T> defuzz;
		Core::UnaryShadowExpression<T> notVar;
		//Core::UnaryShadowExpression<T>* is;

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
	FuzzyFactory<T>::FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or , Then<T>* _then, MamdaniDefuzz<T>* _defuzz):
	andVar(_and), orVar(_or), then(_then), notVar(_not), defuzz(_defuzz)
	{
	
	}

	template<class T>
	FuzzyFactory<T>::~FuzzyFactory() {
	
	}

	template<class T>
	Expression<T>*  FuzzyFactory<T>::Hold(Expression<T>* e) {
		memory.insert(e);
		return e;
	}


	template <class T>
	Expression<T>* FuzzyFactory<T>::NewUnary(UnaryExpression<T>* ope, Expression<T>* o) {
		return Hold(new UnaryExpressionModel<T>(ope, o));
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::NewBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) {
		return Hold(new BinaryExpressionModel<T>(ope, l, r));
	}


	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewAnd(Core::Expression<T>* r, Core::Expression<T>* l) {
		return NewBinary(&andVar, l, r);
	}
	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewOr(Core::Expression<T>* r, Core::Expression<T>* l) {
		return NewBinary(&orVar, l, r);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewThen(Core::Expression<T>* r, Core::Expression<T>* l) {
		return NewBinary(&then, l, r);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewAgg(Core::Expression<T>* r, Core::Expression<T>* l) {
		return NewBinary(&agg, l, r);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewDefuzz(Core::Expression<T>* r, Core::Expression<T>* l) {
		return NewBinary(&defuzz, l, r);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewDefuzz(Core::Expression<T>* r, Core::Expression<T>* l, T min, T max, T step) {
		//defuzz.setMin(min);
		//defuzz.setMax(max);
		//defuzz.setStep(step);
		NewBinary(&defuzz, l, r)
		return NewBinary(&defuzz, l, r); //, min, max, step
		
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewNot(Core::Expression<T>* o) {
		return NewUnary(&notVar, o);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::NewSugeno(std::vector<Core::Expression<T>*>* operands)
	{
		return NewNary(sugeno, operands);
	}

	template<class T>
	Core::Expression<T>* FuzzyFactory<T>::NewIs(Is<T>* is, Core::Expression<T>* o) {
		return NewUnary(is, o);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::NewConclusion(std::vector<Core::Expression<T>*>* operands)
	{
		return NewNary(conclusion, operands);
	}


	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>* o) {
		this->andVar->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>* o) {
		orVar->setTarget(o);
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
	/*
	template<class T>
	void FuzzyFactory<T>::changeIs(Is<T>* o) {
		is.setTarget(o);
	}*/
}
#endif