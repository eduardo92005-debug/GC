#ifndef DATA_H_
#define DATA_H_
#include <iostream>
#include <string>
#include <vector>

namespace std{
	class Data {
		public:
			vector<string> vlinha;
			vector<vector<string> > conteudo;
			int getConteudoTamanho();
	};
}
#endif

