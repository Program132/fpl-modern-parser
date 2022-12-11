#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <optional>

#include "../Types.h"
#include "../Tokenizer.h"
#include "../Definitions/Variables.h"

namespace FPL::Data {
    using namespace FPL::Tokenizer;

    class Data {
    public:
        explicit Data(std::vector<FPL::Tokenizer::Token>& Tokens);

        std::vector<Token>::iterator current_token; // Le token que le Parser analyze
        std::vector<Token>::iterator end_token; // Le dernier token sauvegardé
        std::map<std::string, FPL::Types::Types> AllFPLTypes;
        std::vector<std::string> InstructionsList;

        std::map<std::string, FPL::VariableDef> Map_Variables;

        void addVariableToMap(std::string& name, std::string& value, FPL::Types::Types& type);
        bool isVariable(std::string& name) const;
        std::optional<FPL::VariableDef> getVariable(std::string& name);
    };
}