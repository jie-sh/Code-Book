#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"start.h"
//�������������
void StartPassWord()
{
	char spw[10] = "abcd";
	char write[10] = "";
	int nSuccess = 0;
	for (int i = 1; i <= 3; i++)
	{
		printf("�������������룺\n");
		scanf_s("%s", write, 10);
		if (strcmp(write, spw) == 0)
		{
			nSuccess = 1;
			break;
		}
		else
		{
			printf("����������󣡻���%d�λ���\n", 3 - i);
			system("pause");
			system("cls");
		}
	}
	if (nSuccess == 1)
	{
		printf("������ȷ�����������ʼʹ�ó���\n");
	}
	else
	{
		printf("����ȫ������!���������������\n");
		system("pause");
		exit(1);
	}
	system("pause");
	system("cls");
}