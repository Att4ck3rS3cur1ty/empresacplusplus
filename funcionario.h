#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
#include "date.h"

class funcionario{
	private:
		string cnpj_empresa_; 
		std::string nome_;
		double salario_;
	public:
		void setCnpjEmpresa(string cnpj);
		void setNome(std::string nome);				
		void setSalario(double salario);
		void setDataAdmissao(const int& d, const int& m, const int& y);
		string getCnpjEmpresa();
		std::string getNome();
		double getSalario();
		string getDataAdmissao();
		funcionario(int i);
		funcionario();
		bool operator == (funcionario&);
};

#endif
