#pragma once
#include "Func.h"
#include <iostream>
class FuncWithSpecificValues : public Func {
	int32_t* _values;

	void copyFrom(const FuncWithSpecificValues& other);
	void free();
	void moveFrom(FuncWithSpecificValues&& other);

public:
	FuncWithSpecificValues() = default;
	FuncWithSpecificValues(int32_t* results, int32_t* values, int32_t count);
	FuncWithSpecificValues(const FuncWithSpecificValues& other);
	FuncWithSpecificValues& operator=(const FuncWithSpecificValues& other);
	FuncWithSpecificValues(FuncWithSpecificValues&& other);
	FuncWithSpecificValues& operator=(FuncWithSpecificValues&& other);
	~FuncWithSpecificValues() override;

	bool isExcluded(int32_t point) const override;
	int32_t operator()(int32_t point) const override;
};

