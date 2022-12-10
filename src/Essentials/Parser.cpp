#include "Parser.h"

namespace FPL::Parser {
    void Parser::PrintInstruction(FPL::Data::Data& data) {
        while (!ExpectOperator(data, ";").has_value()) {
            auto Value = ExpectValue(data);
            std::cout << Value->StatementName;

            if (ExpectOperator(data, ";").has_value()) {
                break;
            }
        }
        std::cout << std::endl;
    }

    void Parser::VariableInstruction(FPL::Data::Data &data) {
        auto possibleType = ExpectType(data);
        if (possibleType.has_value()) {
            auto possibleVariableName = ExpectIdentifiant(data);
            if (possibleVariableName.has_value()) {
                if (ExpectEgalOperators(data)) {
                    auto possibleValue = ExpectValue(data);
                    if (possibleValue.has_value()) {
                        if (possibleType->Type == Types::BOOL) {

                        } else {
                            if (possibleValue->StatementType.Name != possibleType->Name) { // On vérifie si les deux types sont les mêmes
                                differentTypes(data);
                            }

                            if (ExpectOperator(data, ";").has_value()) {
                                std::cout << "Une variable du nom de " << possibleVariableName->TokenText
                                << " a pour valeur " << possibleValue->StatementName
                                << " et a pour type " << possibleType->Name
                                << std::endl;
                            } else {
                                forgotEndInstructionOperator(data);
                            }
                        }
                    } else {
                        forgotValue(data);
                    }
                } else{
                    forgotEgalOperators(data);
                }
            } else {
                forgotName(data);
            }
        } else {
            forgotType(data);
        }
    }

    bool Parser::ManagerInstruction(FPL::Data::Data &data) {
        auto Instruction = ExpectIdentifiant(data);
        if (Instruction.has_value()) {
            if (Instruction->TokenText == "envoyer") {
                PrintInstruction(data);
                return true;
            } else if (Instruction->TokenText == "variable") {
                VariableInstruction(data);
                return true;
            }
        }
        return false;
    }

    void Parser::ParserCode(std::vector<FPL::Tokenizer::Token>& Tokens) {
        Data::Data data(Tokens);

        while (data.current_token != data.end_token) {
            if (ManagerInstruction(data)) {

            } else {
                if (data.current_token->TokenText.empty()
                    || data.current_token->TokenType == FPL::Tokenizer::ESPACE_VIDE
                    || data.current_token->TokenText == " ") {
                    continue;
                }

                std::cerr << "Identifier inconnu : " << data.current_token->TokenText << " : "
                          << data.current_token->TokenLineNumber << std::endl;
                ++data.current_token;
            }
        }
    }
}