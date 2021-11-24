#ifndef TABLECSV_H_
#define TABLECSV_H_
#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <numeric>
#include <stdlib.h>

namespace std{
	class TableCSV {
		private:
			string _fname;
			Data _data;
			int _col_num;
			int _lin_num;
			bool _show_info=true;
		public:
			TableCSV();
			void storeTable(bool show_success);
			string getFicheiroNome();
			int getTamanhoColunas();
			vector<string> getColunas();
			int getLinhas();
			vector<string> getColunaPorIndice(int indice);
			int totalPeloIndiceColuna(int indice);
			friend ostream &operator<<(ostream &output, TableCSV &csv);
	};
}
#endif

