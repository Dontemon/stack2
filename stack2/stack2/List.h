#ifndef _List_h
#define _List_h


template<typename T>
class List
{
public:
	List() = default;//конструктор по умолчанию
	List(const List& other);//конструктор копирования
	~List();//деструктор

	T front() const;//
	T back() const;//

	bool empty() const;//проверка на пустоту списка
	unsigned size() const;//выдаёт колличество элементов списка
	void clear();//чистит весь список

	void push_front(const T& value);//вставка в голову
	void pop_front();//удаление из головы
	void push_back(const T& value);//вставка в хвост
	void pop_back();//удаление из хвоста

	List& operator = (const List& other);//оператор присваевания

private:
	struct Node
	{
		T data;
		Node* next = nullptr;
		Node* prev = nullptr;

		Node(const T& data)
		{
			this->data = data;//конструктор
		}

		Node(const Node& other)//конструктор по умолчанию
		{
			data = other.data;
		}
	};

	Node* head = nullptr;
	Node* tail = nullptr;
};


template<typename T>
List<T>::List(const List& other)
{
	if (!other.head)//проверяем существует ли other
		return;

	head = new Node(*other.head);//перевыделяем память под голову
	tail = head;
	Node* head_ptr = head;//создаем казатель на голову
	for (Node* tmp = other.head->next; tmp != nullptr; tmp = tmp->next, head_ptr = head_ptr->next) {
		head_ptr->next = new Node(*tmp); //выделяем память
		tail = head_ptr->next;
		tail->prev = head_ptr;
	}
}

template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
T List<T>::front() const
{
	return head->data;//возвращаем значение из головы
}

template<typename T>
T List<T>::back() const
{
	return tail->data;//возвращаем значение из хвоста
}

template<typename T>
bool List<T>::empty() const
{
	return head == nullptr;//если головы нет, то и списка нет
}

template<typename T>
unsigned List<T>::size() const
{
	unsigned counter = 0;
	for (Node* tmp = head; tmp != nullptr; tmp = tmp->next) {
		++counter;
	}
	return counter;
}

template<typename T>
void List<T>::clear()
{
	for (Node* tmp = head; head != nullptr; tmp = head) {
		head = head->next;//меняем голову
		delete tmp;//удаляем "старую" голову
	}
	tail = nullptr;
}

template<typename T>
void List<T>::push_back(const T& value)
{
	if (head != nullptr) {//если голова есть
		tail->next = new Node(value);//выделяем память под узел
		tail->next->prev = tail;//заменяем старый хвост на новый
		tail = tail->next;//переопределям хвост, так как добавился новый элемент	
	}
	else {//если головы нет, то голова и хвост совпадают
		tail = new Node(value);
		head = tail;
	}
}

template<typename T>
void List<T>::pop_back()
{
	if (empty())//если список пустой, то ничего не возвращаем
		return;

	if (head == tail) {//если в списке один элемент
		delete tail;//удаляем хвост
		head = tail = nullptr;
	}
	else {
		tail = tail->prev;//переприсваеваем хвост
		delete tail->next;//удаляем хвост
		tail->next = nullptr;
	}
}

template<typename T>
void List<T>::push_front(const T& value)
{
	if (head != nullptr) {
		head->prev = new Node(value);//выделяем память и создаем новый узел перед головой
		head->prev->next = head;//этот узел объявляем головой
		head = head->prev;
	}
	else {
		head = new Node(value);//если головы не существует, просто создаем её
		tail = head;
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (empty())//если список пустой, ничего не делаем
		return;

	if (head == tail) {//если голова и хвост это один и тот же узел, то просто удаляем голову
		delete head;
		head = tail = nullptr;
	}
	else {
		head = head->next;//переопределяем голову
		delete head->prev;//удаляем "старую" голову
		head->prev = nullptr;
	}
}


template<typename T>
List<T>& List<T>::operator = (const List& other)
{
	if (this == &other)//если списки равны, то возвращаем наш список
		return *this;

	clear();//если не равны, то сначала чистим наш список

	head = new Node(*other.head);//создаем голову
	tail = head;//объявляем хвост
	Node* head_ptr = head;//создаем указатель на голову
	for (Node* tmp = other.head->next; tmp != nullptr; tmp = tmp->next, head_ptr = head_ptr->next) {
		head_ptr->next = new Node(*tmp);//выделяем память под новый элемент
		tail = head_ptr->next;//заполняем наш список, элементами списка other
		tail->prev = head_ptr;
	}

	return *this;
}
#endif