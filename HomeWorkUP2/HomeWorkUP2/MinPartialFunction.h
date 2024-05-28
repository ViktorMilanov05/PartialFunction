#pragma once
#include "MinAndMaxPartialFunction.h"

class MinPartialFunction : public MinAndMaxPartialFunction {
public:
	MinPartialFunction(const PartialFunction<Pair>** functions, size_t functionsCount);
	virtual PartialFunction<int>* clone() const override;
	virtual int operator()(int32_t point) const override;
};