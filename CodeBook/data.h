#pragma once
#define 查看所有 1
#define 增加 2
#define 删除 3
#define 修改 4
#define 查询 5
#define 保存退出 6

typedef struct _TEXTINFO
{
	char WebSite[50];
	char UserName[50];
	char PassWord[50];
	char reMark[50];
}TEXTINFO, *PTEXTINFO;
extern TEXTINFO *g_pInfo;//全局缓冲区指针
extern int g_num;//站点个数