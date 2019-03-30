#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
#include "date.h"

class funcionario{
	private:
		int id_; // incrementar o id quando chamar o método addFun...
		std::string nome_;
		double salario_;
	public:
		void setNome(std::string nome);				
		void setSalario(double salario);
		void setDataAdmissao(const int& d, const int& m, const int& y);
		int getId();
		std::string getNome();
		double getSalario();
		string getDataAdmissao();
		funcionario(int i);
};

#endif
