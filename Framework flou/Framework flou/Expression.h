#pragma once
#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace Core {

	template <class T>
	class Expression {
	public:
		virtual ~Expression() {};
		virtual T evaluate() const = 0;
	};
}
#endif