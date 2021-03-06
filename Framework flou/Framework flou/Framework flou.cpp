// Framework flou.cpp : définit le point d'entrée pour l'application console.
#include <iostream>
#include "Expression.h"
#include "UnaryExpression.h"
#include "ValueModel.h"
//#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "AggMax.h"
#include "AggPlus.h"
#include "AndMin.h"
#include "AndMult.h"
#include "IsTriangle.h"
#include "IsTrapeze.h"
#include "NotMinus1.h"
#include "OrMax.h"
#include "OrPlus.h"
#include "ThenMin.h"
#include "ThenMult.h"
#include "CogDefuzz.h"
#include "FuzzyFactory.h"
#include "SugenoThen.h"
#include "SugenoDefuzz.h"
#include "SugenoConclusion.h"

//#include "Framework flou.h"


using namespace Core;
using namespace Fuzzy;

/*int main()
{

	ValueModel<float> test1(10.0);
	ValueModel<float> test2(4.0);
	ValueModel<float> test3(0.75);
	ValueModel<float> test4(1.75);
	ValueModel<float> test5(2.75);

	std::cout << "Valeur1 " <<test1.evaluate() << std::endl;
	std::cout << "Valeur2 " << test2.evaluate() << std::endl;
	AndMin<float> minAnd;
	std::cout << "Andmin " << minAnd.evaluate(&test1, &test2) << std::endl;
	AndMult<float> multAnd;
	std::cout << "Andmult " << multAnd.evaluate(&test1, &test2) << std::endl;
	
	OrMax<float> maxOr;
	std::cout << "Ormax " << maxOr.evaluate(&test1, &test2) << std::endl;
	OrPlus<float> plusOr;
	std::cout << "Orplus " << plusOr.evaluate(&test1, &test2) << std::endl;

	ThenMin<float> minThen;
	std::cout << "ThenMin " << minThen.evaluate(&test1, &test2) << std::endl;
	ThenMult<float> multThen;
	std::cout << "ThenMult " << multThen.evaluate(&test1, &test2) << std::endl;

	AggMax<float> maxAgg;
	std::cout << "AggMax " << maxAgg.evaluate(&test1, &test2) << std::endl;
	AggPlus<float> plusAgg;
	std::cout << "AggPlus " << plusAgg.evaluate(&test1, &test2) << std::endl;

	NotMinus1<float> minusUn;
	std::cout << "NotMinus " << minusUn.evaluate(&test1) << std::endl;

	std::cout << std::endl;

	IsTriangle<float> tri(0.0, 1.0, 2.0);
	std::cout << "triangle :" << " min " << tri.getMin() << " mid " << tri.getMid() << " max " << tri.getMax() <<std::endl;
	std::cout << tri.evaluate(&test3) << std::endl;
	std::cout << tri.evaluate(&test4) << std::endl;

	IsTrapeze<float> tra(0.0, 1.0, 2.0 ,3.0);
	std::cout << "trapeze :" << " min " << tra.getMin() << " mid1 " << tra.getMid1() << " mid2 " << tra.getMid2() << " max " << tra.getMax() << std::endl;
	std::cout << tra.evaluate(&test3) << std::endl;
	std::cout << tra.evaluate(&test4) << std::endl;
	std::cout << tra.evaluate(&test5) << std::endl;

	std::cout << std::endl;

	CogDefuzz<float> cog(0, 25, 1);
	//std::cout << "Cog " << cog.setStep(0.1) << std::endl;
	//maxAgg.evaluate(tri, tra);
	//std::cout << "Cog " << cog.evaluate(&test1, &test2) << std::endl;
	//std::cout << "Cog " << cog.BuildShape() << std::endl;


	std::cout << "test du cours" << std::endl;

	FuzzyFactory<float> f(&minusUn, &minAnd, &maxOr, &minThen, &cog);

	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);

	IsTriangle<float> cheap(0, 5, 10);
	IsTriangle<float> average(10, 15, 20);
	IsTriangle<float> generous(20, 25, 30);

	ValueModel<float> service(0);
	ValueModel<float> food(0);
	ValueModel<float> tips(0);

	Expression<float> *r =
		f.NewAgg(
			f.NewAgg(
				f.NewThen(
					f.NewIs( &poor, &service),
					f.NewIs(&cheap,&tips)
				),
				f.NewThen(
					f.NewIs(&good, &service),
					f.NewIs(&average, &tips)
				)
			),
			f.NewThen(
				f.NewIs(&excellent,&service),
				f.NewIs(&generous, &tips)
			)
		);

	Expression<float> *system = f.NewDefuzz(&tips, r); //, 0, 25, 1 min max step

	float s;
	while (true)
	{
		std::cout << "service : "; std::cin >> s;
		service.SetValue(s);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}

    return 0;
}*/

void testMamdani()
{
	//operators
	Fuzzy::NotMinus1<float>         opNot;
	Fuzzy::AndMin<float>           opAnd;
	Fuzzy::OrMax<float>            opOr;
	Fuzzy::ThenMin<float>          opThen;
	Fuzzy::AggPlus<float>          opAgg;
	Fuzzy::CogDefuzz<float>        opDefuzz;

	//fuzzy expression factory
	Fuzzy::FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);

	//membership function
	//service
	Fuzzy::IsTriangle<float> poor(-5, 0, 5);
	Fuzzy::IsTriangle<float> good(0, 5, 10);
	Fuzzy::IsTriangle<float> excellent(5, 10, 15);
	//food
	Fuzzy::IsTriangle<float> rancid(-5, 0, 5);
	Fuzzy::IsTriangle<float> delicious(5, 10, 15);
	//tips
	Fuzzy::IsTriangle<float> cheap(0, 5, 10);
	Fuzzy::IsTriangle<float> average(10, 15, 20);
	Fuzzy::IsTriangle<float> generous(20, 25, 30);

	//values
	Core::ValueModel<float> service(0);
	Core::ValueModel<float> food(0);
	Core::ValueModel<float> tips(0);

	Core::Expression<float> *r =
		f.newAgg(
			f.newAgg(
				f.newThen(
					f.newOr(
						f.newIs(&poor, &service),
						f.newIs(&rancid, &food)
					),
					f.newIs(&cheap, &tips)
				),
				f.newThen(
					f.newIs(&good, &service),
					f.newIs(&average, &tips)
				)
			),
			f.newThen(
				f.newOr(
					f.newIs(&excellent, &service),
					f.newIs(&delicious, &food)
				),
				f.newIs(&generous, &tips)
			)
		);
	//defuzzification
	std::cout << "test tips" << std::endl;
	std::cout << tips.evaluate() << std::endl;

	ValueModel<float> test1(5.0);

	std::cout << "test r" << std::endl;
	std::cout << r->evaluate() << std::endl;

	Core::Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);

	//apply input
	float s, foo;

	while (true)
	{
		std::cout << "service : ";
		std::cin >> s;
		service.SetValue(s);
		std::cout << "food : ";
		std::cin >> foo;
		food.SetValue(foo);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}
}

void testSugenoDefuzz()
{
	//operators
	NotMinus1<float>    opNot;
	AndMin<float>       opAnd;
	OrMax<float>        opOr;
	SugenoThen<float>   opThen;
	AggMax<float>       opAgg;
	CogDefuzz<float>    opDefuzz;
	SugenoDefuzz<float> opSugDefuzz;

	std::vector<float> coef;
	coef.push_back(1);
	coef.push_back(1);
	coef.push_back(1);
	//SugenoConclusion<float>* opConclusion = SugenoConclusion<float>(&coef);
	SugenoConclusion<float> opConclusion(&coef);

	//fuzzy expession factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz, &opSugDefuzz, &opConclusion);

	//membership function
	// service
	IsTriangle<float> poor(-5, 0, 5);
	IsTriangle<float> good(0, 5, 10);
	IsTriangle<float> excellent(5, 10, 15);
	// food
	IsTriangle<float> rancid(-5, 0, 5);
	IsTriangle<float> delicious(5, 10, 15);
	//values
	ValueModel<float> service(0);
	ValueModel<float> food(0);

	//output : ces variables vont stocker le résultat de SugenoConclusion (zi)
	std::vector<const Expression<float>*> SC_service_food;
	SC_service_food.push_back(&service);
	SC_service_food.push_back(&food);

	std::vector<const Expression<float>*> SC_service;
	SC_service.push_back(&service);

	//rules
	Expression<float> *r =
		f.newThen(
			f.newOr(
				f.newIs(&poor, &service),
				f.newIs(&rancid, &food)
			),
			f.newConclusion(&SC_service_food)
		);

	Expression<float> *r1 =
		f.newThen(
			f.newIs(&good, &service),
			f.newConclusion(&SC_service)
		);

	Expression<float> *r2 =
		f.newThen(
			f.newOr(
				f.newIs(&excellent, &service),
				f.newIs(&delicious, &food)
			),
			f.newConclusion(&SC_service_food)
		);

	std::vector<const Expression<float>*> operands;
	operands.push_back(r);
	operands.push_back(r1);
	operands.push_back(r2);

	//defuzzification
	Expression<float> *system = f.newSugeno(&operands);

	//apply input
	float s, foo;
	while (true)
	{
		std::cout << "service : ";
		std::cin >> s;
		service.SetValue(s);
		std::cout << "food : ";
		std::cin >> foo;
		food.SetValue(foo);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}
}



int _tmain(int argc, _TCHAR* argv[])
{

	unsigned select;
	std::cout << "Voulez vous tester :" << std::endl;
	std::cout << "1: Mamdani ?" << std::endl;
	std::cout << "2: Sugeno ?" << std::endl;
	std::cout << "> ";
	std::cin >> select;

	if (select == 1)
		testMamdani();
	else
		testSugenoDefuzz();

	return 0;
}
