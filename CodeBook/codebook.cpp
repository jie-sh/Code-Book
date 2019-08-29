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
		case 查看所有:
			PrintAllInfo(nCount);
			break;
		case 增加:
			AddInfo(&nCount);
			//SaveFile(nCount);
			break;
		case 删除:
			DeleteInfo(&nCount);
			//SaveFile(nCount);
			break;
		case 修改:
			AlterInfo(nCount);
			//SaveFile(nCount);;
			break;
		case 查询:
			PrintOneInfo(nCount);
			break;
		case 保存退出:
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
