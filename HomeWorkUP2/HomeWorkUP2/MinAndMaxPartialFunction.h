#pragma once
#include "PartialFunction.hpp"

template<class ReturnType>
class MinAndMaxPartialFunction : public PartialFunction<ReturnType> {
	void copyFrom(const MinAndMaxPartialFunction<ReturnType>& other);
	void moveFrom(MinAndMaxPartialFunction<ReturnType>&& other);
	void free();
protected:
	PartialFunction<ReturnType>** _functions;
	size_t count;
	size_t cap;
	void resize(size_t newCap);
public:
	MinAndMaxPartialFunction();
	MinAndMaxPartialFunction(const PartialFunction<ReturnType>** functions, size_t functionsCount);
	MinAndMaxPartialFunction(const MinAndMaxPartialFunction<ReturnType>& other);
	MinAndMaxPartialFunction(MinAndMaxPartialFunction<ReturnType>&& other) noexcept;
	MinAndMaxPartialFunction& operator=(const MinAndMaxPartialFunction<ReturnType>& other);
	MinAndMaxPartialFunction& operator=(MinAndMaxPartialFunction<ReturnType>&& other) noexcept;
	virtual ~MinAndMaxPartialFunction() noexcept;
	void addFunction(const PartialFunction<ReturnType>* function);
	virtual bool isDefined(int32_t point) const override;
};