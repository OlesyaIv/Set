//�������� ������� - ���������.
//������: 13501/3 �������: ��������� ����� 
/*� �������� ���������� ��������� � �������(!) ������ ��� ���������� �������.
��� ������������ ������������� ������������� ������.*/
#include "interface.h"

int main(void)
{
	MySet < int > massiv1;

	int eleme = 17;

	massiv1.add(eleme);
	massiv1.remove(eleme);
	if(massiv1.contains(eleme)==true)
		cout << "Element is here";
	system("Pause");
}