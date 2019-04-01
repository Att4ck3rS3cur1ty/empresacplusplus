#ifndef EMPRESA_H
#define EMPRESA_H
#include "date.h"
#include "funcionario.h"
#include <string>
#include <list>

class empresa{
	private:
		std::string nome_;
		std::string cnpj_;
	public:
		void setNome(std::string nome);
		void setCnpj(std::string cnpj);
		std::string getNome();
		std::string getCnjp();
		empresa(); 
};
#endif