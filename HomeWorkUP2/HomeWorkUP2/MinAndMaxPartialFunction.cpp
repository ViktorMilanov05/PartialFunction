#include "MinAndMaxPartialFunction.h"

MinAndMaxPartialFunction::MinAndMaxPartialFunction(const PartialFunction<Pair>** functions, size_t functionsCount) : count(functionsCount) {
	_functions = new PartialFunction<Pair>*[functionsCount];
	for (size_t i = 0; i < functionsCount; ++i) {
		_functions[i] = functions[i]->clone();
	}
}

void MinAndMaxPartialFunction::free() {
	for (int i = 0; i < count; i++)
		delete _functions[i];
	delete[] _functions;
}
void MinAndMaxPartialFunction::moveFrom(MinAndMaxPartialFunction&& other)
{
	_functions = other._functions;
	other._functions = nullptr;

	count = other.count;
	other.count = 0;
}
void MinAndMaxPartialFunction::copyFrom(const MinAndMaxPartialFunction& other)
{
	_functions = new PartialFunction<Pair> *[other.count];

	for (int i = 0; i < other.count; i++)
		_functions[i] = other._functions[i]->clone();

	count = other.count;
}

MinAndMaxPartialFunction::MinAndMaxPartialFunction(const MinAndMaxPartialFunction& other)
{
	copyFrom(other);
}
MinAndMaxPartialFunction::MinAndMaxPartialFunction(MinAndMaxPartialFunction&& other) noexcept
{
	moveFrom(std::move(other));
}

MinAndMaxPartialFunction& MinAndMaxPartialFunction::operator= (const MinAndMaxPartialFunction& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
MinAndMaxPartialFunction& MinAndMaxPartialFunction::operator=(MinAndMaxPartialFunction&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MinAndMaxPartialFunction::~MinAndMaxPartialFunction() noexcept
{
	free();
}

bool MinAndMaxPartialFunction::isDefined(int32_t point) const {
	for (size_t i = 0; i < count; i++)
	{
		if (!_functions[i]->isDefined(point))
			return false;
	}
	return true;
}
