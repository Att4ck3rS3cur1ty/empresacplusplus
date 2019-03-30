#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
#include "date.h"

class funcionario{
	private:
		std::string nome_;
		double salario_;
		int dia_;
		int mes_;
		int ano_;
	public:
		void setNome(std::string nome);				
		void setSalario(double salario);
		date setDataAdmissao(const int& d, const int& m, const int& y);
		std::string getNome();
		double getSalario();
		date getDataAdmissao();
		funcionario();
};

#endif
