#include "Menu.h"

namespace std{
	//Construtor
	Menu::Menu(){
		int opcao;
		cout << "Primeiro carregue na memoria o arquivo!"<<endl;
		cout << "CARREGANDO..." << endl;
		this->_tabela.armazenaTabela(true);
		while(true){
			system("pause");
			system("cls");
			cout << " Selecione uma opcao! " << endl;
			cout << "1 - Mostrar conteudo resumido da tabela (TOTAIS)" << endl;
			cout << "2 - Exibe total de pessoas vacinadas" << endl;
			cout << "3 - Exibe media de pessoas parcialmente vacinas" << endl;
			cout << "4 - Exibe 5 datas que tiveram maior aplicacao da segunda dose" << endl;
			cout << "5 - Exibe a maior quantidade de dose administrada" << endl;
			cout << "6 - Sair" << endl;
			cin >> opcao;
			switch(opcao){
				case 1:
					this->mostrarTabela();
					break;
				case 2:
					this->exibeTotalVacinadas();
					break;
				case 3:
					this->exibeMediaVacinadasParcialmente();
					break;
				case 4:
					this->exibeCincoDatasMaiorAplicacaoVacina();
					break;
				case 5:
					this->exibeMaiorQuantidadeDose();
					break;
				case 6:
					exit(3);
					break;
				default:
					cout << " Opcao invalida! Tente novamente" << endl;
					break;
			}	
 		}
	}
	//Metodos
	void Menu::mostrarTabela(){
		cout << this->_tabela;
	}
		
	//EXIBE O TOTAL DE VACINADOS COMPLETAMENTE DOSE 1 E DOSE 2-> COLUNA: pessoas_vacinadas_completamente
	int Menu::exibeTotalVacinadas(){
		Tabela& tabela = this->_tabela;
		int resultado;
		resultado = tabela.totalPeloIndiceColuna(7);
		return resultado;
	}
	
	//EXIBE A MEDIA DOS VACINADOS PARCIALMENTE -> COLUNA: pessoas_vacinadas_parcialmente
	double Menu::exibeMediaVacinadasParcialmente(){
		Tabela& tabela = this->_tabela;
		const int resultado = tabela.totalPeloIndiceColuna(9);
		const int total_linhas = tabela.getLinhasTamanho();
		double media = resultado/total_linhas;
		cout << fixed << showpoint;
		cout << "Media de pessoas vacinadas parcialmente: " << setprecision(2) << media << endl;
		return media;
	}
	
	/* NOTOU-SE QUE OS DADOS DO CSV JA ESTAVAM ORDENADOS COMO JA ESTAO ORDENADOS, BASTOU  ARMAZENAR OS 5 MAIORES VALORES
	NUM VECTOR E MANIPULAR OS INDICES PARA OBTER AS DATAS CORRETAS
	TAMBEM, NOTOU-SE QUE O MAIOR VALOR EH O ULTIMO, COMO ESTAO ORDENADOS, ENTAO OS N-1 MAIORES PODEM SER OBTIDOS ATRAVES
	DO MAIOR ABSOLUTO UTILIZANDO-SE DA FUNCAO POP E DESCARTANDO CELULAR COM VALOR ZERO, ISTO EH, ARMAZENAR APENAS OS VALORES
	ORDENADOS DIFERENTE DE 0
	*/
	vector<string> Menu::exibeCincoDatasMaiorAplicacaoVacina(){
		Tabela& tabela = this->_tabela;
		tabela.setExibeInfo(false);
		vector<string> resultado = tabela.getColunaPorIndice(5);
		vector<int> maiores;
		int qntd_maiores;
		int tam_linhas = tabela.getLinhasTamanho();
		for (int i = tam_linhas; i != 0; i--){
			if(resultado.back() != "0"){
				maiores.push_back(i);
			}
			resultado.pop_back();
		}
		// Como no EXCEL comeca-se a contar a partir do 1 e no codigo comeca a partir do 0 eh necessario diminuir o valor 1 de cada selecao de celula
		//324 -> 325
		//322 -> 323
		//321 -> 322
		//320 -> 321
		cout <<"1 - Nessa determinada data a segunda dose aplicada foi maxima: " << tabela.selecionaCelula(0, maiores[0] - 1) << endl;
		cout <<"2 - Nessa determinada data a segunda dose aplicada foi maxima: " << tabela.selecionaCelula(0, maiores[1] - 1) << endl;
		cout <<"3 - Nessa determinada data a segunda dose aplicada foi maxima: " << tabela.selecionaCelula(0, maiores[2] - 1) << endl;
		cout <<"4 - Nessa determinada data a segunda dose aplicada foi maxima: " << tabela.selecionaCelula(0, maiores[3] - 1) << endl;
		cout <<"5 - Nessa determinada data a segunda dose aplicada foi maxima: " << tabela.selecionaCelula(0, maiores[4] - 1) << endl;
		tabela.setExibeInfo(true);
		
		return resultado;
	}
	
	int Menu::exibeMaiorQuantidadeDose() {
		Tabela& tabela = this->_tabela;
		tabela.setExibeInfo(false);
		vector<string> resultado = tabela.getColunaPorIndice(1);
		vector<int> temp_vint;
		int tam_resultado = resultado.size();
		for (int i = 1; i < tam_resultado; i++){
			temp_vint.push_back(stol(resultado[i]));
		}
		int max = *max_element(temp_vint.begin(), temp_vint.end());
		cout << "A maior quantidade foi: " << max << endl;
		tabela.setExibeInfo(true);
	}
	
	Menu::~Menu(){
		//DESTRUCTOR
	}
}

