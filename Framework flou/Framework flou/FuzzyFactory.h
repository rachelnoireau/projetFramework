#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "Is.h"
#include "Not.h"
#include "And.h"
#include "Or.h"
#include "Then.h"
#include "Agg.h"
#include "SugenoConclusion.h"

#include "MamdaniDefuzz.h"
#include "SugenoDefuzz.h"

#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"
#include "NaryShadowExpression.h"


namespace Fuzzy
{
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T>
	{
	public:
		FuzzyFactory() {};
		FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, CogDefuzz<T>*);
		FuzzyFactory(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, CogDefuzz<T>*, SugenoDefuzz<T>*, SugenoConclusion<T>*);
		virtual ~FuzzyFactory();

		virtual Expression<T>* newNot(Expression<T>*);
		virtual Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newOr(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newThen(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		virtual Expression<T>* newDefuzz(Expression<T>*, Expression<T>* , const T&, const T&, const T&);
		virtual Expression<T>* newIs(Is<T>*, Expression<T>*);
		virtual Expression<T>* newSugeno(std::vector<const Expression<T>*>*);
		virtual Expression<T>* newConclusion(std::vector<const Expression<T>*>*);

		Expression<T>* changeNot(Not<T>*);
		Expression<T>* changeAnd(And<T>*);
		Expression<T>* changeOr(Or<T>*);
		Expression<T>* changeThen(Then<T>*);
		Expression<T>* changeAgg(Agg<T>*);
		Expression<T>* changeDefuzz(MamdaniDefuzz<T>*);
		Expression<T>* changeSugeno(SugenoDefuzz<T>*);
		Expression<T>* changeConclusion(SugenoConclusion<T>*);

	private:
		Core::UnaryShadowExpression<T>  notVar;
		Core::BinaryShadowExpression<T> andVar;
		Core::BinaryShadowExpression<T> orVar ;
		Core::BinaryShadowExpression<T> then;
		Core::BinaryShadowExpression<T> agg;
		Core::BinaryShadowExpression<T> defuzz;
		Core::NaryShadowExpression<T> sugeno;
		Core::NaryShadowExpression<T>   conclusion;
	};

	template <class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, CogDefuzz<T>* _defuzz)
	{
		notVar = new Core::UnaryShadowExpression<T>(_not);
		andVar = new Core::BinaryShadowExpression<T>(_and);
		orVar = new Core::BinaryShadowExpression<T>(_or);
		then = new Core::BinaryShadowExpression<T>(_then);
		agg = new Core::BinaryShadowExpression<T>(_agg);
		defuzz = new Core::BinaryShadowExpression<T>(_defuzz);
	}
	
	template <class T>
	FuzzyFactory<T>::FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, CogDefuzz<T>* _defuzz, SugenoDefuzz<T>* _sugeno, SugenoConclusion<T>* _conclusion):
		notVar(_not),andVar(_and),orVar(_or),then(_then),agg(_agg),defuzz(_defuzz),sugeno(_sugeno),conclusion(_conclusion)
	{	/*
		notVar = new Core::UnaryShadowExpression<T>(_not);
		andVar = new Core::BinaryShadowExpression<T>(_and);
		orVar = new Core::BinaryShadowExpression<T>(_or);
		then = new Core::BinaryShadowExpression<T>(_then);
		agg = new Core::BinaryShadowExpression<T>(_agg);
		defuzz = new Core::BinaryShadowExpression<T>(_defuzz);
		sugeno = new Core::NaryShadowExpression<T>(_sugeno);
		conclusion = new Core::NaryShadowExpression<T>(_conclusion);
		*/
	}

	template <class T>
	FuzzyFactory<T>::~FuzzyFactory()
	{	/*
		delete notVar;
		delete andVar;
		delete orVar ;
		delete then;
		delete agg;
		delete defuzz;
		delete sugeno;
		delete conclusion;*/
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newNot(Core::Expression<T>* o)
	{
		return ExpressionFactory<T>::newUnary(&notVar, o);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newAnd(Core::Expression<T>* l, Core::Expression<T>* r)
	{
		return ExpressionFactory<T>::newBinary(&andVar, l, r);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newOr(Core::Expression<T>* l, Core::Expression<T>* r)
	{
		return ExpressionFactory<T>::newBinary(&orVar , l, r);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newThen(Core::Expression<T>* l, Core::Expression<T>* r)
	{
		return ExpressionFactory<T>::newBinary(&then, l, r);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newAgg(Core::Expression<T>* l, Core::Expression<T>* r)
	{
		return ExpressionFactory<T>::newBinary(&agg, l, r);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newDefuzz(Core::Expression<T>* l, Core::Expression<T>* r, const T& min, const T& max, const T& step)
	{	
		/*
		CogDefuzz<T>* target = (CogDefuzz<T>*) defuzz->getTarget();
		target->setMin(min);
		target->setMax(max);
		target->setStep(step);
		*/
		return ExpressionFactory<T>::newBinary(&defuzz, l, r);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newIs(Is<T>* s, Core::Expression<T>* o)
	{
		return ExpressionFactory<T>::newUnary(s, o);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newSugeno(std::vector<const Core::Expression<T>*>* operands)
	{
		return ExpressionFactory<T>::newNary(&sugeno, operands);
	}

	template <class T>
	Core::Expression<T>* FuzzyFactory<T>::newConclusion(std::vector<const Core::Expression<T>*>* operands)
	{
		return ExpressionFactory<T>::newNary(&conclusion, operands);
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::changeNot(Not<T>* _not)
	{
		notVar->setTarget(_not);
		return this;
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::changeAnd(And<T>* _and)
	{
		andVar->setTarget(_and);
		return this;
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::changeOr(Or<T>* _or)
	{
		orVar ->setTarget(_or);
		return this;
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::changeThen(Then<T>* _then)
	{
		then->setTarget(_then);
		return this;
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::changeAgg(Agg<T>* _agg)
	{
		agg->setTarget(_agg);
		return this
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::changeDefuzz(MamdaniDefuzz<T>* _defuzz)
	{
		defuzz->setTarget(_defuzz);
		return this
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::changeSugeno(SugenoDefuzz<T>* _sugeno)
	{
		sugeno->setTarget(_sugeno);
		return this
	}

	template <class T>
	Expression<T>* FuzzyFactory<T>::changeConclusion(SugenoConclusion<T>* _conclusion)
	{
		conclusion->setTarget(_conclusion);
		return this
	}
}

#endif
