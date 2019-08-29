#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"FileOper.h"
#include"data.h"

//��ȡ�ļ���Ϣ����ʼ��
void ReadCodeInfo(int *pCount)
{
	//���ļ�
	FILE *pFile = NULL;
	int nError = fopen_s(&pFile, "E:\\code.txt", "rb+");
	//����ʧ�ܣ�û���ļ�����ô�����Լ����ó�ʼ��Ϣ
	if (nError != 0) {
		g_pInfo = (TEXTINFO*)malloc(20 * sizeof(TEXTINFO));
		g_num = 20;
		*pCount = 0;
		return;
	}
	//���򿪳ɹ�����ȥ��ȡͷ����Ϣ
	fread(&g_num, 4, 1, pFile);//��ȡ�ڴ�����
	fread(pCount, 4, 1, pFile);//��ȡվ������

	//����������ռ�
	g_pInfo = (TEXTINFO*)malloc(g_num * sizeof(TEXTINFO));
	memset(g_pInfo, 0, g_num * sizeof(TEXTINFO));
	//��ȡ��Ϣ
	fscanf_s(pFile, "\n");
	for (int i = 0; i < *pCount; i++) {
		fread(g_pInfo[i].WebSite, 50, 1, pFile);
		fread(g_pInfo[i].UserName, 50, 1, pFile);
		fread(g_pInfo[i].PassWord, 50, 1, pFile);
		fread(g_pInfo[i].reMark, 50, 1, pFile);
	}
	//����������
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

//�����ļ���Ϣ
void SaveFile(int nCount)
{
	//���ļ�
	FILE *pFile = NULL;
	int nError = fopen_s(&pFile, "E:\\code.txt", "wb+");
	if (nError != 0) {
		return;
	}
	//ÿ�����Ƕ�ȡһ���ļ����ļ���ǰ�Ķ�дλ�þͻ���ƶ�ȡ���ֽ���
	//д�����������������
	fwrite(&g_num, 4, 1, pFile);
	fwrite(&nCount, 4, 1, pFile);
	//д����Ϣ
	fprintf(pFile, "\n");
	//����������
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