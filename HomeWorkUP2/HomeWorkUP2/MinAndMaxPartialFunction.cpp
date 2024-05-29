#include "MinAndMaxPartialFunction.h"

template<class ReturnType>
void MinAndMaxPartialFunction<ReturnType>::resize(size_t newCap)
{
	PartialFunction<ReturnType>** temp = new PartialFunction<ReturnType>*[newCap];
	for (size_t i = 0; i < count; i++)
	{
		temp[i] = _functions[i]->clone();
	}
	free();
	_functions = temp;
	cap = newCap;
}

template<class ReturnType>
void MinAndMaxPartialFunction<ReturnType>::addFunction(const PartialFunction<ReturnType>* function)
{
	if (count == cap)
		resize(cap * 2);
	_functions[count] = function;
	count++;
}

template<class ReturnType>
MinAndMaxPartialFunction<ReturnType>::MinAndMaxPartialFunction()
{
	cap = 8;
	_functions = new PartialFunction<ReturnType>*[cap];
	count = 1;
}

template<class ReturnType>
MinAndMaxPartialFunction<ReturnType>::MinAndMaxPartialFunction(const PartialFunction<ReturnType>** functions, size_t functionsCount) : count(functionsCount), cap(functionsCount) {
	_functions = new PartialFunction<ReturnType>*[functionsCount];
	for (size_t i = 0; i < functionsCount; ++i) {
		_functions[i] = functions[i]->clone();
	}
}

template<class ReturnType>
void MinAndMaxPartialFunction<ReturnType>::free() {
	for (int i = 0; i < count; i++)
		delete _functions[i];
	delete[] _functions;
}

template<class ReturnType>
void MinAndMaxPartialFunction<ReturnType>::moveFrom(MinAndMaxPartialFunction<ReturnType>&& other)
{
	_functions = other._functions;
	other._functions = nullptr;

	count = other.count;
	cap = other.cap;

	other.count = other.cap = 0;
}

template<class ReturnType>
void MinAndMaxPartialFunction<ReturnType>::copyFrom(const MinAndMaxPartialFunction<ReturnType>& other)
{
	_functions = new PartialFunction<ReturnType> *[other.cap];

	for (int i = 0; i < other.count; i++)
		_functions[i] = other._functions[i]->clone();

	count = other.count;
	cap = other.cap;
}

template<class ReturnType>
MinAndMaxPartialFunction<ReturnType>::MinAndMaxPartialFunction(const MinAndMaxPartialFunction<ReturnType>& other)
{
	copyFrom(other);
}

template<class ReturnType>
MinAndMaxPartialFunction<ReturnType>::MinAndMaxPartialFunction(MinAndMaxPartialFunction<ReturnType>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class ReturnType>
MinAndMaxPartialFunction<ReturnType>& MinAndMaxPartialFunction<ReturnType>::operator= (const MinAndMaxPartialFunction<ReturnType>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<class ReturnType>
MinAndMaxPartialFunction<ReturnType>& MinAndMaxPartialFunction<ReturnType>::operator=(MinAndMaxPartialFunction<ReturnType>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class ReturnType>
MinAndMaxPartialFunction<ReturnType>::~MinAndMaxPartialFunction() noexcept
{
	free();
}

template<class ReturnType>
bool MinAndMaxPartialFunction<ReturnType>::isDefined(int32_t point) const {
	for (size_t i = 0; i < count; i++)
	{
		if (!_functions[i]->isDefined(point))
			return false;
	}
	return true;
}
