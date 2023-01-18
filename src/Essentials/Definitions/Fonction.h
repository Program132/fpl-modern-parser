#pragma once

#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include <algorithm>
#include <iterator>

#include "../Types.h"

namespace FPL {
    class FonctionArgumentDef {
    public:
        std::string ArgumentName;
        std::string ArgumentValue;
        Types::Types ArgumentType;

        friend std::ostream& operator<<(std::ostream& flux, FonctionArgumentDef const& arg);
        friend bool operator==(FonctionArgumentDef const& arg1, FonctionArgumentDef const& arg2);
    };

    class FonctionDef {
    public:
        std::string FonctionName;
        Types::Types FonctionType;
        std::vector<FonctionArgumentDef> FonctionArguments;
        std::vector<std::string> FonctionContentCode;
        int FonctionNumberArgument = 0;

        friend std::ostream& operator<<(std::ostream& flux, FonctionDef const& var);

        bool isArgument(FonctionArgumentDef const& argument);
    };
}