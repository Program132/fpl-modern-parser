#include "ErrorsCodeManagement.h"

void forgotType(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de preciser le type, ligne "
    << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(1);
}

void forgotName(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de donner un nom, ligne "
    << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(2);
}

void forgotEgalOperators(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de placer les operateurs '->' pour donner une valeur, ligne "
    << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(3);
}

void forgotValue(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de donner une valeur, ligne "
    << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(4);
}

void forgotEndInstructionOperator(FPL::Data::Data& data) {
    std::cerr << "Vous avez oublie de mettre l'operateur ';' pour mettre fin a l'instruction., ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(5);
}

void differentTypes(FPL::Data::Data& data) {
    std::cerr << "Vous avez declarer deux types differents dans une meme expression ce qui n'est pas possible, ligne "
    << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(6);
}

void variableAlreadyExist(FPL::Data::Data& data) {
    std::cerr << "Vous avez deja declare une variable avec ce nom, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(7);
}

void variableDoesNotExist(FPL::Data::Data& data) {
    std::cerr << "La variable que vous cherchez n'existe pas, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(8);
}

void BoolNotLikeValue(FPL::Data::Data& data) {
    std::cerr << "Pour utiliser le type bool vous devez pas mettre entre '\"' votre valeur mais marquer 'vrai' ou 'faux' simplement, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(9);
}

void wrongTypeForBool(FPL::Data::Data& data) {
    std::cerr << "Pour utiliser un type bool vous devez mettre en argument 'boolean' ou 'bool', ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(10);
}

void needValueNextOperatorCondition(FPL::Data::Data& data) {
    std::cerr << "Apres votre operateur conditionnelle vous devez specifier une valeur, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(11);
}

void inputTypeError(FPL::Data::Data& data) {
    std::cerr << "Votre reponse a l'entree clavier comporte un type non similaire a votre type preciser, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(12);
}

void wrongType(FPL::Data::Data& data) {
    std::cerr << "Le type de la valeur preciser n'est pas valide, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(13);
}

void CONVERSION_sameTypeVariable(FPL::Data::Data& data) {
    std::cerr << "Le type precise est le meme que le type de votre variable dans votre conversion donc aucun changement n'est necessaire, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(14);
}

void CONVERSION_boolNumberFromInt(FPL::Data::Data& data) {
    std::cerr << "La variable doit etre de type 'entier' (int) et doit contenir 1 pour 'vrai' et 0 pour 'faux', ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(15);
}

void FONCTION_forgotfirstParenthese(FPL::Data::Data& data) {
    std::cerr << "Vous devez ouvrir les parentheses pour inserer des arguments si vous le souhaitez, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(16);
}

void FONCTION_forgotsecondParenthese(FPL::Data::Data& data) {
    std::cerr << "Vous devez fermer les parentheses pour cloturer l'insertion des arguments si vous en avez mis, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(17);
}

void FONCTION_forgotargtype(FPL::Data::Data& data) {
    std::cerr << "Vous devez donner un le type de votre argument, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(18);
}

void FONCTION_forgotargname(FPL::Data::Data& data) {
    std::cerr << "Vous devez donner un le nom de votre argument, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(19);
}

void FONCTION_forgotaddarg(FPL::Data::Data& data) {
    std::cerr << "Vous devez separer vos argument avec une ',', ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(20);
}

void FONCTION_forgotinsertcode(FPL::Data::Data& data) {
    std::cerr << "Vous devez ouvrir et fermer avec '{' et '}' pour inserer votre code, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(21);
}

void FONCTION_argumentexist(FPL::Data::Data& data) {
    std::cerr << "L'argument existe deja, merci de donner un autre nom, ligne "
              << data.current_token->TokenLineNumber - 1 << "." << std::endl;
    exit(22);
}