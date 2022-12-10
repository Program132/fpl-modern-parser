#include <string>
#include <iostream>
#include <string_view>
#include <vector>
#include <map>
#include <optional>

#include "../Statement.h"
#include "../Tokenizer.h"
#include "../Types.h"

#include "Data.h"

using namespace FPL;
using namespace FPL::Tokenizer;

std::optional<Statement::Statement> ExpectValue(FPL::Data::Data& data);
std::optional<Types::Types> ExpectType(FPL::Data::Data& data);
std::optional<Token> ExpectOperator(FPL::Data::Data& data, std::string_view name = std::string());
std::optional<Token> ExpectIdentifiant(FPL::Data::Data& data, std::string_view name = std::string());