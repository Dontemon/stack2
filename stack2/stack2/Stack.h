#ifndef _Stack_h
#define _Stack_h

#include "List.h"
#include "EStackEmpty.h"

template<typename T>
class Stack
{
public:
	Stack();//êîíñòðóêòîð ïî óìîë÷àíèþ
	Stack(const Stack& other);//êîíñòðóêòîð êîïèðîâàíèÿ
	~Stack();//äåñòðóêòîð

	T top() const;//âîçâðàùàåò çíà÷åíèå âåðõíåãî ýëåìåíòà
	bool empty() const;//ïðîâåðêà íà ïóñòîòó
	unsigned size() const;//âîçâðàùàåò êîëëè÷åñòâî ýëåìåíòîâ â ñòýêå

	void push(T value);//äîáàâëåíèå ýëåìåíòà â ñòýê
	void pop();//óäàëåíèå ýëåìåíòà èç ñòýêà

	Stack& operator = (const Stack& other);//îïåðàòîð ïðèñâàåíèÿ

private:
	List<T>* list;
};


template<typename T>
Stack<T>::Stack()
{
	list = new List<T>;//ñîçäàåì ñïèñîê äëÿ ôîðìèðîâàíèÿ ñòýêà

}


template<typename T>
Stack<T>::Stack(const Stack& other)
{
	list = new List<T>(*other.list);//÷åðåç êîíñòðóêòîð êîïèðîâàíèÿ ñïèñêà, êîïèðóåì ñòýê

}


template<typename T>
Stack<T>::~Stack()
{
	delete list;//óäàëÿåì ñïèñîê
}


template<typename T>
T Stack<T>::top() const
{
	if (list->empty())//åñëè ñòýê ïóñòîé, òî âûêèäûâàåì èñêëþ÷åíèå
		throw EStackEmpty();

	return list->back();//âûâîäèì õâîñò ñïèñêà(õâîñò ñïèñêà ýòî âåðõíèé ýëåìåíò ñòýêà)
}

template<typename T>
bool Stack<T>::empty() const
{
	return list->empty();//ïðîâåðÿåì ïóñòîé ëè ñïèñîê
}

template<typename T>
unsigned Stack<T>::size() const
{
	return list->size();//âîçâðàùàåò êîëè÷åñòâî ýëåìåíòîâ â ñïèñêå(ñòýêå)
}

template<typename T>
void Stack<T>::push(T value)
{
	list->push_back(value);//âñòàâëÿåì ýëåìåíò â õâîñò ñïèñêà(èëè ïðîñòî äîáàâëÿåì ýëåìåíò â ñòýê)
}

template<typename T>
void Stack<T>::pop()
{
	if (list->empty())//åñëè ñòýê ïóñòîé, òî âîçâðàùàåì èñêëþ÷åíèå
		throw EStackEmpty();

	list->pop_back();//óäàëÿåì âåðõíèé ýëåìåíò ñòýêà
}

template<typename T>
Stack<T>& Stack<T>::operator = (const Stack& other)
{
	if (this == &other)//åñëè ñòýêè ñîâïàäàþò, òî âîçâðàùàåì íàø ñòýê
		return *this;

	delete list;//óäàëÿåì íàø ñòýê
	list = new List<T>(*other.list);//÷åðåç êîíñòðóêòîð êîïèðîâàíèÿ ñïèñêà, êîïèðóåì ñòýê

	return *this;
}

#endif