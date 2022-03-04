#ifndef _List_h
#define _List_h


template<typename T>
class List
{
public:
	List() = default;//êîíñòðóêòîð ïî óìîë÷àíèþ
	List(const List& other);//êîíñòðóêòîð êîïèðîâàíèÿ
	~List();//äåñòðóêòîð

	T front() const;//
	T back() const;//

	bool empty() const;//ïðîâåðêà íà ïóñòîòó ñïèñêà
	unsigned size() const;//âûäà¸ò êîëëè÷åñòâî ýëåìåíòîâ ñïèñêà
	void clear();//÷èñòèò âåñü ñïèñîê

	void push_front(const T& value);//âñòàâêà â ãîëîâó
	void pop_front();//óäàëåíèå èç ãîëîâû
	void push_back(const T& value);//âñòàâêà â õâîñò
	void pop_back();//óäàëåíèå èç õâîñòà

	List& operator = (const List& other);//îïåðàòîð ïðèñâàåâàíèÿ

private:
	struct Node
	{
		T data;
		Node* next = nullptr;
		Node* prev = nullptr;

		Node(const T& data)
		{
			this->data = data;//êîíñòðóêòîð
		}

		Node(const Node& other)//êîíñòðóêòîð ïî óìîë÷àíèþ
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
	if (!other.head)//ïðîâåðÿåì ñóùåñòâóåò ëè other
		return;

	head = new Node(*other.head);//ïåðåâûäåëÿåì ïàìÿòü ïîä ãîëîâó
	tail = head;
	Node* head_ptr = head;//ñîçäàåì êàçàòåëü íà ãîëîâó
	for (Node* tmp = other.head->next; tmp != nullptr; tmp = tmp->next, head_ptr = head_ptr->next) {
		head_ptr->next = new Node(*tmp); //âûäåëÿåì ïàìÿòü
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
	return head->data;//âîçâðàùàåì çíà÷åíèå èç ãîëîâû
}

template<typename T>
T List<T>::back() const
{
	return tail->data;//âîçâðàùàåì çíà÷åíèå èç õâîñòà
}

template<typename T>
bool List<T>::empty() const
{
	return head == nullptr;//åñëè ãîëîâû íåò, òî è ñïèñêà íåò
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
		head = head->next;//ìåíÿåì ãîëîâó
		delete tmp;//óäàëÿåì "ñòàðóþ" ãîëîâó
	}
	tail = nullptr;
}

template<typename T>
void List<T>::push_back(const T& value)
{
	if (head != nullptr) {//åñëè ãîëîâà åñòü
		tail->next = new Node(value);//âûäåëÿåì ïàìÿòü ïîä óçåë
		tail->next->prev = tail;//çàìåíÿåì ñòàðûé õâîñò íà íîâûé
		tail = tail->next;//ïåðåîïðåäåëÿì õâîñò, òàê êàê äîáàâèëñÿ íîâûé ýëåìåíò	
	}
	else {//åñëè ãîëîâû íåò, òî ãîëîâà è õâîñò ñîâïàäàþò
		tail = new Node(value);
		head = tail;
	}
}

template<typename T>
void List<T>::pop_back()
{
	if (empty())//åñëè ñïèñîê ïóñòîé, òî íè÷åãî íå âîçâðàùàåì
		return;

	if (head == tail) {//åñëè â ñïèñêå îäèí ýëåìåíò
		delete tail;//óäàëÿåì õâîñò
		head = tail = nullptr;
	}
	else {
		tail = tail->prev;//ïåðåïðèñâàåâàåì õâîñò
		delete tail->next;//óäàëÿåì õâîñò
		tail->next = nullptr;
	}
}

template<typename T>
void List<T>::push_front(const T& value)
{
	if (head != nullptr) {
		head->prev = new Node(value);//âûäåëÿåì ïàìÿòü è ñîçäàåì íîâûé óçåë ïåðåä ãîëîâîé
		head->prev->next = head;//ýòîò óçåë îáúÿâëÿåì ãîëîâîé
		head = head->prev;
	}
	else {
		head = new Node(value);//åñëè ãîëîâû íå ñóùåñòâóåò, ïðîñòî ñîçäàåì å¸
		tail = head;
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (empty())//åñëè ñïèñîê ïóñòîé, íè÷åãî íå äåëàåì
		return;

	if (head == tail) {//åñëè ãîëîâà è õâîñò ýòî îäèí è òîò æå óçåë, òî ïðîñòî óäàëÿåì ãîëîâó
		delete head;
		head = tail = nullptr;
	}
	else {
		head = head->next;//ïåðåîïðåäåëÿåì ãîëîâó
		delete head->prev;//óäàëÿåì "ñòàðóþ" ãîëîâó
		head->prev = nullptr;
	}
}


template<typename T>
List<T>& List<T>::operator = (const List& other)
{
	if (this == &other)//åñëè ñïèñêè ðàâíû, òî âîçâðàùàåì íàø ñïèñîê
		return *this;

	clear();//åñëè íå ðàâíû, òî ñíà÷àëà ÷èñòèì íàø ñïèñîê

	head = new Node(*other.head);//ñîçäàåì ãîëîâó
	tail = head;//îáúÿâëÿåì õâîñò
	Node* head_ptr = head;//ñîçäàåì óêàçàòåëü íà ãîëîâó
	for (Node* tmp = other.head->next; tmp != nullptr; tmp = tmp->next, head_ptr = head_ptr->next) {
		head_ptr->next = new Node(*tmp);//âûäåëÿåì ïàìÿòü ïîä íîâûé ýëåìåíò
		tail = head_ptr->next;//çàïîëíÿåì íàø ñïèñîê, ýëåìåíòàìè ñïèñêà other
		tail->prev = head_ptr;
	}

	return *this;
}
#endif