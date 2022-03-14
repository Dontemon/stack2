#ifndef _Stack_h
#define _Stack_h

#include "List.h"
#include "EStackEmpty.h"

template<typename T>
class Stack
{
public:
	Stack();//конструктор по умолчанию
	Stack(const Stack& other);//конструктор копирования
	~Stack();//деструктор

	T top() const;//возвращает значение верхнего элемента
	bool empty() const;//проверка на пустоту
	unsigned size() const;//возвращает колличество элементов в стэке

	void push(T value);//добавление элемента в стэк
	void pop();//удаление элемента из стэка

	Stack& operator = (const Stack& other);//оператор присваения

private:
	List<T>* list;
};


template<typename T>
Stack<T>::Stack()
{
	list = new List<T>;//создаем список для формирования стэка

}


template<typename T>
Stack<T>::Stack(const Stack& other)
{
	list = new List<T>(*other.list);//через конструктор копирования списка, копируем стэк

}


template<typename T>
Stack<T>::~Stack()
{
	delete list;//удаляем список
}


template<typename T>
T Stack<T>::top() const
{
	if (list->empty())//если стэк пустой, то выкидываем исключение
		throw EStackEmpty();

	return list->back();//выводим хвост списка(хвост списка это верхний элемент стэка)
}

template<typename T>
bool Stack<T>::empty() const
{
	return list->empty();//проверяем пустой ли список
}

template<typename T>
unsigned Stack<T>::size() const
{
	return list->size();//возвращает количество элементов в списке(стэке)
}

template<typename T>
void Stack<T>::push(T value)
{
	list->push_back(value);//вставляем элемент в хвост списка(или просто добавляем элемент в стэк)
}

template<typename T>
void Stack<T>::pop()
{
	if (list->empty())//если стэк пустой, то возвращаем исключение
		throw EStackEmpty();

	list->pop_back();//удаляем верхний элемент стэка
}

template<typename T>
Stack<T>& Stack<T>::operator = (const Stack& other)
{
	if (this == &other)//если стэки совпадают, то возвращаем наш стэк
		return *this;

	delete list;//удаляем наш стэк
	list = new List<T>(*other.list);//через конструктор копирования списка, копируем стэк

	return *this;
}

#endif