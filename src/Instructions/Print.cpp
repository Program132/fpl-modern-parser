#include "Print.h"

namespace FPL::Instruction::Print {
    void operatorCondReturnFalseTrue_INT(std::string operatorCond, int a, int b) {
        if (operatorCond == "=") {
            if (a == b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        } else if (operatorCond == "<") {
            if (a < b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        } else if (operatorCond == ">") {
            if (a > b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        } else if (operatorCond == "<=") {
            if (a <= b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        } else if (operatorCond == ">=") {
            if (a >= b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        }
    }

    void operatorCondReturnFalseTrue_DOUBLE(std::string operatorCond, double a, double b) {
        if (operatorCond == "=") {
            if (a == b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        } else if (operatorCond == "<") {
            if (a < b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        } else if (operatorCond == ">") {
            if (a > b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        } else if (operatorCond == "<=") {
            if (a <= b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        } else if (operatorCond == ">=") {
            if (a >= b) { std::cout << "vrai"; } else { std::cout << "faux"; }
        }
    }
}