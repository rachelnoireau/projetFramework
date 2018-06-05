// Framework flou.cpp : définit le point d'entrée pour l'application console.
//
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

using namespace Core;
using namespace Fuzzy;

int main()
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

	FuzzyFactory<float> f(&minusUn, &minAnd, &maxOr, &minThen, &maxAgg, &cog);

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
}

