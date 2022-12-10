#include "ErrorsCodeManagement.h"

void forgotType(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de preciser le type, ligne "
    << data.current_token->TokenLineNumber << "." << std::endl;
    exit(1);
}

void forgotName(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de donner un nom, ligne "
    << data.current_token->TokenLineNumber << "." << std::endl;
    exit(2);
}

void forgotEgalOperators(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de placer les operateurs '->' pour donner une valeur, ligne "
    << data.current_token->TokenLineNumber << "." << std::endl;
    exit(3);
}

void forgotValue(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de donner une valeur, ligne "
    << data.current_token->TokenLineNumber << "." << std::endl;
    exit(4);
}

void forgotEndInstructionOperator(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de mettre l'operateur ';' pour mettre fin a l'instruction., ligne "
              << data.current_token->TokenLineNumber << "." << std::endl;
    exit(5);
}

void differentTypes(FPL::Data::Data& data) {
    std::cerr << "Vous avez declarer deux types differents dans une meme expression ce qui n'est pas possible, ligne "
    << data.current_token->TokenLineNumber << "." << std::endl;
    exit(6);
}