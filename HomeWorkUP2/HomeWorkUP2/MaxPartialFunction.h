#pragma once
#include "MinAndMaxPartialFunction.h"

template<class ReturnType>
class MaxPartialFunction : public MinAndMaxPartialFunction<ReturnType> {
public:
	MaxPartialFunction();
	MaxPartialFunction(const PartialFunction<ReturnType>** functions, size_t functionsCount);
	virtual PartialFunction<ReturnType>* clone() const override;
	virtual ReturnType operator()(int32_t point) const override;
};