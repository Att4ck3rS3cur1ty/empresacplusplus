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

int controller::validarData(string data_admissao, funcionario *novo){
	string data_atual = dataAtual();
	
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
	
	regex reg("^([0-2][0-9]|(3)[0-1])(\\/)(((0)[0-9])|((1)[0-2]))(\\/)\\d{4}$");
	smatch matches;
	
    if(!regex_search(data_admissao, matches, reg)){
    	cout << "Data inválida!" << endl;
        return 0;
    }

    else{
    
       		if(!(d_admissao > d_atual) || (mes[1] == 02 && dia[1] > 29)){ // considerando ano bissexto, a data não pode ser > 29
       			novo->setDataAdmissao(dia[1], mes[1], ano[1]);
    			cout << "Data inválida!" << endl;
    			return 0;
       		}
       		else return 1;
    }
    
    return 0;
}


void controller::novoFuncionario(funcionario *novo){ // criar um novo funcionário
	; // 0 = não pertence a nenhuma empresa, pois nenhuma tem o id = 0
	string nome, data_admissao;
	double salario;

	cout << "Nome: ";
	fflush(stdin);
	cin >> nome;
    cout << endl;
	novo->setNome(nome);


	cout << "Salário: ";
	fflush(stdin);
	cin >> salario;
    cout << endl;
	novo->setSalario(salario);

	bool data_valida = false;

	while(!data_valida){
		cout << "Data de admissão (dd/mm/aaaa): ";
		fflush(stdin);
		cin >> data_admissao;
    	fflush(stdin);
    	cout << endl;

    	if(validarData(data_admissao, novo)){
    		data_valida = true;
    	}
	}	
}; 

void controller::addFuncionario(){ // alocar um funcionário a uma empresa

}; 

void controller::listarFuncionariosEmpresa(int id_empresa){ // listar todos os funcionários de uma empresa

}; 
		
void controller::aumentoSalario(){ // aumentar o salário de todos, em %

}; 

void controller::funcionariosExp(){ // listar os funcionários em experiência (com menos de 90 dias, considerando data atual)	

}; 

void controller::novaEmpresa(empresa *novo){

}