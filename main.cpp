//Домашнее задание - Множество.
//Группа: 13501/3 Студент: Ивашкевич Олеся 

#include "MyFirstSet.h"


void main(void)
{
	MyFirstSet < int > set1;
	
	int y = 9;
	int x = 8;
	set1.add(y);//Добавить 9
	set1.add(x); //Добавить 8
	set1.remove(y); //Удалить 9
	cout << set1.contains(y); //Есть ли 9? Нет
	system("Pause");
	
}