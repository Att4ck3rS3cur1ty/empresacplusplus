#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
#include "date.h"

class funcionario{
	private:
		int id_empresa_; 
		std::string nome_;
		double salario_;
	public:
		void setIdEmpresa(int id);
		void setNome(std::string nome);				
		void setSalario(double salario);
		void setDataAdmissao(const int& d, const int& m, const int& y);
		int getIdEmpresa();
		std::string getNome();
		double getSalario();
		string getDataAdmissao();
		funcionario();
};

#endif
