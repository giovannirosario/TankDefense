#include <iostream>

template <class T_data> 
Lista<T_data>::Lista (){
	inicio = nullptr;
	fim = nullptr;
	busca = nullptr;
	aux = nullptr;
}

template <class T_data> 
Lista<T_data>::~Lista(){}


template <class T_data> 
void Lista<T_data>::insert(T_data x) {
	Item* novo = new Item;
	novo->data = x;
	novo->next = nullptr;

	if (inicio == nullptr) {
		inicio = novo;
	}

	else {
		Item* busca = inicio;
		while (busca->next != nullptr) {
			busca = busca->next;
		}

		busca->next = novo;
	}

	fim = novo;
	busca = nullptr;
}

		
template <class T_data> 
void Lista<T_data>::remove(Item* destroy) {
	if (destroy == inicio) {
		inicio = destroy->next;
		delete destroy;
	}

	else {
		busca = inicio;
		while (busca != nullptr && busca->next != destroy) {
			busca = busca->next;
		}

		if(busca != nullptr && busca->next == destroy) {
			busca->next = destroy->next;
			delete destroy;
		}	
	}
}


template <class T_data> 
bool Lista<T_data>::isEmpty() {
	if(inicio == nullptr)
		return true;
	else
		return false;
}
