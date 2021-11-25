#ifndef DATA_H_
#define DATA_H_
#include <iostream>
#include <string>
#include <vector>

/* CLASSE PARA ARMAZENAR CONTEUDO DO CSV (Data se refere  a DADOS)*/
namespace std{
	class Data {
		public:
			virtual ~Data();
			vector<string> vlinha;
			vector<vector<string> > conteudo;
			int getConteudoTamanho();
	};
}
#endif

