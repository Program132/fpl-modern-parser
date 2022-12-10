#include "Tokenizer.h"

namespace FPL::Tokenizer {
    std::vector<Token> TokenBuilder::ParseToken(const std::string &contentFile) {
        std::vector<Token> AllTokens;
        Token currentToken;

        for (auto const &element: contentFile) {
            switch (element) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    if (currentToken.TokenType == ESPACE_VIDE) {
                        currentToken.TokenType = ENTIER;
                        currentToken.TokenText.append(1, element);
                    } else if (currentToken.TokenType == PEUTETRE_DECIMAL) {
                        currentToken.TokenType = DECIMAL;
                        currentToken.TokenText.append(1, element);
                    } else if (currentToken.TokenType == IDENTIFIANT) {
                        TokenBuilder::ParseEndToken(currentToken, AllTokens);
                        currentToken.TokenType = ENTIER;
                        currentToken.TokenText.append(1, element);
                    }  else {
                        currentToken.TokenText.append(1, element);
                    }
                    break;

                case '.':
                    if (currentToken.TokenType == ESPACE_VIDE) {
                        currentToken.TokenType = PEUTETRE_DECIMAL;
                        currentToken.TokenText.append(1, element);
                    } else if (currentToken.TokenType == ENTIER) {
                        currentToken.TokenType = DECIMAL;
                        currentToken.TokenText.append(1, element);
                    } else if (currentToken.TokenType == CHAINE_LITTERAL) {
                        currentToken.TokenText.append(1, element);
                    } else {
                        TokenBuilder::ParseEndToken(currentToken, AllTokens);
                        currentToken.TokenType = OPERATEUR;
                        currentToken.TokenText.append(1, element);
                        TokenBuilder::ParseEndToken(currentToken, AllTokens);
                    }
                    break;

                case '{':
                case '}':
                case '(':
                case ')':
                case ',':
                case ';':
                case '-':
                case '+':
                case '/':
                case '*':
                case '=':
                case '<':
                case '>':
                case '[':
                case ']':
                    if (currentToken.TokenType != CHAINE_LITTERAL) {
                        TokenBuilder::ParseEndToken(currentToken, AllTokens);
                        currentToken.TokenType = OPERATEUR;
                        currentToken.TokenText.append(1, element);
                        TokenBuilder::ParseEndToken(currentToken, AllTokens);
                    } else {
                        currentToken.TokenText.append(1, element);
                    }
                    break;

                case '"':
                    if (currentToken.TokenType != CHAINE_LITTERAL) {
                        TokenBuilder::ParseEndToken(currentToken, AllTokens);
                        currentToken.TokenType = CHAINE_LITTERAL;
                    } else if (currentToken.TokenType == CHAINE_LITTERAL) {
                        TokenBuilder::ParseEndToken(currentToken, AllTokens);
                    }
                    break;

                default:
                    if (currentToken.TokenType == ESPACE_VIDE || currentToken.TokenType == ENTIER || currentToken.TokenType == DECIMAL) {
                        TokenBuilder::ParseEndToken(currentToken, AllTokens);
                        currentToken.TokenType = IDENTIFIANT;
                        currentToken.TokenText.append(1, element);
                    } else {
                        currentToken.TokenText.append(1, element);
                    }
                    break;
            }
        }

        TokenBuilder::ParseEndToken(currentToken, AllTokens);
        return AllTokens;
    }

    void TokenBuilder::ParseEndToken(Token &token, std::vector<Token> &tokens) {
        if (token.TokenType != ESPACE_VIDE) {
            tokens.push_back(token);
        }

        if (token.TokenType == PEUTETRE_DECIMAL) {
            if (token.TokenText == ".") {
                token.TokenType = OPERATEUR;
            } else {
                token.TokenType = PEUTETRE_DECIMAL;
            }
        }
        token.TokenType = ESPACE_VIDE;
        token.TokenText.erase();
    }

    std::ostream &operator<<(std::ostream &flux, const Token &token) {
        flux << "(Token Flux: " << token.TokenText << ", " << FPL::Tokenizer::sAllTokenTypes[token.TokenType] << ")";
        return flux;
    }
}