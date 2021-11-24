#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include <string>
#include <vector>
#include "TableCSV.h"

namespace std {
	class Menu {
		private:
			TableCSV _tabela;
			
		public:
			Menu();
			void mostrarTabela();
			int exibeTotalVacinadas();
			int exibeMediaVacinadasParcialmente();
			int exibeMaiorQuantidadeDose();
			vector<string> exibeCincoDatasMaiorAplicacaoVacina();
	};
}
#endif
