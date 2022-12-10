#include "Parser.h"

namespace FPL::Parser {
    /*Parser::Parser() {
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

    }*/

    bool Parser::PrintInstruction(FPL::Data::Data& data) {
        auto possiblePrint = ExpectIdentifiant(data);
        if (possiblePrint && possiblePrint->TokenText == "envoyer") {
            while (!ExpectOperator(data, ";").has_value()) {
                auto Value = ExpectValue(data);
                std::cout << Value->StatementName;

                if (ExpectOperator(data, ";").has_value()) {
                    break;
                }
            }
            std::cout << std::endl;
            return true;
        }
        return false;
    }

    void Parser::ParserCode(std::vector<FPL::Tokenizer::Token>& Tokens) {
        Data::Data data(Tokens);

        while (data.current_token != data.end_token) {
            if (PrintInstruction(data)) {

            } else {
                if (data.current_token->TokenText.empty()
                || data.current_token->TokenType == FPL::Tokenizer::ESPACE_VIDE
                || data.current_token->TokenText == " ") {
                    continue;
                }

                std::cerr << "Identifier inconnu : " << data.current_token->TokenText << " : " << data.current_token->TokenLineNumber << std::endl;
                ++data.current_token;
            }
        }
    }
}
