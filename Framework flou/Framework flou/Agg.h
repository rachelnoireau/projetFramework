#ifndef AGG_H
#define AGG_H
//#include "BinaryExpression.h"
using namespace Core;
namespace Fuzzy {
	template <class T>
	class Agg : public BinaryExpression<T> {
	public:
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const = 0;
	};

}

#endif
