#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ctrl.h"
#include"data.h"

//查看所有数据
void PrintAllInfo(int nCount)
{
	
	for (int i = 0; i < nCount; i++) {
		printf("第%d条数据：\n", i + 1);
		printf("站点：%s 账号：%s 密码：%s 备注：%s",
			g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord, g_pInfo[i].reMark);
		printf("\n");
	}
	if (nCount == 0)
		printf("没有数据！\n");
}

//增加数据
void AddInfo(int *pCount)
{
	printf("输入需要存储的站点：");
	scanf_s("%s", g_pInfo[*pCount].WebSite, 50);
	printf("输入需要存储的账号：");
	scanf_s("%s", g_pInfo[*pCount].UserName, 50);
	printf("输入需要存储的密码：");
	scanf_s("%s", g_pInfo[*pCount].PassWord, 50);
	printf("输入需要存储的备注：");
	scanf_s("%s", g_pInfo[*pCount].reMark, 50);
	(*pCount)++;//每增加一组数据就应自增
	//若内存不够，则扩充内存
	if (*pCount == g_num) {
		//申请一块原来2倍大小的内存空间
		TEXTINFO *pTemp = (TEXTINFO *)malloc(g_num * 2 * sizeof(TEXTINFO));
		//内存复制
		memcpy(pTemp, g_pInfo, g_num * sizeof(TEXTINFO));
		//释放原来的空间
		free(g_pInfo);
		//将全局指针指向新的空间
		g_pInfo = pTemp;
		g_num *= 2;
		return;
	}

}

//删除数据
void DeleteInfo(int *pCount)
{
	printf("请输入要删除的站点：\n");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	int nFind = 0;
	for (int i = 0; i < *pCount; i++) {
		if (strcmp(buf, g_pInfo[i].WebSite) == 0) {
			nFind = 1;
			for (int j = i; j < *pCount; j++) {
				g_pInfo[j] = g_pInfo[j + 1];
			}
			(*pCount)--;
			printf("删除成功！\n");
			break;
		}
	}
	if (nFind == 0) {
		printf("查找失败！\n");
	}

}

//修改数据
void AlterInfo(int nCount)
{
	nCount++;
	printf("请输入要修改的站点：\n");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 20);
	int nFind = 0;
	for (int i = 0; i < nCount; i++) {
		if (strcmp(buf, g_pInfo[i].WebSite) == 0) {
			nFind = 1;
			printf("请输入要修改的 账号：");
			scanf_s("%s", g_pInfo[i].UserName, 50);
			printf("请输入要修改的 密码：");
			scanf_s("%s", g_pInfo[i].PassWord, 50);
			printf("请输入要修改的 备注：");
			scanf_s("%s", g_pInfo[i].reMark, 50);
			printf("站点：%s 账号：%s 密码：%s 备注：%s\n",
				g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord, g_pInfo[i].reMark);
			printf("修改成功！\n");
			break;
		}
	}
	if (nFind == 0) {
		printf("查找失败！\n");
	}

}

//查询数据
void PrintOneInfo(int nCount)
{
	nCount++;
	printf("请输入要查询的站点：\n");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	int nFind = 0;
	for (int i = 0; i < nCount; i++) {
		if (strcmp(buf, g_pInfo[i].WebSite) == 0) {
			nFind = 1;
			printf("站点：%s 账号：%s 密码：%s 备注：%s\n",
				g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord, g_pInfo[i].reMark);
			printf("查询成功！\n");
			break;
		}
	}
	if (nFind == 0) {
		printf("查找失败！\n");
	}
}