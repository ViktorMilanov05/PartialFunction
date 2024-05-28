#pragma once
#include "PartialFunction.hpp"
#include "Pair.h"

class MinAndMaxPartialFunction : public PartialFunction<int> {
	void copyFrom(const MinAndMaxPartialFunction& other);
	void moveFrom(MinAndMaxPartialFunction&& other);
	void free();
protected:
	PartialFunction<Pair>** _functions;
	size_t count;
public:
	MinAndMaxPartialFunction(const PartialFunction<Pair>** functions, size_t functionsCount);
	MinAndMaxPartialFunction(const MinAndMaxPartialFunction& other);
	MinAndMaxPartialFunction(MinAndMaxPartialFunction&& other) noexcept;
	MinAndMaxPartialFunction& operator=(const MinAndMaxPartialFunction& other);
	MinAndMaxPartialFunction& operator=(MinAndMaxPartialFunction&& other) noexcept;
	virtual ~MinAndMaxPartialFunction() noexcept;
	virtual bool isDefined(int32_t point) const override;
	virtual int operator()(int32_t point) const = 0;
	virtual PartialFunction<int>* clone() const = 0;
};