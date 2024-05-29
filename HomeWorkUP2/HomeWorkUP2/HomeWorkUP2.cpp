#include <iostream>
#include <fstream>
#include "PartialFunction.hpp"
#include "FuncFactory.cpp"

int main() {
    try {
        std::ifstream ifs("h2_3.bin", std::ios::binary);
        if (!ifs) {
            try {
                throw std::exception("Unable to open stream");
            }
            catch (std::exception) {
                std::cout << "Unable to open stream";
            }
        }
        PartialFunction<Pair>* arr = FuncFactory(ifs);
        std::cout << arr->operator()(0) << std::endl << arr->operator()(1) << std::endl << arr->operator()(2) << std::endl << arr->operator()(6) << std::endl << arr->operator()(7) << std::endl << arr->isDefined(10) << std::endl << arr->isDefined(0);
    }
    catch(std::exception){
        std::cout << "plss";
    }

    //std::ofstream outFile("h2_3.bin", std::ios::binary);
    //if (!outFile) {
    //    std::cerr << "Error opening file for writing" << std::endl;
    //    return 1;
    //}
    //int16_t n = 3;
    //int16_t t = 3;
    //outFile.write((const char*)(&n), sizeof(n));
    //outFile.write((const char*)(&t), sizeof(t));
    //const char* firstFile = "h2_0.bin";
    //const char* secondFile = "h2_1.bin";
    //const char* thirdFile = "h2_2.bin";
    //size_t length = std::strlen(firstFile);
    //outFile.write(firstFile, length);
    //outFile.put('\0');

    //length = std::strlen(secondFile);
    //outFile.write(secondFile, length);
    //outFile.put('\0');

    //length = std::strlen(thirdFile);
    //outFile.write(thirdFile, length);
    //outFile.put('\0');
    ////unsigned int thirdSet[] = { 0, 3, 3, 3, 4, 4, 0 };
    ////outFile.write((const char*)(thirdSet), sizeof(thirdSet));
    //outFile.close();
    //if (!outFile.good()) {
    //    std::cerr << "Error occurred at writing time!" << std::endl;
    //    return 1;
    //}
    //std::cout << "Values written to output.bin successfully!" << std::endl;
}