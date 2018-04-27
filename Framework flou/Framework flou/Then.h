#ifndef THEN_H
#define THEN_H

namespace Fuzzy {
	template <class T>
	class Then : public BinaryExpression<T> {
	public:
		virtual T evaluate(Core::Expression<T>*, Core::Expression<T>*) const = 0;
	};


}



#endif
