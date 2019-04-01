#include "funcionario.h"
#include "date.h"
#include <iostream>
#include <string>
using namespace std;

funcionario::funcionario(int i):id_empresa_(i), nome_(""), salario_(0){}

funcionario::funcionario(){
	id_empresa_ = 0;
	nome_ = "";
	salario_ = 0;	
}

void funcionario::setIdEmpresa(int id){funcionario::id_empresa_ = id;};

void funcionario::setNome(string nome){funcionario::nome_ = nome;};

void funcionario::setSalario(double salario){funcionario::salario_ = salario;};

void funcionario::setDataAdmissao(const int& d, const int& m, const int& y){
	date dt;
	dt.setday(d);
	dt.setmonth(m);
	dt.setyear(y);
};

int funcionario::getIdEmpresa(){ return id_empresa_;};

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
	if((f1.getIdEmpresa() == f2.getIdEmpresa()) && (f1.getSalario() == f2.getSalario()) && 
		(f1.getNome() == f2.getNome()) && (f1.getDataAdmissao() == f2.getDataAdmissao()))
		return true;
	return false;
}

/*
bool operator == (funcionario f2){
	if((this->getIdEmpresa() == f2.getIdEmpresa()) && (this->getSalario() == f2.getSalario()) && 
		(this->getNome() == f2.getNome()) && (this->getDataAdmissao() == f2.getDataAdmissao()))
		return true;
	return false;
}*/

/*
bool operator == (funcionario f2){
	return ((this->getIdEmpresa() == f2.getIdEmpresa()) && (this->getSalario() == f2.getSalario()) && 
		(this->getNome() == f2.getNome()) && (this->getDataAdmissao() == f2.getDataAdmissao()))
		
}
*/