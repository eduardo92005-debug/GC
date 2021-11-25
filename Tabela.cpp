#include "Tabela.h"


namespace std{
	Tabela::Tabela() {
		cout << "Digite o nome do arquivo .csv que deseja ler!"<< endl;
		cin >> _fname;
	}
	
	//Operator overloading sobrecarga do operador << do cout
	//Mostra o total de todas colunas
	ostream &operator<<(ostream &output, Tabela &csv){
			int tam_colunas = csv.getTamanhoColunas();
			for(int column=1;column < tam_colunas;column++)
			{
				csv.totalPeloIndiceColuna(column);
			} 
		return output;
	}
	
	//Armazena na memoria a tabela
	void Tabela::armazenaTabela(bool show_sucess) {
		string line,word;
		ifstream file ((this->_fname).c_str());
		if(file.is_open())
			{
				while(getline(file, line))
				{
					this->_data.vlinha.clear();
					stringstream str(line);
		 			this->_lin_num++;
					while(getline(str, word, ','))
						this->_data.vlinha.push_back(word);
					this->_data.conteudo.push_back(this->_data.vlinha);
				}
			this->_col_num = this->_data.vlinha.size();
			if(show_sucess == true)
				cout << " Sucesso! Conteudo foi armazenado em memoria!" << endl;
			}
		else
			cout<<"Nao pode abrir o arquivo\n";
			system("pause");
	}
	
	/* DESCARTAR
	//Mostra e retorna atraves de um vector str os valores 
	/*vector<string> Tabela::getColumns(){
		vector<string> temp_data; 
			for(int column=1;column < (this->_data.content).size();column++)
			{
				if(this->show_info == true)
					cout << this->_data.content[0][column] << "\t" << endl;
				cout << column<<endl;
	
			}
			cout << "OLA";
			return temp_data;
	} */
	//Retorna a quantidade de colunas na tabela
	string Tabela::selecionaCelula(int col_indice, int linha_indice){
		vector<vector<string> >& temp_content =  this->_data.conteudo;
		return temp_content[linha_indice][col_indice];
	}
	int Tabela::getTamanhoColunas(){
		return this->_col_num;
	} 
	
	//Retorna todas colunas da tabela dentro de um vector
	vector<string> Tabela::getColunas(){
		vector<string> temp_data; 
		int length_col = this->getTamanhoColunas();
		for(int column=0;column < length_col;column++)
		{
			string& temp_content =  this->_data.conteudo[0][column]; //Apelido temp_conteudo para (this->_data.conteudo[0][column]
			if(this->_exibe_info == true)
				cout << temp_content << "\t" << endl;
			temp_data.push_back(temp_content);

		}
		return temp_data;
	}
	//Retorna o total acumulado pelos valores da coluna
	int Tabela::totalPeloIndiceColuna(int indice)
	{
		vector<int> temp_vint;
		string& header = this->_data.conteudo[0][indice];
		long int sum;
		const int length_data = this->_data.conteudo.size();
		for(int column=1;column < length_data;column++)
			{
				string& temp_cont = this->_data.conteudo[column][indice];
				temp_vint.push_back(stol(temp_cont));
			}
			sum = accumulate(temp_vint.begin(),temp_vint.end(),0);
			cout << "Total de "<< header << ": " << sum << endl;
		return sum;
	}
	//retorna as linhas de uma tabela
	int Tabela::getLinhasTamanho(){
		return this->_lin_num;
	}
	//Retorna valores da uma coluna pelo indice dela
	vector<string> Tabela::getColunaPorIndice(int indice){
		vector<string> temp_data; 
		int tam_linha = this->getLinhasTamanho();
		for(int linha=0;linha < tam_linha;linha++)
		{
			string& temp_cont =  this->_data.conteudo[linha][indice]; //Apelido temp_content para (this->_data.content[column][indice]
			if(this->_exibe_info == true)
				cout << temp_cont << "\t" << endl;
			temp_data.push_back(temp_cont);
		}
		return temp_data;
		
	}
	//Retorna valores de uma linha por um indice
	vector<string> Tabela::getLinhaPorIndice(int indice){
		vector<string> temp_data; 
		int tam_coluna = this->getTamanhoColunas();
		for(int col=0;col < tam_coluna;col++)
		{
			string& temp_cont =  this->_data.conteudo[indice][col]; //Apelido temp_content para (this->_data.content[column][indice]
			if(this->_exibe_info == true)
				cout << temp_cont << "\t" << endl;
			temp_data.push_back(temp_cont);
		}
		return temp_data;
		
	}
	
	bool Tabela::getExibeInfo(){
		return this->_exibe_info;
	}
	void Tabela::setExibeInfo(bool novo_exibe_info){
		this->_exibe_info = novo_exibe_info;
	}
	string Tabela::getFicheiroNome(){
		return _fname;
	}
	Tabela::~Tabela() {
		//Destructor
	}
}

/* TESTA CLASSE TABELA 
AO UTILIZAR A CLASSE LEMBRAR DE SEMPRE CRIAR UM OBJETO E UTILIZAR A FUNCAO ARMAZENATABELA
using namespace std;
int main(){
	Tabela csv;
	csv.armazenaTabela(true); //OK
	//csv.getColunas(); OK
	//csv.getColunaPorIndice(3); OK
	//csv.getLinhaPorIndice(3); OK
	//cout << csv.getLinhasTamanho() << endl; OK
	//cout << csv.getTamanhoColunas() << endl; OK
	//csv.totalPeloIndiceColuna(3); OK
	//cout << csv.selecionaCelula(3,5); OK
	/*  AO USAR METODOS QUE RECUPERAM DADOS QUE UTILIZA-SE COLUNA E LINHAS LEMBRAR QUE COMECA-SE A CONTAR A PARTIR DO INDICE 0*/
//}

