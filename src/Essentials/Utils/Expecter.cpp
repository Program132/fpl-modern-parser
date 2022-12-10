#include "Expecter.h"

using namespace FPL;
using namespace FPL::Data;
using namespace FPL::Tokenizer;

std::optional<Token> ExpectIdentifiant(FPL::Data::Data &data, std::string_view name) {
    if (data.current_token == data.end_token) { return std::nullopt; }
    if (data.current_token->TokenType != Tokenizer::IDENTIFIANT) { return std::nullopt; }
    if (!name.empty() && data.current_token->TokenText != name) { return std::nullopt; }

    auto returnToken = data.current_token;
    data.current_token++;
    return *returnToken;
}

std::optional<Token> ExpectOperator(FPL::Data::Data &data, std::string_view name) {
    if (data.current_token == data.end_token) { return std::nullopt; }
    if (data.current_token->TokenType != Tokenizer::OPERATEUR) { return std::nullopt; }
    if (data.current_token->TokenText != name && !name.empty()) { return std::nullopt; }

    auto returnToken = data.current_token;
    data.current_token++;
    return *returnToken;
}

std::optional<Types::Types> ExpectType(FPL::Data::Data &data) {
    auto possibleType = ExpectIdentifiant(data);
    if (!possibleType.has_value()) { return std::nullopt; }

    auto foundType = data.AllFPLTypes.find(possibleType->TokenText);
    if (foundType == data.AllFPLTypes.end()) {
        data.current_token--;
        return std::nullopt;
    }

    return foundType->second;
}

std::optional<Statement::Statement> ExpectValue(FPL::Data::Data &data) {
    std::optional<Statement::Statement> res;

    if (data.current_token->TokenType == FPL::Tokenizer::DECIMAL) {
        Statement::Statement doubleLitteralStatement(
                Statement::StatementKind::LITTERAL,
                data.current_token->TokenText,
                Types::Types("decimal", FPL::Types::STRING)
        );
        res = doubleLitteralStatement;
    } else if (data.current_token->TokenType == Tokenizer::ENTIER) {
        Statement::Statement integerLitteralStatement(
                Statement::StatementKind::LITTERAL,
                data.current_token->TokenText,
                Types::Types("entier", Types::STRING)
        );
        res = integerLitteralStatement;
    } else if (data.current_token->TokenType == Tokenizer::CHAINE_LITTERAL) {
        Statement::Statement stringLitteralStatement(
                Statement::StatementKind::LITTERAL,
                data.current_token->TokenText,
                Types::Types("text", Types::STRING)
        );
        res = stringLitteralStatement;

    } else {
        return std::nullopt;
    }

    data.current_token++;
    return res;
}

bool ExpectEgalOperators(FPL::Data::Data &data) {
    if (ExpectOperator(data, "-").has_value()) {
        if (ExpectOperator(data, ">").has_value()) {
            return true;
        }
    }
    return false;
}

std::optional<std::string> ExpectOperatorCondition(FPL::Data::Data &data) {
    // Ops : <, >, =, <=, >=

    auto const firstOp = ExpectOperator(data);
    auto const secondOp = ExpectOperator(data);
    if (firstOp.has_value() && secondOp.has_value()) {
        if (firstOp->TokenText == "<" && secondOp->TokenText == "=") { return "<="; }
        else if (firstOp->TokenText == ">" && secondOp->TokenText == "=") { return ">="; }
        else { wrongOperatorCondition(data); }
    } else if (firstOp.has_value()) {
        if (firstOp->TokenText == "=") { return "="; }
        else if (firstOp->TokenText == ">") { return ">"; }
        else if (firstOp->TokenText == "<") { return "<"; }
        else { wrongOperatorCondition(data); }
    }
    return std::nullopt;
}