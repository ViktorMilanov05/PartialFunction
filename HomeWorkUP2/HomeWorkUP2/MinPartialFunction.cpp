#include "MinPartialFunction.h"

MinPartialFunction::MinPartialFunction(const PartialFunction<Pair>** functions, size_t functionsCount) : MinAndMaxPartialFunction(functions, functionsCount) {};

int MinPartialFunction::operator()(int32_t point) const {
	int min = _functions[0]->operator()(point).getValue();
	for (size_t i = 1; i < count; i++)
	{
		int currentValue = _functions[i]->operator()(point).getValue();
		if (min > _functions[0]->operator()(point).getValue()) {
			min = currentValue;
		}
	}
	return min;
}
PartialFunction<int>* MinPartialFunction::clone() const {
	return new MinPartialFunction(*this);
}