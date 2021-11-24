#include "TableCSV.h"


namespace std{
	TableCSV::TableCSV() {
		cout << "Digite o nome do arquivo .csv que deseja ler!"<< endl;
		cin >> _fname;
	}
	
	//Operator overloading sobrecarga do operador << do cout
	//Mostra o total de todas colunas
	ostream &operator<<(ostream &output, TableCSV &csv){
			int tam_colunas = csv.getTamanhoColunas();
			for(int column=1;column < tam_colunas;column++)
			{
				csv.totalPeloIndiceColuna(column);
			} 
		return output;
	}
	
	void TableCSV::storeTable(bool show_sucess) {
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
	//Mostra e retorna atraves de um vector str os valores 
	/*vector<string> TableCSV::getColumns(){
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
	int TableCSV::getTamanhoColunas(){
		return this->_col_num;
	} 
	
	//Retorna todas colunas da tabela dentro de um vector
	vector<string> TableCSV::getColunas(){
		vector<string> temp_data; 
		int length_col = this->getTamanhoColunas();
		for(int column=0;column < length_col;column++)
		{
			string& temp_content =  this->_data.conteudo[0][column]; //Apelido temp_conteudo para (this->_data.conteudo[0][column]
			if(this->_show_info == true)
				cout << temp_content << "\t" << endl;
			temp_data.push_back(temp_content);

		}
		return temp_data;
	}
	int TableCSV::totalPeloIndiceColuna(int indice)
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
	int TableCSV::getLinhas(){
		return this->_lin_num;
	}
	//Retorna valores da uma coluna pelo indice dela
	vector<string> TableCSV::getColunaPorIndice(int indice){
		vector<string> temp_data; 
		int tam_linha = this->getLinhas();
		for(int column=0;column < tam_linha;column++)
		{
			string& temp_cont =  this->_data.conteudo[column][indice]; //Apelido temp_content para (this->_data.content[column][indice]
			if(this->_show_info == true)
				cout << temp_cont << "\t" << endl;
			temp_data.push_back(temp_cont);
		}
		return temp_data;
		
	}
	
	string TableCSV::getFicheiroNome(){
		return _fname;
	}
}

