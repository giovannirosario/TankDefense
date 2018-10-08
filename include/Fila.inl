template <class T_data> 
Fila<T_data>::Fila (){
	Head.next = nullptr;
	inicio = nullptr;
	aux = nullptr;
}

template <class T_data> 
Fila<T_data>::~Fila(){}


template <class T_data> 
void Fila<T_data>::insert(T_data x) {
	Item* novo = new Item;
	novo->data = x;
	novo->next = nullptr;

	Item* busca = &Head;

	while (busca->next != nullptr) {
		busca = busca->next;
	}

	busca->next = novo;
	inicio = Head.next;
}


template <class T_data> 
T_data Fila<T_data>::remove() {
	if(Head.next != nullptr) {
		T_data x = inicio->data;
		aux = inicio->next;
		delete inicio;
		Head.next = aux;
		inicio = Head.next;
		return x;
	}
}


template <class T_data> 
bool Fila<T_data>::isEmpty() {
	if(Head.next == nullptr)
		return true;
	else
		return false;
}


