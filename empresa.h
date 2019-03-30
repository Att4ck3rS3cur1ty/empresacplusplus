#ifndef EMPRESA_H
#define EMPRESA_H
#include "date.h"
#include "funcionario.h"
#include <string>
#include <list>

class empresa{
	private:
		int id_; // incrementar o id quando criar outra empresa
		std::string nome_;
		std::string cnpj_;
	public:
		void setNome(std::string nome);
		void setCnpj(std::string cnpj);
		std::string getNome();
		std::string getCnjp();
		empresa(int i); 
};
#endif