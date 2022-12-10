#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <optional>

#include "Tokenizer.h"

#include "Utils/Expecter.h"

namespace FPL::Parser {
    class Parser {
    public:
        //Parser();

        static void ParserCode(std::vector<FPL::Tokenizer::Token>& Tokens);
    private:

        //std::vector<std::string> InstructionsList;
        //std::map<std::string, FPL::Types::Types> AllFPLTypes;

        static bool PrintInstruction(FPL::Data::Data& data);
    };
}