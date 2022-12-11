#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <optional>


#include "Tokenizer.h"
#include "Utils/Expecter.h"
#include "Utils/ErrorsCodeManagement.h"
#include "Utils/Vectors.h"
#include "Definitions/Variables.h"
#include "MathUtils/Converts.h"

#include "../Instructions/Print.h"
#include "../Instructions/Inputs.h"

#include "MathUtils/MathParser/MathParser.h"

namespace FPL::Parser {
    class Parser {
    public:
        static void ParserCode(std::vector<FPL::Tokenizer::Token>& Tokens);

    private:
        static bool ManagerInstruction(FPL::Data::Data &data);

        static void PrintInstruction(FPL::Data::Data& data);
        static void VariableInstruction(FPL::Data::Data& data);
        static void InputInstruction(FPL::Data::Data& data);
        static void MathInstruction(FPL::Data::Data& data);
    };
}