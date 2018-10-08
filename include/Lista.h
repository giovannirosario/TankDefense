#ifndef _LISTA_H_
#define _LISTA_H_

template <class T_data> 
class Lista {
	public:
		struct Item {
			T_data data;
			Item* next;
		};

	private:
		Item* fim;
		Item* busca;

	public:
		Item* inicio;
		Item* aux;
		Item* aux2;
		
		Lista();
		~Lista();
		void insert(T_data x);
		void remove(Item* destroy);
		bool isEmpty();

};	


#include "Lista.inl"
#endif