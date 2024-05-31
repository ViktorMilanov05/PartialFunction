#include <iostream>
#include <fstream>
#include "PartialFunction.hpp"
#include "FuncFactory.cpp"

void firstMode(PartialFunction<Pair>* function) {
    std::cout << "Enter a and b" << std::endl;
    int32_t a, b;
    std::cin >> a >> b;
    for (size_t i = a; i <= b; i++)
    {
        if (function->isDefined(i))
            std::cout << "f(" << i << ") : " << function->operator()(i) << std::endl;
        else
            std::cout << "f is not defined for " << i << std::endl;
    }
}

void printNextPoint(PartialFunction<Pair>* function, int32_t& current, int32_t last) {
    for (int32_t i = current; i <= last; i++)
    {
        if (function->isDefined(i)) {
            std::cout << "f(" << i << ") : " << function->operator()(i) << std::endl;
            current = ++i;
            break;
        }
    }
}

void secondMode(PartialFunction<Pair>* function) {
    unsigned short choice = 1;
    int32_t current = function->getFirstDefinedPoint(); // if this is max or min with function that is defined for every points and some with much more less defined points it will take much time.
    int32_t last = function->getLastDefinedPoint(); //this too
    while (choice) {
        printNextPoint(function, current, last);
        if (current > last)
            break;
        std::cout << "Enter 1 for next point or 0 for exit";
        std::cin >> choice;
    }
}

int main() {
    try {
        unsigned short caseOfWork;
        std::cout << "Enter which one of the program mode you want" << std::endl << "Enter 1 for the first mode" << std::endl << "Enter 2 for the second mode" << std::endl;
        std::cin >> caseOfWork;
        std::ifstream ifs("h2_3.bin", std::ios::binary);
        if (!ifs) {
            throw std::exception("Unable to open stream");
        }
        PartialFunction<Pair>* function = FuncFactory(ifs);
        switch (caseOfWork) {
        case 1: firstMode(function); break;
        case 2: secondMode(function); break;
        default: throw std::invalid_argument("Incorect Mode");
        }
        delete function;
    }
    catch (std::invalid_argument) {
        std::cout << "Incorect Mode";
    }
    catch (std::exception) {
        std::cout << "Unable to open stream";
    }
}