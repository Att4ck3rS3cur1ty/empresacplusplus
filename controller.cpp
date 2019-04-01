#include "funcionario.h"
#include "empresa.h"
#include "date.h"
#include "controller.h"
#include <string>
#include <list>
#include <regex>
#include <time.h>
using namespace std;

const string controller::dataAtual(){
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}

int controller::extrairDia(string data){
	int dia;
	istringstream(data.substr(0, 2)) >> dia;	
	
	return dia;	
}

int controller::extrairMes(string data){
	int mes;
	istringstream(data.substr(3, 5)) >> mes;	
	
	return mes;	
}

int controller::extrairAno(string data){
	int ano;
	istringstream(data.substr(6)) >> ano;	
	
	return ano;	
}


int controller::validarData(string data_admissao, funcionario *novo){
	string data_atual = dataAtual();
	int* dia = new int[2];
	int* mes = new int[2];
	int* ano = new int[2];
	

/*
	// criação de inteiros para serem atribuídos a data atual e a de admissão, 
	// para verificar se a data não é maior do a corrente
	
	int* dia = new int[2];
	int* mes = new int[2];
	int* ano = new int[2];
	// a data atual ocupará o índice 0  

	istringstream(data_atual.substr(0, 2)) >> dia[0];
	istringstream(data_atual.substr(3, 5)) >> mes[0];
	istringstream(data_atual.substr(6)) >> ano[0];

	// a data de admissão terá o índice 1
	
	istringstream(data_admissao.substr(0, 2)) >> dia[1];
    istringstream(data_admissao.substr(3, 5)) >> mes[1];
    istringstream(data_admissao.substr(6)) >> ano[1];

    date d_atual(dia[0], mes[0], ano[0]);
    date d_admissao(dia[1], mes[1], ano[1]);
*/	
	dia[0] = extrairDia(data_atual);
	mes[0] = extrairDia(data_atual);
	ano[0] = extrairDia(data_atual);

	dia[1] = extrairDia(data_admissao);
	mes[1] = extrairDia(data_admissao);
	ano[1] = extrairDia(data_admissao);

	date d_atual(dia[0], mes[0], ano[0]);
    date d_admissao(dia[1], mes[1], ano[1]);

	regex reg("^([0-2][0-9]|(3)[0-1])(\\/)(((0)[0-9])|((1)[0-2]))(\\/)\\d{4}$");
	smatch matches;
	
    if(!regex_search(data_admissao, matches, reg)){
    	cout << "Data inválida!" << endl;
        return 0;
    }

    else{
      		if(!(d_admissao > d_atual) || ((extrairMes(data_admissao) == 02) && (extrairDia(data_admissao) > 29))){ // considerando ano bissexto, a data não pode ser > 29
       			//novo->setDataAdmissao(dia[1], mes[1], ano[1]);
    			cout << "Data inválida!" << endl;
    			return 0;
       		}
       		else{
       			novo->setDataAdmissao(extrairDia(data_admissao), extrairMes(data_admissao), extrairAno(data_admissao));
       			return 1;
       		}
    }
    
    return 0;
}

void controller::novoFuncionario(funcionario *novo){ // criar um novo funcionário
	 // 0 = não pertence a nenhuma empresa, pois nenhuma tem o id = 0
	string nome, data_admissao;
	double salario;

	cout << "\nNome do funcionário: ";
	fflush(stdin);
	cin >> nome;
    cout << endl;
	novo->setNome(nome);


	cout << "Salário: ";
	fflush(stdin);
	cin >> salario;
    cout << endl;
	novo->setSalario(salario);

	while(!(validarData(data_admissao, novo))){
		cout << "Data de admissão (dd/mm/aaaa): ";
		fflush(stdin);
		cin >> data_admissao;
    	fflush(stdin);
    	cout << endl;
	}
}; 

void controller::addFuncionario(string cnpj){ // alocar um funcionário a uma empresa
	string nome;
	double salario;
	list<funcionario> funcionarios;

	for (std::list<funcionarios>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++){
	 	it-> setCnpjEmpresa(cnpj);
	 	cout << "\nNome do funcionário: ";
	 	fflush(stdin);
	 	cin >> nome;
	 	it-> setNome(nome);
	 	cout << endl;

	 	cout << "Salário: ";
	 	fflush(stdin);
	 	cin >> salario;
	 	it-> setSalario(salario);
	 	cout << endl;
	}
}; 

void controller::listarFuncionariosEmpresa(string cnpj){ // listar todos os funcionários de uma empresa
	list<funcionario> funcionarios;
	for (std::list<funcionarios>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++){
		if(it->getCnpjEmpresa() == cnpj){
			cout << "\nNome: " << it->getNome() << endl;
			cout << "Salário: " << it->getSalario() << endl;
		}
	}
}; 
		
void controller::aumentoSalario(){ // aumentar o salário de todos, em %

}; 

void controller::funcionariosExp(){ // listar os funcionários em experiência (com menos de 90 dias, considerando data atual)	
	list<funcionario> funcionarios;
	int* dia = new int[2];
	int* mes = new int[2];
	int* ano = new int[2];

	dia[0] = extrairDia(dataAtual());
	mes[0] = extrairMes(dataAtual());
	ano[0] = extrairAno(dataAtual());
	
	date data_atual(dia[0], mes[0], ano[0]);

	for(list<funcionario>::iterator it = funcionarios.begin(); it != funcionarios.end(); it++){
		dia[1] = extrairDia(it->getDataAdmissao);
		mes[1] = extrairMes(it->getDataAdmissao);
		ano[1] = extrairAno(it->getDataAdmissao);

		date data_admissao(dia[1], mes[1], ano[1]);

		if(data_atual - data_admissao <= 90){
			std::cout << *it << ' ' << endl;		
		}
	}
}; 

void controller::novaEmpresa(empresa *novo){
	string nome, cnpj;
	cout << "\nNome da empresa: ";
	fflush(stdin);
	cin >> nome;
	cout << endl;
	novo->setNome(nome);
	
	while(!(validarCnpj(cnpj))){
		cout << "CNPJ: ";
		fflush(stdin);
		cin >> cnpj;
		cout << endl;
	}

	addFuncionario(cnpj);
}

int controller::validarCnpj(string cnpj){
	regex reg("[0-9]{2}\\.?[0-9]{3}\\.?[0-9]{3}\\/?[0-9]{4}\\-?[0-9]{2}");
	smatch matches;
	
    if(!regex_search(cnpj, matches, reg)){
    	cout << "CNPJ inválido!" << endl;
        return 0;
    }

    else return 1;
}