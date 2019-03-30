#include "funcionario.h"
#include "date.h"
#include <iostream>
using namespace std;

void funcionario::setNome(string nome){funcionario::nome_ = nome;};

void funcionario::setSalario(double salario){funcionario::salario_ = salario;};

date funcionario::setDataAdmissao(const int& d; const int& m, const int& a){
	funcionario::dia_ = d; funcionario::mes_ = m; funcionario::ano_ = a;};

double funcionario::getSalario(){ return salario_;};

string funcionario::getNome(){ return nome_; }

date funcionario::getDataAdmissao(){ 
	return 	
};

funcionario::funcionario():nome_(""), salario_(0){}

