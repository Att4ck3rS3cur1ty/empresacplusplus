#include "funcionario.h"
#include "empresa.h"
#include "date.h"
#include <string>
#include <list>

class controller{
	private:
		std::list<funcionario> lst_funcionarios;
		std::list<empresa> lst_empresas; 
	public:
		void addFuncionario(); // criar um novo funcionário
		void listarFuncionariosEmpresa(int id_empresa); // listar todos os funcionários de uma empresa
		void aumentoSalario(); // aumentar o salário de todos, em %
		void funcionariosExp(); // listar os funcionários em experiência (com menos de 90 dias, considerando data atual)	
};