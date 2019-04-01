#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "funcionario.h"
#include "empresa.h"
#include "date.h"
#include <string>
#include <list>
#include <regex>
#include <time.h>

class controller{
	private:
		std::list<funcionario> lst_funcionarios;
		std::list<empresa> lst_empresas; 
	public:
		const std::string dataAtual(); // obter a data atual no format dd/mm/aaaa
		int validarData(string str, funcionario *novo); // validar a data através de expressão regular
		void novoFuncionario(funcionario *f); // criar um novo funcionário
		void addFuncionario(string cnpj); // alocar um funcionário a uma empresa
		void listarFuncionariosEmpresa(string cnpj); // listar todos os funcionários de uma empresa
		void aumentoSalario(); // aumentar o salário de todos, em %
		void funcionariosExp(); // listar os funcionários em experiência (com menos de 90 dias, considerando data atual)	
		void novaEmpresa(empresa *novo); // criar uma nova empresa
		int validarCnpj(string cnpj);
		int extrairDia(string data);
		int extrairMes(string data);
		int extrairAno(string data);
};

#endif