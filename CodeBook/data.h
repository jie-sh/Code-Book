#pragma once
#define �鿴���� 1
#define ���� 2
#define ɾ�� 3
#define �޸� 4
#define ��ѯ 5
#define �����˳� 6

typedef struct _TEXTINFO
{
	char WebSite[50];
	char UserName[50];
	char PassWord[50];
	char reMark[50];
}TEXTINFO, *PTEXTINFO;
extern TEXTINFO *g_pInfo;//ȫ�ֻ�����ָ��
extern int g_num;//վ�����