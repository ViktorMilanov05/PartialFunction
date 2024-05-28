#include <iostream>
#include <fstream>
#include "Func.h"
#include "FuncWithSpecificValues.h"
#include "PartialFunctionByCriteria.hpp"
#include "PartialFunction.hpp"
#include "Pair.h"

static PartialFunction<Pair>* FuncFactory(std::ifstream& ifs)
{
    try {
        int16_t n;
        int16_t t;

        ifs.read((char*)(&n), sizeof(n));
        ifs.read((char*)(&t), sizeof(t));

        switch (t) {
        case 0: {
            int32_t* results = new int32_t[n];
            int32_t* values = new int32_t[n];

            ifs.read((char*)(results), n * sizeof(int32_t));
            ifs.read((char*)(values), n * sizeof(int32_t));
            for (size_t i = 0; i < n; i++)
            {
                std::cout << results[i] << ' ';
            }
            FuncWithSpecificValues function(results, values, n);
            PartialFunction<Pair>* result = new PartialFunctionByCriteria<FuncWithSpecificValues, Pair>(function);
            return result;
        }
        default:
            throw std::invalid_argument("Invalid T");
        }
    }
    catch (std::invalid_argument) {
        std::cout << "Invalid T";
    }
}
