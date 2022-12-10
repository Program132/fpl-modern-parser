#include <vector>
#include <iostream>
#include <map>

#include "../Types.h"
#include "../Tokenizer.h"

namespace FPL::Data {
    using namespace FPL::Tokenizer;

    class Data {
    public:
        Data(std::vector<FPL::Tokenizer::Token>& Tokens);

        std::vector<Token>::iterator current_token; // Le token que le Parser analyze
        std::vector<Token>::iterator end_token; // Le dernier token sauvegardé
        std::map<std::string, FPL::Types::Types> AllFPLTypes;

        void initFPL(std::vector<FPL::Tokenizer::Token>& Tokens);
        void incrementeCurrentToken();
        void decrementeCurrentToken();
    };
}