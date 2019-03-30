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
		std::list<funcionario> lst_funcionarios; 
	public:
		void setNome(std::string nome);
		void setCnpj(std::string cnpj);
		void addFuncionario(); // adicionar funcionário
		void listarFuncionarios(); // listar todos os funcionários de uma empresa
		void aumentoSalario(); // aumentar o salário de todos, em %
		void funcionariosExp(); // listar os funcionários em experiência (com menos de 90 dias, considerando data atual)
		std::string getNome();
		std::string getCnjp();
		empresa(int i); 
};

#endif