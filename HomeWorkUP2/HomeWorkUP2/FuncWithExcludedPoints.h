#pragma once
#include "Func.h"

class FuncWithExcludedPoints : public Func {
public:
	FuncWithExcludedPoints(int32_t* results, int32_t count);
	bool isExcluded(int32_t point) const override;
	int32_t operator()(int32_t point) const override;
};
