//�������� ������� - ���������.
//������: 13501/3 �������: ��������� ����� 

#include "MyFirstSet.h"


void main(void)
{
	MyFirstSet < int > set1;
	
	int y = 9;
	int x = 8;
	set1.add(y);//�������� 9
	set1.add(x); //�������� 8
	set1.remove(y); //������� 9
	cout << set1.contains(y); //���� �� 9? ���
	system("Pause");
	
}