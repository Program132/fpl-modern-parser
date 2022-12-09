#include <iostream>
#include <fstream>

#include "src/Essentials/Tokenizer.h"

using namespace FPL;

int main(int argc, char** argv) {
    std::cout << "Init Parser FPL V2" << std::endl;

    std::string fileName;
    if (argc == 2) {
        fileName = argv[1];
    } else {
        std::cout << "Fichier : ";
        std::cin >> fileName;
        std::cout << std::endl;
    }
    std::ifstream file { fileName};
    if (!file) {
        std::cerr << "Donnez le nom correct du fichier." << std::endl;
        return 1;
    }
    std::string FileCode((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

    std::vector<Tokenizer::Token> FileCode_Tokens = FPL::Tokenizer::TokenBuilder::ParseToken(FileCode);

    for (Tokenizer::Token const& e : FileCode_Tokens) {
        std::cout << e << std::endl;
    }

    return 0;
}