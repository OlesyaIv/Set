//Домашнее задание - Множество.
//Группа: 13501/3 Студент: Ивашкевич Олеся 
#ifndef __INTERFACE_H
#define __INTERFACE_H    

#include <iostream> 
#include <clocale>
#include <stdlib.h>
#include <new>

// Используем стандартное пространство имен
using namespace std;      

template <class T> class ISet { 
public:    
    // добавить элемент    
    virtual void add(const T& elem) = 0;    
    // удалить элемент    
    virtual void remove(const T& elem) = 0;    
    // содержится ли элемент    
    virtual bool contains(const T& elem) const = 0;    
    // узнать размер множества    
    virtual int size() const = 0; 
}; 

template < class T > class MySet : public ISet < T >
{
protected:

	T *set;  // Множество
	T *temp; // Временный массив
	unsigned int sizeset;  // Размер множества

public:
	//Конструктор
	MySet()
	{
		set = new (nothrow)T[0];
		sizeset = 0;
	}

	//Деструктор
	~MySet()
	{
		delete[] set;
	}

    //Добавить элемент
	void add(const T& elem) 
	{
		T element = elem;

		//Проверим, а вдруг элемент уже есть
		for (int i = 0; i<sizeset; i++)
			if (element == set[i])
			{
			cout << "Element already in the set";
			return;
			}

		temp = new (nothrow)T[sizeset];

		//Записываем во временный массив
		for (int i = 0; i<sizeset; i++)
			temp[i] = set[i];
		//Удаляем изначальный, тем самым освобождаем память
		delete[] set;
		//Увеличиваем размер
		sizeset++;
		//Создаем массив с новым размером
		set = new (nothrow)T[sizeset];
		//Заполняем его
		for (int i = 0; i<sizeset; i++)
			set[i] = temp[i];
		//Удаляем временный, тем самым освобождаем память
		delete[] temp;
		//Добавляем элемент
		set[sizeset - 1] = element;
	};

    //Удалить элемент
	void remove(const T& elem)   
	{
		T element = elem;
		bool flag = true;
		//Создаем временный массив
		temp = new (nothrow)T[sizeset - 1];

		for (int i = 0; i<sizeset; i++)
		{
			//Ищем элемент в множестве
			if (element == set[i])
			{
				flag = false;
				int k = 0;
				//Начинаем заполнять новый массив
				for (int j = 0; j<sizeset; j++)
				{
					if (set[j] != element)  //Если это не наш элемент(который надо удалить)
					{
						//то записываем в новый массив
						temp[k] = set[j];
						k++;
					}
				}
				
			}
		}
		
		if (flag == true) //Если элемент не нашли
		{
			cout << " Element didnt found!";
			return;
		}
		else
		{
			sizeset--;
			for (int i = 0; i < sizeset; i++) //Перезаписываем в изначальный массив
			{
				set[i] = temp[i];
			}
			delete[] temp;//Освобождаем память
		}

	};

	//Содержится ли элемент
	bool contains(const T& elem) const  
	{

		T element = elem;

		bool flag = false;
		//Ищем элемент
		for (int i = 0; i<sizeset; i++)
			if (element == set[i]) //Если нашли,то true
			{
			flag = true;
			}
		return flag;
	};

	//Размер множества
	int size() const
	{
		return sizeset;
	};
};

#endif