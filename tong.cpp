#include "tong.h"

//------------------------------登录------------------------------------
//初始化登陆循环链表
bool initLog(LogList*& head) {
    if (head == NULL) {
        head = (LogList*)malloc(sizeof(LogList));
        if (head == NULL)return false;
    }
    head->next = head;
    return true;
}

//登录判断
bool isLogin(LogList* head, char* name, char* password) {
    LogList* p = head->next;
    if (name == NULL) {
        printf("用户名为空，录入错误！请重新录入\n");
        return false;
    }
    if (password == NULL) {
        printf("密码为空，录入错误！请重新录入\n");
        return false;
    }
    while (p != head) {
        if (strcmp(p->data.u_name, name) == 0 && strcmp(p->data.u_password, password) == 0) {
            //login = true;
            printf("\n\n恭喜！登录完成。\n\n");
            return true;
        }
        p = p->next;
    }
    printf("\n\n登陆错误！\n");
    //这里在界面时可以清空里面的东西。
    return false;
}

//增
bool addLog(LogList* head, const char* name, const char* password) {
    LogList* p = head->next, * rear;
    if (name == NULL) {
        printf("用户名为空，添加错误！\n");
        return false;
    }
    if (password == NULL) {
        printf("密码为空，添加错误！\n");
        return false;
    }
    while (p->next != head) {
        //用户名不能重复
        if (strcmp(p->data.u_name, name) == 0) {
            printf("用户名已存在，添加失败!\n");
            return false;
        }
        p = p->next;
    }
    LogList* s = p->next;
    if (strcmp(s->data.u_name, name) == 0) {
        printf("用户名已存在，添加失败!\n");
        return false;
    }
    rear = (LogList*)malloc(sizeof(LogList));
    if (rear == NULL) {
        printf("指针内存申请失败！\n");
        return false;
    }
    strcpy_s(rear->data.u_name, name);
    strcpy_s(rear->data.u_password, password);
    rear->next = p->next;
    p->next = rear;
    return true;
}

//删
bool dropLog(LogList* head, char* name, char* password) {
    LogList* p = head, * rear;
    if (name == NULL) {
        printf("用户名为空，删除错误！\n");
        return false;
    }
    if (password == NULL) {
        printf("密码为空，删除错误！\n");
        return false;
    }
    if (p->next == head) {
        printf("目前没有账户记录存在，请添加账户密码\n");
    }
    while (p->next != head) {
        if (strcmp(p->next->data.u_name, name) == 0 && strcmp(p->next->data.u_password, password) == 0) {
            rear = p->next;
            p->next = rear->next;
            printf("已删除账号：%s 对应密码:%s\n",
                rear->data.u_name, rear->data.u_password);
            free(rear);
            return true;
        }
        p = p->next;
    }
    return false;
}

//查(判断是否存在)
bool isfindLog(LogList* head, char* name) {
    if (name == NULL) {
        printf("传入姓名为空，错误！\n");
        return false;
    }
    LogList* p = head->next;
    while (p != head) {
        if (strcmp(p->data.u_name, name) == 0) {
            return true;
        }
        p = p->next;
    }
    return false;
}

//查询
char* findLog(LogList* head, char* data) {
    if (data == NULL) {
        printf("传入数据为空，错误！\n");
        return NULL;
    }
    LogList* p = head->next;
    while (p != head) {
        if (strcmp(p->data.u_name, data) == 0) {
            return p->data.u_password;
        }
        p = p->next;
    }
    return NULL;
}

//改
bool updateLog(LogList* head, int m, char* name, char* data) {
    if (name == NULL) {
        printf("用户名为空，错误！\n");
        return false;
    }
    if (data == NULL) {
        printf("传入的修改数据为空，错误！\n");
        return false;
    }
    if (m < 0) {
        printf("传入序号不是规定内的序号，错误！\n");
        return false;
    }
    LogList* p = head->next;
    if (m == 1) {
        if (isfindLog(head, name)) {
            printf("错误！此用户名已存在，不能修改！\n");
            return false;
        }
    }
    while (p != head) {
        if (m == 1) {
            if (strcmp(p->data.u_name, name) == 0) {
                strcpy_s(p->data.u_name, data);
                return true;
            }
        }
        else if (m == 2) {
            if (strcmp(p->data.u_name, name) == 0) {
                strcpy_s(p->data.u_password, data);
                return true;
            }
        }
        p = p->next;
    }
    return false;
}


//------------------------------------联系人-------------------------------------------
//初始化联系人循环链表
bool initList(ConList*& head) {
    if (head == NULL) {
        head = (ConList*)malloc(sizeof(ConList));
        if (head == NULL) {
            printf("头指针内存申请失败！\n");
            return false;
        }
    }
    head->next = head;
    return true;
}

//增联系人
bool addList(ConList* head, char* name, char* number) {
    if (name == NULL) {
        printf("姓名为空，录入错误！\n");
        return false;
    }
    if (number == NULL) {
        printf("号码为空，录入错误！\n");
        return false;
    }
    ConList* p = head->next;
    while (p->next != head) {
        //用户名不能重复
        if (strcmp(p->data.c_name, name) == 0) {
            printf("联系人姓名已存在，添加失败!\n");
            return false;
        }
        p = p->next;
    }
    ConList* rear = (ConList*)malloc(sizeof(ConList));
    if (rear == NULL) {
        printf("指针内存申请失败！\n");
    }
    strcpy_s(rear->data.c_name, name);
    strcpy_s(rear->data.c_number, number);
    if (rear->data.c_bei) {
        strcpy_s(rear->data.c_bei, " ");
    }
    if (rear->data.c_gender) {
        strcpy_s(rear->data.c_gender, " ");
    }    if (rear->data.c_city) {
        strcpy_s(rear->data.c_city, " ");
    }    if (rear->data.c_zipCode) {
        strcpy_s(rear->data.c_zipCode, " ");
    }    if (rear->data.c_qq) {
        strcpy_s(rear->data.c_qq, " ");
    }    if (rear->data.c_email) {
        strcpy_s(rear->data.c_email, " ");
    }
    rear->next = p->next;
    p->next = rear;
    return true;
}

//删联系人
bool dropList(ConList* head, ConNode* h, char* name) {
    if (name == NULL) {
        printf("传入姓名为空，错误！\n");
        return false;
    }
    ConList* p = head, * rear;
    if (p->next == head) {
        printf("目前没有联系人记录存在，请添加联系人信息\n");
    }
    //删除了联系人后，也需要把分组里面的联系人指针给删掉
    //hh,头结点。h,大节点。m,小结点。
    ConNode* hh = h->next_zu;
    while (hh != h) {
        TacList* prev = NULL;   // 前驱指针
        TacList* c = hh->next;  // 当前指针
        while (c != NULL) {
            if (strcmp(c->data->c_name, name) == 0) {
                if (prev == NULL) {
                    hh->next = c->next;
                }
                else {
                    prev->next = c->next;
                }
                free(c);
                break;
            }
            prev = c;
            c = c->next;
        }
        hh = hh->next_zu;
    }
    while (p->next != head) {
        if (strcmp(p->next->data.c_name, name) == 0) {
            rear = p->next;
            p->next = rear->next;
            //判断
            //打印删掉的联系人的信息
            printf("已删除联系人姓名：%s 号码:%s\n",
                rear->data.c_name, rear->data.c_number);
            free(rear);
            return true;
        }
        p = p->next;
    }
    return false;
}

//查联系人
bool findList(ConList* head, char* name) {
    if (name == NULL) {
        printf("传入姓名为空，错误！\n");
        return false;
    }
    ConList* p = head->next;
    while (p != head) {
        if (strcmp(p->data.c_name, name) == 0) {
            printPl(p);
            return true;
        }
        p = p->next;
    }
    return false;
}
bool findNum(ConList* head, char* num) {
    if (num == NULL) {
        printf("传入号码为空，错误！\n");
        return false;
    }
    ConList* p = head->next;
    while (p != head) {
        if (strcmp(p->data.c_number, num) == 0) {
            printPl(p);
            return true;
        }
        p = p->next;
    }
    return false;
}


//改联系人
bool updateList(ConList* head, char* name, int m, char* value) {
    if (name == NULL) {
        printf("姓名为空，错误！\n");
        return false;
    }
    if (m < 0 || m>8) {
        printf("传入序号不是规定范围内的序号，错误！\n");
        return false;
    }
    if (value == NULL) {
        printf("修改的值为空，错误！\n");
        return false;
    }
    ConList* p = head->next;
    while (p != head) {
        if (strcmp(p->data.c_name, name) == 0) {
            switch (m) {
            case 0:
                if (findList(head, value)) {
                    printf("错误！此姓名已出现在联系人中，不可重名！\n");
                    return false;
                }
                strcpy_s(p->data.c_name, value);
                break;
            case 1:
                if (findNum(head, value)) {
                    printf("错误！此号码已出现在联系人中，不可重号码！\n");
                    return false;
                }
                strcpy_s(p->data.c_number, value);
                break;
            case 2:
                strcpy_s(p->data.c_bei, value);
                break;
            case 3:
                strcpy_s(p->data.c_gender, value);
                break;
            case 4:
                strcpy_s(p->data.c_city, value);
                break;
            case 5:
                strcpy_s(p->data.c_zipCode, value);
                break;
            case 6:
                strcpy_s(p->data.c_qq, value);
                break;
            case 7:
                strcpy_s(p->data.c_email, value);
                break;
            }
            return true;
        }
        p = p->next;
    }
    return false;
}


//-----------------------------------分组--------------------------------------------------------
//寻找联系人(在未分组里面）
Contact* findpeople(ConList* head, char* name) {
    if (name == NULL) {
        printf("姓名为空，错误！\n");
        return NULL;
    }
    if (head == NULL || head->next == NULL)return NULL;
    ConList* p = head->next;
    while (p != head) {
        if (strcmp(p->data.c_name, name) == 0) {
            return &p->data;
        }
        p = p->next;
    }
    return NULL;
}

//初始化分组
bool initGroup(ConNode*& head) {
    if (head == NULL) {
        head = (ConNode*)malloc(sizeof(ConNode));
        if (head == NULL) {
            printf("头指针内存申请失败！\n");
            return false;
        }
    }
    head->next_zu = head;
    head->next = NULL;
    return true;
}

//增分组
bool addGroup(ConNode* head, char* nname) {
    if (nname == NULL) {
        printf("分组名为空，错误！\n");
        return false;
    }
    ConNode* p = head->next_zu;
    while (p->next_zu != head) {
        if (strcmp(p->name, nname) == 0) {
            printf("分组已存在\n");
            return false;
        }
        p = p->next_zu;
    }
    if (p != head && strcmp(p->name, nname) == 0) {
        printf("分组已存在\n");
        return false;
    }
    //新分组
    ConNode* rear = (ConNode*)malloc(sizeof(ConNode));
    if (rear == NULL) {
        printf("指针内存申请失败!\n");
        return false;
    }
    strcpy_s(rear->name, nname);
    rear->next_zu = p->next_zu;
    rear->next = NULL;
    p->next_zu = rear;
    return true;
}

//分组中增加联系人
bool addGp(ConList* h, ConNode* head, char* nname, char* name) {
    if (nname == NULL) {
        printf("分组名为空，错误！\n");
        return false;
    }
    if (name == NULL) {
        printf("联系人姓名为空，错误！\n");
        return false;
    }
    ConNode* p = head->next_zu;
    while (p != head && strcmp(p->name, nname) != 0) {
        p = p->next_zu;
    }
    if (p == head) {
        printf("没有找到名字为%s的分组！", nname);
        return false;
    }
    TacList* s = (TacList*)malloc(sizeof(TacList));
    if (s == NULL) {
        printf("内存申请失败！\n");
        return false;
    }
    if ((s->data = findpeople(h, name)) == NULL) {
        free(s);
        printf("没有在联系人列表里找到该联系人，请先添加联系人信息至联系人列表中！\n");
        return false;
    }
    TacList* q = p->next;
    while (q != NULL) {
        if (q->data == s->data) {
            printf("联系人已存在于分组中！\n");
            free(s);
            return false;
        }
        q = q->next;
    }
    s->next = p->next;
    p->next = s;
    printf("\n添加成功！\n");
    return true;
}

//删组
bool dropGroup(ConNode* head, char* name) {
    if (name == NULL) {
        printf("分组名为空，错误！\n");
        return false;
    }
    ConNode* p = head;
    if (p->next_zu == head) {
        printf("目前没有联系人信息存在，请添加联系人信息\n");
    }
    //可以在这一块多加一些判断语句
    while (p->next_zu != head) {
        if (strcmp(p->next_zu->name, name) == 0) {
            ConNode* rear = p->next_zu;
            p->next_zu = rear->next_zu;
            TacList* q = rear->next;
            while (q != NULL) {
                TacList* t = q;
                q = q->next;
                free(t);
            }
            free(rear);
            //判断
            return true;
        }
        p = p->next_zu;
    }
    printf("错误！没有找到要删的组！\n");
    return false;
}

//查组
bool findGroup(ConNode* head, char* name) {
    if (name == NULL) {
        printf("分组名为空，错误！\n");
        return false;
    }
    ConNode* p = head->next_zu;
    while (p != head) {
        if (strcmp(p->name, name) == 0) {
            print(p);
            return true;
        }
        p = p->next_zu;
    }
    return false;
}

//修改组名
bool updateGroup(ConNode* head, char* name, char* nameNew) {
    if (name == NULL) {
        printf("组名为空，错误！\n");
        return false;
    }
    if (nameNew == NULL) {
        printf("新组名为空，错误！\n");
        return false;
    }
    ConNode* p = head->next_zu;
    while (p != head) {
        if (strcmp(p->name, nameNew) == 0) {
            printf("新组名已经存在于组中，错误！\n");
            return false;
        }
        p = p->next_zu;
    }
    p = head->next_zu;
    while (p != head) {
        if (strcmp(p->name, name) == 0) {
            strcpy_s(p->name, nameNew);
            return true;
        }
        p = p->next_zu;
    }
    return false;
}

//其实想打印全部信息来着!!!
//打印某一组
void print(ConNode* head) {
    TacList* p = head->next;
    if (p == NULL) {
        printf("本组没有联系人信息在里面\n");
    }
    while (p != NULL) {
        printP(p);
        p = p->next;
    }
}
//打印全部(默认全部的那个）
void printall(ConList* h) {
    ConList* p = h->next;
    while (p != h) {
        printPl(p);
        p = p->next;
    }
}
//打印联系人信息（链表）
void printPl(ConList* p) {
    printf("【联系人】姓名：%s   号码：%s   性别：%s   城市：%s\n",
        p->data.c_name, p->data.c_number, p->data.c_gender, p->data.c_city);
    printf("         备注：%s   邮编：%s\n",
        p->data.c_bei, p->data.c_zipCode);
    printf("         QQ：%s   邮箱：%s\n",
        p->data.c_qq, p->data.c_email);
}
//打印联系人信息（节点）
void printP(TacList* p) {
    printf("【联系人】姓名：%s   号码：%s   性别：%s   城市：%s\n",
        p->data->c_name, p->data->c_number, p->data->c_gender, p->data->c_city);
    printf("         备注：%s   邮编：%s\n",
        p->data->c_bei, p->data->c_zipCode);
    printf("         QQ：%s   邮箱：%s\n",
        p->data->c_qq, p->data->c_email);
}


//---------------------------------文件--------------------------------------------------------
//释放内存
void delList(ConList*& head) {
    ConList* p = head->next;
    while (p != head) {
        ConList* tmp = p;
        p = p->next;
        free(tmp);
    }
    free(head);
    head = NULL;
}
//释放内存
void delNode(ConNode*& head) {
    ConNode* p = head->next_zu;
    while (p != head) {
        ConNode* tmp = p;
        p = p->next_zu;
        TacList* q = tmp->next;
        while (q != NULL) {
            TacList* t = q;
            q = q->next;
            free(t);
        }
        free(tmp);
    }
    free(head);
    head = NULL;
}
//保存文件
// //分组的呢
//能实现对所有东西先记录再全部释放内存，退出登录时。
bool saveFile(ConList*& head, ConNode* h) {
    FILE* fp = NULL;
    errno_t err = fopen_s(&fp, "contacts.txt", "w");
    if (err != 0 || fp == NULL) {
        printf("文件打开失败！错误码：%d\n", err);
        return false;
    }
    ConList* p = head->next;
    fprintf(fp, "--Contact--\n");
    while (p != head) {
        //往文件里写内容
        fprintf(fp, "%s %s %s %s %s %s %s %s\n", p->data.c_name,
            p->data.c_number, p->data.c_bei,
            p->data.c_gender, p->data.c_city,
            p->data.c_zipCode, p->data.c_qq,
            p->data.c_email);
        p = p->next;
    }
    fprintf(fp, "--Group--\n");
    ConNode* pp = h->next_zu;
    while (pp != h) {
        TacList* ppp = pp->next;
        fprintf(fp, "%s", pp->name);
        while (ppp != NULL) {
            fprintf(fp, "  %s", ppp->data->c_name);
            ppp = ppp->next;
        }
        fprintf(fp, "\n");
        pp = pp->next_zu;
    }
    fclose(fp);//关闭文件
    printf("\n\n已经安全退出登录！感谢使用此系统！\n");
    //login = false;
    return true;
}

//读取文件
bool readFile(ConList*& head, ConNode*& groupHead) {
    FILE* fp = NULL;
    fopen_s(&fp, "contacts.txt", "r");
    if (!fp) {
        printf("文件打开失败\n");
        return false;
    }
    if (head != NULL) {   //要注意防止覆盖！
        delList(head);
    }
    if (groupHead == NULL) {  //要检查GroupHead是否有初始化
        initGroup(groupHead);
    }
    initList(head);
    ConList* s = head;
    char line[256];
    bool inContact = false;//在联系人栏里面
    bool inGroup = false;//在分组栏里面
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "--Contact--", 11) == 0) {
            inContact = true;
            inGroup = false;
            continue;
        }
        if (strncmp(line, "--Group--", 9) == 0) {
            inGroup = true;
            inContact = false;
            continue;
        }
        //联系人
        if (inContact) {
            ConList* con = (ConList*)malloc(sizeof(ConList));
            if (!con) continue;
            memset(con, 0, sizeof(ConList));
            //从字符串里读数据
            sscanf_s(line, "%s %s %s %s %s %s %s %s", con->data.c_name, CON_LEN,
                con->data.c_number, CON_LEN, con->data.c_bei, CON_LEN,
                con->data.c_gender, CON_LEN, con->data.c_city, CON_LEN,
                con->data.c_zipCode, CON_LEN, con->data.c_qq, CON_LEN,
                con->data.c_email, CON_LEN);
            con->next = head;
            s->next = con;
            s = con;
        }
        //分组
        if (inGroup) {
            char groupName[CON_LEN];
            char personName[CON_LEN];
            int n = sscanf_s(line, "%s", groupName, CON_LEN);
            //跳过空行
            if (n != 1) continue;
            addGroup(groupHead, groupName);
            ConNode* g = groupHead->next_zu;
            while (g != groupHead && strcmp(g->name, groupName) != 0) {
                g = g->next_zu;
            }
            if (g == groupHead) continue;
            //读取联系人
            char* p = line + strlen(groupName);  // 跳过组名，指向后面的数据
            while (sscanf_s(p, "%s", personName, CON_LEN) == 1) {
                Contact* c = findpeople(head, personName);
                if (c == NULL) {
                    printf("错误！读取的分组联系人信息在原联系人列表中没有。\n");
                    return false;
                }
                TacList* t = (TacList*)malloc(sizeof(TacList));
                if (t == NULL) {
                    printf("错误！指针申请失败！\n");
                }
                t->data = c;
                t->next = g->next;
                g->next = t;
                p += strlen(personName);  // 跳过读取了的名字
                while (*p == ' ') p++;  // 跳过后面的空格
            }
        }
    }
    fclose(fp);
    printf("文件读取完成！\n");
    return true;
}
//--------------------------------------------------------------------------------------------------------
//开始界面
void printtong() {
    printf("\n*************************************开始界面********************************************************\n");
    printf("通讯录系统列表如下：\n");
    printf("1、添加账号(仅限管理员）\n");
    printf("2、登陆账号\n");
    printf("3、退出\n");
    printf("****************************************************************************************************\n");
    printf("你的选择是：");
}
//管理员界面
void printG() {
    printf("\n************************************管理员选择界面****************************************************\n");
    printf("你想要进行哪一种操作：\n");
    printf("1、添加账号\n");
    printf("2、删除账号\n");
    printf("3、查询账号是否存在\n");
    printf("4、通过账号查询密码\n");
    printf("5、通过账号修改账号\n");
    printf("6、通过账号修改密码\n");
    printf("7、退出\n");
    printf("******************************************************************************************************\n");
    printf("你的选择是：");
}
//通讯录界面
void printT() {
    printf("\n************************************通讯录界面****************************************************\n");
    printf("【分  组 列 表 】（可查看）\n");
    printf("【联  系 人 列 表 】（可查看）\n");
    printf("\n");
    printf("======================================操作面板==================================================\n");
    printf("你想要进行哪一种操作：\n");
    printf("==========分组栏==========\n");
    printf("1、查看分组\n");
    printf("2、添加分组\n");
    printf("3、分组中添加联系人\n");
    printf("4、删除分组\n");
    printf("5、查询分组\n");
    printf("6、修改分组名\n");
    printf("===========================\n");
    printf("\n");
    printf("==========联系人栏==========\n");
    printf("7、查看联系人\n");
    printf("8、添加联系人\n");
    printf("9、删除联系人\n");
    printf("10、查询联系人(by名字）\n");
    printf("11、查询联系人(by号码）\n");
    printf("12、修改联系人信息\n");
    printf("===========================\n");
    printf("13、退出\n");
    printf("\n");
    printf("******************************************************************************************************\n");
    printf("你的选择是：");
}