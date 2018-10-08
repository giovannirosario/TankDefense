#ifndef _FILA_H_
#define _FILA_H_

template <class T_data> 
class Fila {
	private:
		struct Item {
			T_data data;
			Item* next;
		};

		Item Head;
		Item* aux;

	public:
		Item* inicio;
		Item* busca;

		Fila();
		~Fila();
		void insert(T_data x);
		T_data remove();
		bool isEmpty();
};


#include "Fila.inl"
#endif