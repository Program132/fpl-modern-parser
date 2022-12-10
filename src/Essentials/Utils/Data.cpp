#include "Data.h"

namespace FPL::Data {
    Data::Data(std::vector<FPL::Tokenizer::Token>& Tokens) {
        AllFPLTypes["vide"] = FPL::Types::Types("vide", Types::BUILTIN_TYPE::VOID);
        AllFPLTypes["entier"] = FPL::Types::Types("entier", Types::BUILTIN_TYPE::INT);
        AllFPLTypes["decimal"] = FPL::Types::Types("decimal", Types::BUILTIN_TYPE::DOUBLE);
        AllFPLTypes["texte"] = FPL::Types::Types("texte", Types::BUILTIN_TYPE::STRING);
        AllFPLTypes["auto"] = FPL::Types::Types("auto", Types::BUILTIN_TYPE::AUTO);
        AllFPLTypes["bool"] = FPL::Types::Types("bool", Types::BUILTIN_TYPE::BOOL); // Deux façons d'avoir le type bool.
        AllFPLTypes["boolean"] = FPL::Types::Types("boolean", Types::BUILTIN_TYPE::BOOL);

        current_token = Tokens.begin();
        end_token = Tokens.end();

        InstructionsList = {
                // Instructions:
                "envoyer",
                "variable",
                // Types:
                "entier",
                "decimal",
                "texte",
                "auto",
                "bool",
                "boolean",
                "vide"
        };
    }

    void Data::addVariableToMap(std::string name, std::string value, FPL::Types::Types type) {
        VariableDef newVariable;
        newVariable.VariableName = name;
        newVariable.VariableValue = value;
        newVariable.VariableType = type;
        Map_Variables[newVariable.VariableName] = newVariable;
    }

    bool Data::isVariable(std::string name) {
        if (Map_Variables.contains(name)) { return true; }
        return false;
    }

    std::optional<FPL::VariableDef> Data::getVariable(std::string name) {
        if (isVariable(name)) {
            VariableDef var = Map_Variables[name];
            return var;
        }
        return std::nullopt;
    }
}