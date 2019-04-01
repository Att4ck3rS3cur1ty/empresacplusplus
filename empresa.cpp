#include "funcionario.h"
#include "empresa.h"
#include "date.h"
#include <string>
#include <list>
using namespace std;

void empresa::setNome(string nome){empresa::nome_ = nome;};

void empresa::setCnpj(string cnpj){empresa::cnpj_ = cnpj;};


empresa::empresa(): nome_(""), cnpj_(""){}
