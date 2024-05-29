#pragma once
#include "MinAndMaxPartialFunction.h"

template<class ReturnType>
class MinPartialFunction : public MinAndMaxPartialFunction<ReturnType> {
public:
	MinPartialFunction();
	MinPartialFunction(const PartialFunction<ReturnType>** functions, size_t functionsCount);
	virtual PartialFunction<ReturnType>* clone() const override;
	virtual ReturnType operator()(int32_t point) const override;
};