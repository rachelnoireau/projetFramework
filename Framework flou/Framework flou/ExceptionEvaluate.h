#ifndef EXCEPTIONEVALUATE_H
#define EXCEPTIONEVALUATE_H

#include <exception>
using namespace std;

class ExceptionEvaluate : public exception {

	public:
		ExceptionEvaluate(string const& phrase = "") throw() : m_phrase(phrase) {}

		virtual const char* what() const throw()
		{
			return m_phrase.c_str();
		}
	private:
		string m_phrase;


};
#endif
