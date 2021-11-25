#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include <string>
#include <vector>
#include "Tabela.h"
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <algorithm>

/* CLASSE PARA GERENCIAR O MENU DE OPCOES*/
namespace std {
	class Menu {
		private:
			Tabela _tabela;
			
		public:
			Menu();
			virtual ~Menu();
			void mostrarTabela();
			int exibeTotalVacinadas();
			double exibeMediaVacinadasParcialmente();
			int exibeMaiorQuantidadeDose();
			vector<string> exibeCincoDatasMaiorAplicacaoVacina();
	};
}
#endif
