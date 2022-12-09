#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ostream>

namespace FPL::Tokenizer {

        enum TokenTypes {
            ESPACE_VIDE,
            IDENTIFIANT,
            ENTIER, // Int
            DECIMAL, // Double
            PEUTETRE_DECIMAL,
            CHAINE_LITTERAL, // Strings
            OPERATEUR // Opérateurs comme +, -, /, *,...
        };

        static const char *sAllTokenTypes[] = {
                "ESPACE_VIDE",
                "IDENTIFIANT",
                "ENTIER",
                "DECIMAL",
                "PEUTETRE_DECIMAL",
                "CHAINE_LITTERAL",
                "OPERATEUR"
        };

        class Token {
        public:
            enum TokenTypes TokenType;
            std::string TokenText;
            [[maybe_unused]] size_t TokenLineNumber = 0;

            friend std::ostream& operator<<(std::ostream& flux, Token const& token);
        };

        class TokenBuilder {
        public:
            static std::vector<Token> ParseToken(const std::string& contentFile);

            static void ParseEndToken(Token& token, std::vector<Token>& tokens);
        };
    }