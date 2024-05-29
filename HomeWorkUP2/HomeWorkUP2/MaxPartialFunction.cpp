#include "MaxPartialFunction.h"

template<class ReturnType>
MaxPartialFunction<ReturnType>::MaxPartialFunction() : MinAndMaxPartialFunction<ReturnType>()
{
}

template<class ReturnType>
MaxPartialFunction<ReturnType>::MaxPartialFunction(const PartialFunction<ReturnType>** functions, size_t functionsCount) : MinAndMaxPartialFunction(functions, functionsCount) {};

template<class ReturnType>
ReturnType MaxPartialFunction<ReturnType>::operator()(int32_t point) const {
	ReturnType max = _functions[0]->operator()(point);
	for (size_t i = 1; i < count; i++)
	{
		ReturnType currentValue = _functions[i]->operator()(point);
		if (max.getValue() < currentValue.getValue()) {
			max = currentValue;
		}
	}
	return max;
}

template<class ReturnType>
PartialFunction<ReturnType>* MaxPartialFunction<ReturnType>::clone() const {
	return new MaxPartialFunction(*this);
}