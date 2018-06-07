#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>

namespace Fuzzy
{
	template <class T>
	class Evaluator
	{
	public:
		typedef std::pair<std::vector<T>, std::vector<T>> Shape;

		Shape BuildShape(const T&, const T&, const T&, Core::ValueModel<T>*, Core::Expression<T>*) const;
		std::ostream& PrintShape(const Shape&, std::ostream&) const;
	};

	template <class T>
	typename Evaluator<T>::Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step, Core::ValueModel<T>* v, Core::Expression<T>* e) const
	{	

		//ValueModel<float> test1(10.0);
		//std::cout << "test : " << test1->evaluate() << std::endl;
		std::cout << "Vavant : " << v << std::endl;
		std::vector<T> x, y;
		T mem = v->ValueModel<T>::evaluate();
		std::cout << "V : " << mem << std::endl;
		for (T i = min; i <= max; i += step)
		{
			std::cout << "i : " << i << std::endl;
			std::cout << "eval : " << e->evaluate() << std::endl;
			v->SetValue(i);
			y.push_back(e->evaluate());
			x.push_back(i);
			//y.push_back(e->evaluate());
		}

		v->SetValue(mem);

		return Shape(x, y);
	}

	template <class T>
	typename std::ostream& Evaluator<T>::PrintShape(const Shape& s, std::ostream& os) const
	{
		for (std::vector<T>::const_iterator ity = s.second.begin(); ity != s.second.end(); ity++)
		{
			unsigned count = (unsigned)((*ity) * 10);

			while (count != 0)
			{
				os << "-";
				count--;
			}

			os << "*" << std::endl;
		}

		return os;
	}
}

#endif