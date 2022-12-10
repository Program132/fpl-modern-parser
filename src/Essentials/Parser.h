#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <optional>

#include "Tokenizer.h"
#include "Utils/Expecter.h"
#include "Utils/ErrorsCodeManagement.h"

namespace FPL::Parser {
    class Parser {
    public:
        static void ParserCode(std::vector<FPL::Tokenizer::Token>& Tokens);

    private:
        static bool ManagerInstruction(FPL::Data::Data &data);

        static void PrintInstruction(FPL::Data::Data& data);
        static void VariableInstruction(FPL::Data::Data& data);
    };
}