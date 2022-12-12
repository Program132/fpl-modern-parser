#include "Prints.h"

namespace FPL::Instruction::Prints {
    void printWithOperatorCondition_INT(std::string_view currOP, int a, int b) {
        if (currOP == "N/A") {
            if (a == b) {
                std::cout << "vrai";
            } else {
                std::cout << "faux";
            }
        } else if (currOP == "<") {
            if (a <= b) {
                std::cout << "vrai";
            } else {
                std::cout << "faux";
            }
        } else if (currOP == ">") {
            if (a >= b) {
                std::cout << "vrai";
            } else {
                std::cout << "faux";
            }
        }
    }

    void printWithOperatorCondition_DOUBLE(std::string_view currOP, double a, double b) {
        if (currOP == "N/A") {
            if (a == b) {
                std::cout << "vrai";
            } else {
                std::cout << "faux";
            }
        } else if (currOP == "<") {
            if (a <= b) {
                std::cout << "vrai";
            } else {
                std::cout << "faux";
            }
        } else if (currOP == ">") {
            if (a >= b) {
                std::cout << "vrai";
            } else {
                std::cout << "faux";
            }
        }
    }
}