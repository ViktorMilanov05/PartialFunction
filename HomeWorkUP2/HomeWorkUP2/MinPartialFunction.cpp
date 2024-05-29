#include "MinPartialFunction.h"

template<class ReturnType>
MinPartialFunction<ReturnType>::MinPartialFunction() : MinAndMaxPartialFunction<ReturnType>()
{
}

template<class ReturnType>
MinPartialFunction<ReturnType>::MinPartialFunction(const PartialFunction<ReturnType>** functions, size_t functionsCount) : MinAndMaxPartialFunction<ReturnType>(functions, functionsCount) {};

template<class ReturnType>
ReturnType MinPartialFunction<ReturnType>::operator()(int32_t point) const {
	ReturnType min = _functions[0]->operator()(point);
	for (size_t i = 1; i < count; i++)
	{
		ReturnType currentValue = _functions[i]->operator()(point);
		if (min.getValue() > currentValue.getValue()) {
			min = currentValue;
		}
	}
	return min;
}

template<class ReturnType>
PartialFunction<ReturnType>* MinPartialFunction<ReturnType>::clone() const {
	return new MinPartialFunction(*this);
}