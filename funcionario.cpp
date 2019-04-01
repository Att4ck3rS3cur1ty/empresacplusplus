#include "funcionario.h"
#include "date.h"
#include <iostream>
#include <string>
using namespace std;

funcionario::funcionario(){
	cnpj_empresa_ = "";
	nome_ = "";
	salario_ = 0;	
}

void funcionario::setCnpjEmpresa(string cnpj){funcionario::cnpj_empresa_ = cnpj;};

void funcionario::setNome(string nome){funcionario::nome_ = nome;};

void funcionario::setSalario(double salario){funcionario::salario_ = salario;};

void funcionario::setDataAdmissao(const int& d, const int& m, const int& y){
	date dt;
	dt.setday(d);
	dt.setmonth(m);
	dt.setyear(y);
};

string funcionario::getCnpjEmpresa(){ return cnpj_empresa_;};

double funcionario::getSalario(){ return salario_;};

string funcionario::getNome(){ return nome_; }

string funcionario::getDataAdmissao(){ 
	date dt;
	string* dt_str = new string[3];
	// conversão em string
	dt_str[0] = to_string(dt.day());
	dt_str[1] = to_string(dt.month());
	dt_str[2] = to_string(dt.year());

	return dt_str[0] + "/" + dt_str[1] + "/" + dt_str[2];
};

bool operator == (funcionario& f1, funcionario& f2){
	if((f1.getCnpjEmpresa() == f2.getCnpjEmpresa()) && (f1.getSalario() == f2.getSalario()) && 
		(f1.getNome() == f2.getNome()) && (f1.getDataAdmissao() == f2.getDataAdmissao()))
		return true;
	return false;
}

/*
bool operator == (funcionario f2){
	if((this->getCnpjEmpresa() == f2.getCnpjEmpresa()) && (this->getSalario() == f2.getSalario()) && 
		(this->getNome() == f2.getNome()) && (this->getDataAdmissao() == f2.getDataAdmissao()))
		return true;
	return false;
}*/

/*
bool operator == (funcionario f2){
	return ((this->getCnpjEmpresa() == f2.getCnpjEmpresa()) && (this->getSalario() == f2.getSalario()) && 
		(this->getNome() == f2.getNome()) && (this->getDataAdmissao() == f2.getDataAdmissao()))
		
}
*/