#pragma once
#ifndef SHAPE_H
#define SHAPE_H

namespace Core {

	template <class T>
	class Shape {
	public:
		virtual T evaluate() const = 0;
	};

}
#endif
