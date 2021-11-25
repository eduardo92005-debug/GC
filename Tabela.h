#ifndef TABELA_H_
#define TABELA_H_
#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <numeric>
#include <stdlib.h>

namespace std{
	class Tabela {
		private:
			string _fname;
			Data _data;
			int _col_num;
			int _lin_num;
			bool _exibe_info=true;
		public:
			Tabela();
			virtual ~Tabela();
			void armazenaTabela(bool show_success);
			string getFicheiroNome();
			int getTamanhoColunas();
			vector<string> getColunas();
			int getLinhasTamanho();
			vector<string> getColunaPorIndice(int indice);
			vector<string> getLinhaPorIndice(int indice);
			string selecionaCelula(int col_indice, int linha_indice);
			int totalPeloIndiceColuna(int indice);
			friend ostream &operator<<(ostream &output, Tabela &csv);
			bool getExibeInfo();
			void setExibeInfo(bool novo_exibe_info);
			
	};
}
#endif

