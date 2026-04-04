#pragma once
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdbool.h>

#define USE_LEN 20
#define CON_LEN 30

//bool login = false;//登陆状态

//用户
typedef struct {
    char u_name[USE_LEN];
    char u_password[USE_LEN];
} User;

//联系人
typedef struct {
    char c_name[CON_LEN];                //必须
    char c_number[CON_LEN];//手机号      //必须
    char c_bei[CON_LEN];//备注
    char c_gender[CON_LEN];
    char c_city[CON_LEN];//城市
    char c_zipCode[CON_LEN];//邮编
    char c_qq[CON_LEN];//qq号
    char c_email[CON_LEN];
} Contact;

//登陆链表
typedef struct LogListt {
    User data;
    struct LogListt* next;
} LogList;

//联系人链表
typedef struct ConList {
    Contact data;
    ConList* next;
} ConList;
//分组小节点
typedef struct TacList {
    Contact* data;
    TacList* next;
} TacList;
//联系人节点
typedef struct ConNode {
    char name[CON_LEN];
    ConNode* next_zu;//分组中的组
    TacList* next;//每一个分组后面存得联系人信息
} ConNode;

//--------------------------------登录-------------------------------
//初始化登陆循环链表
bool initLog(LogList*& head);
//登录判断
bool isLogin(LogList* head, char* name, char* password);
//增
bool addLog(LogList* head, const char* name, const char* password);
//删
bool dropLog(LogList* head, char* name, char* password);
//查(判断是否存在)
bool isfindLog(LogList* head, char* name);
//查询
char* findLog(LogList* head, char* data);
//改
bool updateLog(LogList* head, int m, char* name, char* password);
//--------------------------------联系人-------------------------------
//初始化联系人循环链表
bool initList(ConList*& head);
//增联系人
bool addList(ConList* head, char* name, char* number);
//删联系人
bool dropList(ConList* head, ConNode* h, char* name);
//查联系人
bool findList(ConList* head, char* name);
bool findNum(ConList* head, char* num);
//改联系人
bool updateList(ConList* head, char* name, int m, char* value);
//--------------------------------分组-------------------------------
//寻找联系人
Contact* findpeople(ConList* head, char* name);
//初始化分组
bool initGroup(ConNode*& head);
//增分组
bool addGroup(ConNode* head, char* nname);
//分组中增加联系人
bool addGp(ConList* h, ConNode* head, char* nname, char* name);
//删组
bool dropGroup(ConNode* head, char* name);
//查组
bool findGroup(ConNode* head, char* name);
//修改组名
bool updateGroup(ConNode* head, char* name, char* nameNew);
//打印某一组
void print(ConNode* head);
//打印全部(不是按组来的）
void printall(ConList* head);
//打印联系人信息（链表）
void printPl(ConList* p);
//打印联系人信息（节点）
void printP(TacList* p);
//------------------------------文件-----------------------
//释放内存
void delList(ConList*& head);
//释放内存
void delNode(ConNode*& head);
//保存文件
bool saveFile(ConList*& head, ConNode* h);
//读取文件
bool readFile(ConList*& head, ConNode*& groupHead);
//------------------------------打印-----------------------
//开始
void printtong();
//管理员
void printG();
//通讯录界面
void printT();