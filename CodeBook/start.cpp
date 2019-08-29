#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"start.h"
//程序的启动密码
void StartPassWord()
{
	char spw[10] = "abcd";
	char write[10] = "";
	int nSuccess = 0;
	for (int i = 1; i <= 3; i++)
	{
		printf("请输入启动密码：\n");
		scanf_s("%s", write, 10);
		if (strcmp(write, spw) == 0)
		{
			nSuccess = 1;
			break;
		}
		else
		{
			printf("你的输入有误！还有%d次机会\n", 3 - i);
			system("pause");
			system("cls");
		}
	}
	if (nSuccess == 1)
	{
		printf("输入正确！按任意键开始使用程序\n");
	}
	else
	{
		printf("输入全部错误!按任意键结束程序\n");
		system("pause");
		exit(1);
	}
	system("pause");
	system("cls");
}