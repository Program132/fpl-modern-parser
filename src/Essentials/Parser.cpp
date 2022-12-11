#include "Parser.h"

namespace FPL::Parser {

    void Parser::InputInstruction(FPL::Data::Data& data) {
        auto possibleType = ExpectType(data);
        if (possibleType.has_value()) {
            auto possibleName = ExpectIdentifiant(data);
            if (possibleName.has_value()) {
                if (ExpectEgalOperators(data)) { // Si on affiche une valeur classique/d'une variable dans la console...
                    auto Content_CIN_Value = ExpectValue(data);
                    auto Content_CIN_Id = ExpectIdentifiant(data);

                    if (ExpectOperator(data, ";").has_value()) {
                        if (Content_CIN_Id.has_value() && data.isVariable(Content_CIN_Id->TokenText)) {
                            auto variable = data.getVariable(Content_CIN_Id->TokenText);
                            std::cout << variable->VariableValue << std::endl;
                        } else if (Content_CIN_Value.has_value()) {
                            std::cout << Content_CIN_Value->StatementName << std::endl;
                        }

                        std::string finalValue;
                        if (possibleType->Type == FPL::Types::INT) {
                            int v;
                            std::cin >> v;
                            finalValue = std::to_string(v);
                            if (finalValue == "0" || v == 0) {
                                inputTypeError(data);
                            }
                            std::cout << std::endl;
                        } else if (possibleType->Type == FPL::Types::DOUBLE) {
                            double v;
                            std::cin >> v;
                            finalValue = std::to_string(v);
                            if (finalValue == "0" || v == 0) {
                                inputTypeError(data);
                            }
                            std::cout << std::endl;
                        } else {
                            std::cin >> finalValue;
                        }

                        if (possibleType->Type == FPL::Types::BOOL) {
                            if (finalValue != "vrai" && finalValue != "faux") {
                                BoolNotLikeValue(data);
                            }
                        }

                        if (data.isVariable(possibleName->TokenText)) {
                            auto variable = data.getVariable(Content_CIN_Id->TokenText);
                            variable->VariableValue = finalValue;
                        } else {
                            VariableDef variable;
                            variable.VariableName = possibleName->TokenText;
                            variable.VariableValue = finalValue;
                            variable.VariableType = FPL::Types::Types(possibleType->Name, possibleType->Type);

                            data.addVariableToMap(variable.VariableName, variable.VariableValue, variable.VariableType);
                        }
                    } else {
                        forgotEgalOperators(data);
                    }
                } else { // Si on n'affiche rien dans la console...
                    if (ExpectOperator(data, ";").has_value()) {
                        std::string finalValue;
                        if (possibleType->Type == FPL::Types::INT) {
                            int v;
                            std::cin >> v;
                            finalValue = std::to_string(v);
                            if (finalValue == "0" || v == 0) {
                                inputTypeError(data);
                            }
                            std::cout << std::endl;
                        } else if (possibleType->Type == FPL::Types::DOUBLE) {
                            double v;
                            std::cin >> v;
                            finalValue = std::to_string(v);
                            if (finalValue == "0" || v == 0) {
                                inputTypeError(data);
                            }
                            std::cout << std::endl;
                        } else {
                            std::cin >> finalValue;
                        }

                        if (possibleType->Type == FPL::Types::BOOL) {
                            if (finalValue != "vrai" && finalValue != "faux") {
                                BoolNotLikeValue(data);
                            }
                        }

                        VariableDef variable;
                        variable.VariableName = possibleName->TokenText;
                        variable.VariableValue = finalValue;
                        variable.VariableType = FPL::Types::Types(possibleType->Name, possibleType->Type);

                        data.addVariableToMap(variable.VariableName, variable.VariableValue, variable.VariableType);
                    } else {
                        forgotEgalOperators(data);
                    }
                }
            } else {
                forgotName(data);
            }
        } else {
            forgotType(data);
        }
    }

    void Parser::PrintInstruction(FPL::Data::Data& data) {
        while (!ExpectOperator(data, ";").has_value()) {
            auto Value = ExpectValue(data);
            if (Value.has_value()) {
                std::cout << Value->StatementName;
            }
            auto Id = ExpectIdentifiant(data);
            if (Id.has_value()) {
                auto var = data.getVariable(Id->TokenText);
                auto operatorCond = ExpectOperatorCondition(data);
                if (operatorCond.has_value()) {
                    std::cout << 2 << std::endl;
                    int valueInt = stringToInt(var->VariableValue, "");
                    double valueDouble = stringToDouble(var->VariableValue, "");

                    auto nextValue = ExpectValue(data);
                    if (nextValue.has_value()) {
                        if (var->VariableType.Name != nextValue->StatementType.Name && var->VariableType.Type != Types::BUILTIN_TYPE::BOOL) {
                            differentTypes(data);
                        }

                        if (var->VariableType.Type == Types::BUILTIN_TYPE::INT) {
                            int nextValueInt = stringToInt(nextValue->StatementName, "");
                            Instruction::Print::operatorCondReturnFalseTrue_INT(operatorCond.value(), valueInt, nextValueInt);
                        } else if (var->VariableType.Type == Types::BUILTIN_TYPE::DOUBLE) {
                            double nextValueDouble = stringToDouble(nextValue->StatementName, "");
                            Instruction::Print::operatorCondReturnFalseTrue_DOUBLE(operatorCond.value(), valueDouble, nextValueDouble);
                        } else {
                            needValueNextOperatorCondition(data);
                        }
                    } else {
                        auto nextId = ExpectIdentifiant(data);
                        if (nextId.has_value()) {
                            if (data.isVariable(nextId->TokenText)) {
                                auto nextVar = data.getVariable(nextId->TokenText);
                                if (var->VariableType.Name != nextVar->VariableType.Name && var->VariableType.Type != Types::BUILTIN_TYPE::BOOL) {
                                    differentTypes(data);
                                }

                                if (var->VariableType.Type == Types::BUILTIN_TYPE::INT) {
                                    int nextValueInt = stringToInt(nextVar->VariableValue, "");
                                    Instruction::Print::operatorCondReturnFalseTrue_INT(operatorCond.value(), valueInt, nextValueInt);
                                } else if (var->VariableType.Type == Types::BUILTIN_TYPE::DOUBLE) {
                                    double nextValueDouble = stringToDouble(nextVar->VariableValue, "");
                                    Instruction::Print::operatorCondReturnFalseTrue_DOUBLE(operatorCond.value(), valueDouble, nextValueDouble);
                                } else {
                                    needValueNextOperatorCondition(data);
                                }
                            } else{
                                variableDoesNotExist(data);
                            }
                        } else {
                            needValueNextOperatorCondition(data);
                        }
                    }
                }
                else { // S'il n'y a pas d'opérateur de condition
                    if (var.has_value()) {
                        std::cout << var->VariableValue;
                    }
                }
            }

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
                    VariableDef variable;
                    variable.VariableName = possibleVariableName->TokenText;

                    auto possibleValue = ExpectValue(data); // Valeur classique genre 5, 5.2, "salut"
                    if (possibleValue.has_value()) {
                        if (possibleType->Type == Types::BOOL) {
                            BoolNotLikeValue(data);
                        } else {
                            if (possibleValue->StatementType.Name != possibleType->Name) { // On vérifie si les deux types sont les mêmes
                                differentTypes(data);
                            }

                            if (ExpectOperator(data, ";").has_value()) {
                                if (data.isVariable(possibleVariableName->TokenText)) {
                                    variableAlreadyExist(data);
                                }
                                variable.VariableValue = possibleValue->StatementName;
                                variable.VariableType = FPL::Types::Types(possibleType->Name, possibleType->Type);

                                data.addVariableToMap(variable.VariableName, variable.VariableValue, variable.VariableType);
                            } else {
                                forgotEndInstructionOperator(data);
                            }
                        }
                    } else { // Pour les variables déjà déclaré ou le type bool
                        auto possibleId = ExpectIdentifiant(data);
                        if (possibleId.has_value()) {
                            if (data.isVariable(possibleId->TokenText)) {
                                if (ExpectOperator(data, ";").has_value()) {
                                    auto oldVar  = data.getVariable(possibleId->TokenText);
                                    if (oldVar.has_value()) {
                                        variable.VariableValue = oldVar->VariableValue;
                                        variable.VariableType = FPL::Types::Types(possibleType->Name, possibleType->Type);

                                        if (variable != oldVar) {
                                            differentTypes(data);
                                        }

                                        data.addVariableToMap(variable.VariableName, variable.VariableValue, variable.VariableType);
                                    }
                                } else {
                                    forgotEndInstructionOperator(data);
                                }
                            } else if (possibleId->TokenText == "vrai" || possibleId->TokenText == "faux") {
                                if (possibleType->Type == Types::BOOL) {
                                    if (ExpectOperator(data, ";").has_value()) {
                                        variable.VariableValue = possibleId->TokenText;
                                        variable.VariableType = FPL::Types::Types("bool", Types::BOOL);

                                        data.addVariableToMap(variable.VariableName, variable.VariableValue, variable.VariableType);
                                    } else {
                                        forgotEndInstructionOperator(data);
                                    }
                                } else {
                                    wrongTypeForBool(data);
                                }
                            }
                        } else {
                            forgotValue(data);
                        }
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
            } else if (Instruction->TokenText == "saisir") {
                InputInstruction(data);
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