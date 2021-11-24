#include "Menu.h"
#include "TableCSV.h"
#include <stdlib.h>
namespace std{
	//Construtor
	Menu::Menu(){
		int opcao;
		cout << "Primeiro carregue na memoria o arquivo!"<<endl;
		cout << "CARREGANDO..." << endl;
		this->_tabela.storeTable(true);
		while(true){
			system("cls");
			cout << " Selecione uma opcao! " << endl;
			cout << "1 - Mostrar conteudo resumido da tabela (TOTAIS)" << endl;
			cout << "2 - Exibe total de pessoas vacinadas" << endl;
			cout << "3 - Exibe media de pessoas parcialmente vacinas" << endl;
			cout << "4 - Exibe 5 datas que tiveram maior aplicacao da segunda dose" << endl;
			cout << "5 - Exibe a maior quantidade de dose administrada" << endl;
			cin >> opcao;
			switch(opcao){
				case 1:
					this->mostrarTabela();
					break;
				case 2:
					this->exibeTotalVacinadas();
					break;
			}	
 		}
	}
	//Metodos
	void Menu::mostrarTabela(){
		cout << this->_tabela;
		system("pause");
	}
	int Menu::exibeTotalVacinadas(){
		TableCSV& tabela = this->_tabela;
		int resultado;
		resultado = tabela.totalPeloIndiceColuna(7);
		system("pause");
		return resultado;
	}
}

