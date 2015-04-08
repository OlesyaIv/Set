//�������� ������� - ���������.
//������: 13501/3 �������: ��������� ����� 
#ifndef __INTERFACE_H
#define __INTERFACE_H    

#include <iostream> 
#include <clocale>
#include <stdlib.h>
#include <new>

// ���������� ����������� ������������ ����
using namespace std;      

template <class T> class ISet { 
public:    
    // �������� �������    
    virtual void add(const T& elem) = 0;    
    // ������� �������    
    virtual void remove(const T& elem) = 0;    
    // ���������� �� �������    
    virtual bool contains(const T& elem) const = 0;    
    // ������ ������ ���������    
    virtual int size() const = 0; 
}; 

template < class T > class MySet : public ISet < T >
{
protected:

	T *set;  // ���������
	T *temp; // ��������� ������
	unsigned int sizeset;  // ������ ���������

public:
	//�����������
	MySet()
	{
		set = new (nothrow)T[0];
		sizeset = 0;
	}

	//����������
	~MySet()
	{
		delete[] set;
	}

    //�������� �������
	void add(const T& elem) 
	{
		T element = elem;

		//��������, � ����� ������� ��� ����
		for (int i = 0; i<sizeset; i++)
			if (element == set[i])
			{
			cout << "Element already in the set";
			return;
			}

		temp = new (nothrow)T[sizeset];

		//���������� �� ��������� ������
		for (int i = 0; i<sizeset; i++)
			temp[i] = set[i];
		//������� �����������, ��� ����� ����������� ������
		delete[] set;
		//����������� ������
		sizeset++;
		//������� ������ � ����� ��������
		set = new (nothrow)T[sizeset];
		//��������� ���
		for (int i = 0; i<sizeset; i++)
			set[i] = temp[i];
		//������� ���������, ��� ����� ����������� ������
		delete[] temp;
		//��������� �������
		set[sizeset - 1] = element;
	};

    //������� �������
	void remove(const T& elem)   
	{
		T element = elem;
		bool flag = true;
		//������� ��������� ������
		temp = new (nothrow)T[sizeset - 1];

		for (int i = 0; i<sizeset; i++)
		{
			//���� ������� � ���������
			if (element == set[i])
			{
				flag = false;
				int k = 0;
				//�������� ��������� ����� ������
				for (int j = 0; j<sizeset; j++)
				{
					if (set[j] != element)  //���� ��� �� ��� �������(������� ���� �������)
					{
						//�� ���������� � ����� ������
						temp[k] = set[j];
						k++;
					}
				}
				
			}
		}
		
		if (flag == true) //���� ������� �� �����
		{
			cout << " Element didnt found!";
			return;
		}
		else
		{
			sizeset--;
			for (int i = 0; i < sizeset; i++) //�������������� � ����������� ������
			{
				set[i] = temp[i];
			}
			delete[] temp;//����������� ������
		}

	};

	//���������� �� �������
	bool contains(const T& elem) const  
	{

		T element = elem;

		bool flag = false;
		//���� �������
		for (int i = 0; i<sizeset; i++)
			if (element == set[i]) //���� �����,�� true
			{
			flag = true;
			}
		return flag;
	};

	//������ ���������
	int size() const
	{
		return sizeset;
	};
};

#endif