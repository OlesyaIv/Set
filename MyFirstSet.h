#pragma once
#include <iostream>
#include "interfaces3.h"

using namespace std;

template < class T > class MyFirstSet : public ISet < T >
{

private:

	int sizeset;  // Размер множества
	int capacity; //Вместимость
	T* set;  // Множество
	T* temp; //Временный массив

public:

	MyFirstSet();
	MyFirstSet(const MyFirstSet<T>& otherSet);
	MyFirstSet<T>& operator=(const MyFirstSet<T> & otherSet);
	virtual void add(const T& elem);
	virtual void remove(const T& elem);
	virtual bool contains(const T& elem) const;
	virtual int size() const;
	~MyFirstSet();
};

	template <class T> MyFirstSet<T>::MyFirstSet() //Конструктор
	{
		sizeset = 0;
		capacity = 10;
		set = new T[capacity];
	}

	template <class T> MyFirstSet<T>::MyFirstSet(const MyFirstSet<T>& otherSet)  //Конструктор копирования
	{
		sizeset = otherSet.sizeset;
		capacity = sizeset + 1;
		set1 = new T[capacity];
		for (int i = 0; i < sizeset; i++)
		{
			set1[i] = otherSet.set[i];
		}
	}

	template <class T>  MyFirstSet<T>& MyFirstSet<T>:: operator=(const MyFirstSet<T> & otherSet) //Оператор присваивания
	{
		if (this != &otherSet)
		{
			T* new_set = new T[otherSet.sizeset];
			copy(otherSet.set, otherSet.set + otherSet.sizeset, new_set);
			delete[] set;
			set = new_set;
			sizeset = otherSet.sizeset;
		}
		return *this;
	}

	template <class T> void MyFirstSet<T>::add(const T& elem) //Добавить элемент        Оценка трудоемкости : O(N)
	{
		bool flag1 = true;
		for (int i = 0; i < sizeset; i++)
		{
			if (set[i] == elem)
				flag1 = false;
		}
		if (flag1)
		{
			if (sizeset == capacity - 1)
			{
				temp = new T[capacity * 2];
				for (int i = 0; i < sizeset; i++)
				{
					temp[i] = set[i];
				}

				capacity *= 2;
				set = temp;
			}
			sizeset++;
			set[sizeset - 1] = elem;
			return;
		}
		else
		{
			cout << "Element already in set";
		}
	};


	template <class T> void MyFirstSet<T>::remove(const T& elem)   //Удалить элемент  Оценка трудоемкости : O(N)
	{
		int j = 0;
		for (int i = 0; i < sizeset; i++)
		{
			if (set[i] == elem)
			    i++;
			set[j] = set[i];
			j++;
		}
		sizeset--;
	};

	template <class T> bool MyFirstSet<T>::contains(const T& elem) const   //Содержится ли(если да, то true)    Оценка трудоемкости : O(N)
	{
		bool flag = false;
		for (int i = 0; i < sizeset; i++)
			if (elem == set[i])
				flag = true;
		return flag;
	};

	template <class T> int MyFirstSet<T>::size() const //Узнать размер
	{
		return sizeset;
	};

	template <class T> MyFirstSet<T>::~MyFirstSet() //Деструктор
	{
		delete[] set;
	};
