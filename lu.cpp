#include"tong.h"
int main() {
	//初始化登录
	LogList* head = NULL;
	initLog(head);
	while (!addLog(head, "yo", "123456")) {} //管理员账号，只用于添加账号。
	//读取文件
	int m, cnt = 0;
	ConList* conHead = NULL;
	ConNode* groupHead = NULL;
	initList(conHead);
	initGroup(groupHead);
	if (!readFile(conHead, groupHead)) {
		printf("\n目前没有记录文件，请添加相关记录.\n\n");
	}
	char name[USE_LEN] = { 0 }, password[USE_LEN] = { 0 };
	while (cnt++ <= 20) {
		printtong();
		scanf_s("%d", &m);
		if (m == 1) {
			//管理员添加账号
			int n = 0;
			printf("请输入管理员的账号:");
			scanf_s("%19s", name, USE_LEN);
			printf("请输入管理员的密码:");
			scanf_s("%19s", password, USE_LEN);
			while (!isLogin(head, name, password) && n++ <= 10) {
				printf("请输入管理员的账号:");
				scanf_s("%19s", name, USE_LEN);
				printf("请输入管理员的密码:");
				scanf_s("%19s", password, USE_LEN);
			}
			if (n > 10) {
				printf("输入错误次数超过10次!返回主页\n");
				break;
			}
			while (1) {
				printG();
				scanf_s("%d", &n);
				if (n == 1) {
					printf("请输入添加的账号:");
					scanf_s("%19s", name, USE_LEN);
					printf("请输入添加的密码:");
					scanf_s("%19s", password, USE_LEN);
					if (!addLog(head, name, password)) {
						printf("添加失败！\n");
						break;
					}
					printf("添加成功！\n");
				}
				else if (n == 2) {
					printf("请输入账号:");
					scanf_s("%19s", name, USE_LEN);
					printf("请输入密码:");
					scanf_s("%19s", password, USE_LEN);
					if (!dropLog(head, name, password)) {
						printf("删除失败！\n");
						break;
					}
					printf("删除成功！\n");
				}
				else if (n == 3) {
					printf("请输入要查询的账号:");
					scanf_s("%19s", name, USE_LEN);
					if (isfindLog(head, name)) {
						printf("此账号存在！\n");
					}
					else {
						printf("此账号不存在！\n");
					}
				}
				else if (n == 4) {
					printf("请输入要查询的账号:");
					scanf_s("%19s", name, USE_LEN);
					char* mm;
					if ((mm = findLog(head, name)) != NULL) {
						printf("此账号的密码为：%s\n", mm);
					}
					else {
						printf("此账号查找不到！\n");
					}
				}
				else if (n == 5) {
					printf("请输入查找的账号:");
					scanf_s("%19s", name, USE_LEN);
					printf("请输入修改成的账号:");
					scanf_s("%19s", password, USE_LEN);
					if (updateLog(head, 1, name, password)) {
						printf("修改成功！\n");
					}
				}
				else if (n == 6) {
					printf("请输入查找的账号:");
					scanf_s("%19s", name, USE_LEN);
					printf("请输入修改成的密码:");
					scanf_s("%19s", password, USE_LEN);
					if (updateLog(head, 2, name, password)) {
						printf("修改成功！\n");
					}
					else {
						printf("错误！\n");
					}
				}
				else if (n == 7)break;
				else {
					printf("请输入正确的数字。\n");
				}
			}
		}
		else if (m == 2) {
			//账号登陆
			printf("请输入账号:");
			scanf_s("%19s", name, USE_LEN);
			printf("请输入密码:");
			scanf_s("%19s", password, USE_LEN);
			int n = 0;
			while (!isLogin(head, name, password) && n++ <= 10) {
				printf("请输入账号:");
				scanf_s("%s", name, USE_LEN);
				printf("请输入密码:");
				scanf_s("%s", password, USE_LEN);
			}
			if (n > 10) {
				printf("输入错误次数超过10次!返回主页\n");
				break;
			}
			printf("\n\n恭喜！登录完成。欢迎%s来到通讯录管理系统！！\n\n", name);
			char ccc;
			while (1) {
				printT();
				scanf_s("%d", &n);
				char a[CON_LEN] = { 0 };
				char b[CON_LEN] = { 0 };
				int idx = 0;
				if (n == 1) {          // 查看分组
					ConNode* p = groupHead->next_zu;
					if (p == groupHead) {
						printf("\n\n当前没有任何分组。\n\n");
					}
					while (p != groupHead) {
						printf("分组：%s\n", p->name);
						print(p);
						p = p->next_zu;
					}
				}
				else if (n == 2) {     // 添加分组
					printf("请输入分组名：");
					scanf_s("%19s", a, CON_LEN);
					if (addGroup(groupHead, a)) {
						printf("添加成功！\n");
					}
					else {
						printf("添加失败！\n");
					}
				}
				else if (n == 3) {     // 分组中添加联系人
					printf("请输入分组名：");
					scanf_s("%19s", a, CON_LEN);
					printf("请输入联系人姓名：");
					scanf_s("%19s", b, CON_LEN);
					addGp(conHead, groupHead, a, b);
				}
				else if (n == 4) {     // 删除分组
					printf("请输入分组名：");
					scanf_s("%19s", a, CON_LEN);
					if (dropGroup(groupHead, a)) {
						printf("删除完成！\n");
					}
				}
				else if (n == 5) {     // 查询分组
					printf("请输入分组名：");
					scanf_s("%19s", a, CON_LEN);
					if (findGroup(groupHead, a)) {
						printf("有此分组名\n");
					}
				}
				else if (n == 6) {     // 修改分组名
					printf("旧分组名：");
					scanf_s("%19s", a, CON_LEN);
					printf("新分组名：");
					scanf_s("%19s", b, CON_LEN);
					if (updateGroup(groupHead, a, b)) {
						printf("更新完成！\n");
					}
				}
				else if (n == 7) {     // 查看联系人
					if (conHead->next == conHead) {
						printf("暂无联系人！\n");
						continue;
					}
					printall(conHead);
				}
				else if (n == 8) {     // 添加联系人
					printf("姓名：");
					scanf_s("%19s", a, CON_LEN);
					printf("号码：");
					scanf_s("%19s", b, CON_LEN);
					addList(conHead, a, b);
				}
				else if (n == 9) {     // 删除联系人
					printf("请输入姓名：");
					scanf_s("%19s", a, CON_LEN);
					dropList(conHead, groupHead, a);
				}
				else if (n == 10) {    // 按姓名查询
					printf("请输入姓名：");
					scanf_s("%19s", a, CON_LEN);
					if (!findList(conHead, a)) {
						printf("没有找到联系人(by名字)。\n");
					}
				}
				else if (n == 11) {    // 按号码查询
					printf("请输入号码：");
					scanf_s("%19s", a, CON_LEN);
					if (!findNum(conHead, a)) {
						printf("没有找到联系人(by号码)。\n");
					}
				}
				else if (n == 12) {    // 修改联系人
					printf("联系人姓名：");
					scanf_s("%19s", a, CON_LEN);
					printf("修改项(0-7)：");
					scanf_s("%d", &idx);
					printf("修改成：");
					scanf_s("%19s", b, CON_LEN);
					updateList(conHead, a, idx, b);
				}
				else if (n == 13) {    // 退出
					saveFile(conHead, groupHead);
					delList(conHead);
					delNode(groupHead);
					printf("已退出通讯录系统。\n");
					break;
				}
				else {
					printf("请输入正确的数字！\n");
				}
			}
		}
		else if (m == 3) {
			printf("好的，正在退出中......");
			exit(0);
		}
		else {
			printf("请输入正确的数字。\n");
		}
	}
	printf("系统自动弹出......\n");
	return 0;
}