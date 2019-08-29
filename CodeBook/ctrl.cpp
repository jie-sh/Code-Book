#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ctrl.h"
#include"data.h"

//�鿴��������
void PrintAllInfo(int nCount)
{
	
	for (int i = 0; i < nCount; i++) {
		printf("��%d�����ݣ�\n", i + 1);
		printf("վ�㣺%s �˺ţ�%s ���룺%s ��ע��%s",
			g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord, g_pInfo[i].reMark);
		printf("\n");
	}
	if (nCount == 0)
		printf("û�����ݣ�\n");
}

//��������
void AddInfo(int *pCount)
{
	printf("������Ҫ�洢��վ�㣺");
	scanf_s("%s", g_pInfo[*pCount].WebSite, 50);
	printf("������Ҫ�洢���˺ţ�");
	scanf_s("%s", g_pInfo[*pCount].UserName, 50);
	printf("������Ҫ�洢�����룺");
	scanf_s("%s", g_pInfo[*pCount].PassWord, 50);
	printf("������Ҫ�洢�ı�ע��");
	scanf_s("%s", g_pInfo[*pCount].reMark, 50);
	(*pCount)++;//ÿ����һ�����ݾ�Ӧ����
	//���ڴ治�����������ڴ�
	if (*pCount == g_num) {
		//����һ��ԭ��2����С���ڴ�ռ�
		TEXTINFO *pTemp = (TEXTINFO *)malloc(g_num * 2 * sizeof(TEXTINFO));
		//�ڴ渴��
		memcpy(pTemp, g_pInfo, g_num * sizeof(TEXTINFO));
		//�ͷ�ԭ���Ŀռ�
		free(g_pInfo);
		//��ȫ��ָ��ָ���µĿռ�
		g_pInfo = pTemp;
		g_num *= 2;
		return;
	}

}

//ɾ������
void DeleteInfo(int *pCount)
{
	printf("������Ҫɾ����վ�㣺\n");
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
			printf("ɾ���ɹ���\n");
			break;
		}
	}
	if (nFind == 0) {
		printf("����ʧ�ܣ�\n");
	}

}

//�޸�����
void AlterInfo(int nCount)
{
	nCount++;
	printf("������Ҫ�޸ĵ�վ�㣺\n");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 20);
	int nFind = 0;
	for (int i = 0; i < nCount; i++) {
		if (strcmp(buf, g_pInfo[i].WebSite) == 0) {
			nFind = 1;
			printf("������Ҫ�޸ĵ� �˺ţ�");
			scanf_s("%s", g_pInfo[i].UserName, 50);
			printf("������Ҫ�޸ĵ� ���룺");
			scanf_s("%s", g_pInfo[i].PassWord, 50);
			printf("������Ҫ�޸ĵ� ��ע��");
			scanf_s("%s", g_pInfo[i].reMark, 50);
			printf("վ�㣺%s �˺ţ�%s ���룺%s ��ע��%s\n",
				g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord, g_pInfo[i].reMark);
			printf("�޸ĳɹ���\n");
			break;
		}
	}
	if (nFind == 0) {
		printf("����ʧ�ܣ�\n");
	}

}

//��ѯ����
void PrintOneInfo(int nCount)
{
	nCount++;
	printf("������Ҫ��ѯ��վ�㣺\n");
	char buf[50] = { 0 };
	scanf_s("%s", buf, 50);
	int nFind = 0;
	for (int i = 0; i < nCount; i++) {
		if (strcmp(buf, g_pInfo[i].WebSite) == 0) {
			nFind = 1;
			printf("վ�㣺%s �˺ţ�%s ���룺%s ��ע��%s\n",
				g_pInfo[i].WebSite, g_pInfo[i].UserName, g_pInfo[i].PassWord, g_pInfo[i].reMark);
			printf("��ѯ�ɹ���\n");
			break;
		}
	}
	if (nFind == 0) {
		printf("����ʧ�ܣ�\n");
	}
}