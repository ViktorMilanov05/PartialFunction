#include "MaxPartialFunction.h"

MaxPartialFunction::MaxPartialFunction(const PartialFunction<Pair>** functions, size_t functionsCount) : MinAndMaxPartialFunction(functions, functionsCount) {};

int MaxPartialFunction::operator()(int32_t point) const {
	int max = _functions[0]->operator()(point).getValue();
	for (size_t i = 1; i < count; i++)
	{
		int currentValue = _functions[i]->operator()(point).getValue();
		if (max < _functions[0]->operator()(point).getValue()) {
			max = currentValue;
		}
	}
	return max;
}
PartialFunction<int>* MaxPartialFunction::clone() const {
	return new MaxPartialFunction(*this);
}