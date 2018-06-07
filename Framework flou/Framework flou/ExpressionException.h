#pragma once
#ifndef EXPRESSIONEXCEPTION_H
#define EXPRESSIONEXCEPTION_H

#include <exception>
#include <string>

namespace Core
{
	class ExpressionException : public std::exception
	{
	public:
		ExpressionException(std::string m) : m(m) {};
		virtual ~ExpressionException() {};

	private:
		std::string m;
	};
}

#endif