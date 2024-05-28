#include <iostream>
#include <fstream>
#include "PartialFunction.hpp"
#include "FuncFactory.cpp"

int main() {
    std::ifstream ifs("h2_0.bin", std::ios::binary);

    if (!ifs) {
            try {
                throw std::exception("Unable to open stream");
            }
            catch (std::exception) {
                std::cout << "Unable to open stream";
            } 
    }
    PartialFunction<Pair>* arr = FuncFactory(ifs);
    std::cout << arr->operator()(7) << std::endl << arr->isDefined(3) << std::endl << arr->isDefined(10);


    //std::ofstream outFile("h2_0.bin", std::ios::binary);
    //if (!outFile) {
    //    std::cerr << "Error opening file for writing" << std::endl;
    //    return 1;
    //}
    //int16_t n = 7;
    //int16_t t = 0;
    //outFile.write((const char*)(&n), sizeof(n));
    //outFile.write((const char*)(&t), sizeof(t));
    //unsigned int secondSet[] = { 0, 1, 2, 3, 5, 6, 7 };
    //outFile.write((const char*)(secondSet), sizeof(secondSet));
    //unsigned int thirdSet[] = { 0, 3, 3, 3, 4, 4, 0 };
    //outFile.write((const char*)(thirdSet), sizeof(thirdSet));
    //outFile.close();
    //if (!outFile.good()) {
    //    std::cerr << "Error occurred at writing time!" << std::endl;
    //    return 1;
    //}
    //std::cout << "Values written to output.bin successfully!" << std::endl;
}