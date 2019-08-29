#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"FileOper.h"
#include"data.h"

//读取文件信息，初始化
void ReadCodeInfo(int *pCount)
{
	//打开文件
	FILE *pFile = NULL;
	int nError = fopen_s(&pFile, "E:\\code.txt", "rb+");
	//若打开失败，没有文件，那么我们自己设置初始信息
	if (nError != 0) {
		g_pInfo = (TEXTINFO*)malloc(20 * sizeof(TEXTINFO));
		g_num = 20;
		*pCount = 0;
		return;
	}
	//若打开成功，就去读取头部信息
	fread(&g_num, 4, 1, pFile);//读取内存总数
	fread(pCount, 4, 1, pFile);//读取站点数量

	//按容量申请空间
	g_pInfo = (TEXTINFO*)malloc(g_num * sizeof(TEXTINFO));
	memset(g_pInfo, 0, g_num * sizeof(TEXTINFO));
	//读取信息
	fscanf_s(pFile, "\n");
	for (int i = 0; i < *pCount; i++) {
		fread(g_pInfo[i].WebSite, 50, 1, pFile);
		fread(g_pInfo[i].UserName, 50, 1, pFile);
		fread(g_pInfo[i].PassWord, 50, 1, pFile);
		fread(g_pInfo[i].reMark, 50, 1, pFile);
	}
	//异或运算解密
	for (int i = 0; i < *pCount; i++) {
		for (int j = 0; j < 50; j++) {
			if (g_pInfo[i].UserName[j] == 0)
				continue;
			g_pInfo[i].UserName[j] ^= 'a';
		}
	}
	for (int i = 0; i < *pCount; i++) {
		for (int j = 0; j < 50; j++) {
			if (g_pInfo[i].PassWord[j] == 0)
				continue;
			g_pInfo[i].PassWord[j] ^= 31;
		}
	}
	fclose(pFile);
}

//保存文件信息
void SaveFile(int nCount)
{
	//打开文件
	FILE *pFile = NULL;
	int nError = fopen_s(&pFile, "E:\\code.txt", "wb+");
	if (nError != 0) {
		return;
	}
	//每当我们读取一次文件，文件当前的读写位置就会后移读取的字节数
	//写入密码的总数和数量
	fwrite(&g_num, 4, 1, pFile);
	fwrite(&nCount, 4, 1, pFile);
	//写入信息
	fprintf(pFile, "\n");
	//异或运算加密
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < 50; j++) {
			if (g_pInfo[i].UserName[j] == 0)
				continue;
			g_pInfo[i].UserName[j] ^= 'a';
		}
	}
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < 50; j++) {
			if (g_pInfo[i].PassWord[j] == 0)
				continue;
			g_pInfo[i].PassWord[j] ^= 31;
		}
	}
	for (int i = 0; i < nCount; i++) {
		fwrite(g_pInfo[i].WebSite, 50, 1, pFile);
		fwrite(g_pInfo[i].UserName, 50, 1, pFile);
		fwrite(g_pInfo[i].PassWord, 50, 1, pFile);
		fwrite(g_pInfo[i].reMark, 50, 1, pFile);
	}	
	fclose(pFile);
}