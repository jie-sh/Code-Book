#include<stdlib.h>
#include <stdio.h>
#include"ctrl.h"
#include"data.h"
#include"show.h"
#include"FileOper.h"
#include"start.h"

int main()
{
	int nCount = 0;
	int nChoice = 1;
	StartPassWord();
	ReadCodeInfo(&nCount);
	while (nChoice) {
		ShowMenu();
		scanf_s("%d", &nChoice);
		switch (nChoice) {
		case �鿴����:
			PrintAllInfo(nCount);
			break;
		case ����:
			AddInfo(&nCount);
			//SaveFile(nCount);
			break;
		case ɾ��:
			DeleteInfo(&nCount);
			//SaveFile(nCount);
			break;
		case �޸�:
			AlterInfo(nCount);
			//SaveFile(nCount);;
			break;
		case ��ѯ:
			PrintOneInfo(nCount);
			break;
		case �����˳�:
			SaveFile(nCount);
			nChoice = 0;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
