#ifndef EVALUATOR_H
#define EVALUATOR_H
//#include "Shape.h"
#include <vector>
#include "ValueModel.h"
#include "Expression.h"

using namespace std;
 
namespace Core {

	template <class T>
	class Evaluator {
	public:

		//virtual T operator () (const T&) = 0;
		typedef  pair<vector<T>, vector<T> > Shape ;

		static Shape BuildShape(Expression<T>* entre, ValueModel<T>* exit, T const min, T const max, T const step) const;//static
		//static ostream& PrintShape(ostream&, const Shape& s);
	};

	

	template<class T>
	static Shape Evaluator<T>::BuildShape(Expression<T>* entre, ValueModel<T>* exit, T const min, T const max, T const step) const {
		vector<T> x, y;

		T memory = exit->evaluate();

		for (T i = min; i <= max; i += step)
		{
			y.push_back(entre->evaluate());
			x.push_back(i);
		}
		exit->ValueModel<T>::SetValue(memory);

		return Shape(x, y);
	}
}
#endif