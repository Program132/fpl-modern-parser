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
    }
}