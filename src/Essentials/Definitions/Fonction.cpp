#include "Fonction.h"

namespace FPL {
    bool FonctionDef::isArgument(FonctionArgumentDef const& argument) {
        auto it = std::find(this->FonctionArguments.begin(), this->FonctionArguments.end(), argument);

        if (it != this->FonctionArguments.end()) {
            return true;
        }
        return false;
    }

    std::ostream& operator<<(std::ostream &flux, FPL::FonctionDef const& f) {
        flux << "Nom de la fonction: " << f.FonctionName << ", type: " << f.FonctionType.Name << ", args: " << f.FonctionNumberArgument;
        return flux;
    }

    std::ostream& operator<<(std::ostream &flux, FPL::FonctionArgumentDef const& f) {
        flux << "Nom de l'argument: " << f.ArgumentName << ", type: " << f.ArgumentType.Name << ", value: " << f.ArgumentValue;
        return flux;
    }

    bool operator==(FonctionArgumentDef const& arg1, FonctionArgumentDef const& arg2) {
        return arg1.ArgumentName == arg2.ArgumentName;
    }
}