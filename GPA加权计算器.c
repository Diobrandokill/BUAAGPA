//本程序为GPA及加权平均分计算器，适用于BUAA采用的算法
//完成时间为2020.1.24，暂无后续修改计划 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 100

//欢迎函数及介绍 
void welcome () {
	//初始化 
	printf("*********************************************************\n");
	printf("**         欢迎使用GPA与加权平均分计算器               **\n");
	printf("**      本计算器适用于北京航空航天大学GPA算法          **\n");
	printf("**    如果有误差请以教务系统显示为准，本程序仅供参考   **\n");
	printf("**  作者：空游无所依  联系方式：kongyoubuaa@gmail.com  **\n");
	printf("*********************************************************\n\n\n");
	
	//输入简介 
	printf("*********************************************************\n");
	printf("**         本计算器每一行需要输入成绩及学分            **\n");
	printf("**      如果需要修改上一门信息，请输入-1 -1并回车      **\n");
	printf("**          如果需要结束输入，请输入0 0并回车          **\n");
	printf("**          请按提示要求输入，不超过100门课程          **\n");
	printf("**     成绩和学分间以空格隔开，每行输入结束请按回车    **\n");
	printf("*********************************************************\n\n\n");
}

//相关存储空间初始化 
int i = 0;
struct part{	
	double score;
	double credit;
	};
struct part store[105];
double GPA;
double average;//相关存储空间初始化结束 

//获取输入信息 
int get (int i) {
	printf("您第 %d 门课的 成绩和学分 分别为（请用空格隔开）：", i + 1);
	scanf("%lf%lf", &store[i].score, &store[i].credit);
	//printf("%lf%lf", store[i].score, store[i].credit);
	if(store[i].score==-1 && store[i].credit==-1)	return -1;//修改 
	if(store[i].score==0 && store[i].credit==0)	return 1;//结束输入 
	if(store[i].score<0 || store[i].score>100 
		|| store[i].credit<0 || store[i].credit>10)	return 2;//异常输入 
	return 0;//正常输入 
}

//修改输入确认函数 
int returnGet() {
	int flag;
	printf("确认修改上一输出？（确认请按1，取消修改请按0）：");
	scanf("%d", &flag);
	return flag;
}

//停止输入确认函数 
int end() {
	int flag;
	printf("确认停止输入？（确认请按1，继续输入请按0）：");
	scanf("%d", &flag);
	return flag;
}

//计算平均GPA 
void calculateGPA(int m){
	double sumGPA = 0, sumCredit = 0;
	int i;
	for (i = 0; i < m; i++) {
		if(store[i].score>60)
			sumGPA += (4-3*pow((100-store[i].score),2)/1600)*store[i].credit;
		sumCredit += store[i].credit;
	}
	GPA = sumGPA / sumCredit; 
}

//计算加权平均分 
void calculateAve(int m){
	double sumScore = 0, sumCredit = 0;
	int i;
	for (i = 0; i < m; i++) {
		sumScore += store[i].score*store[i].credit;
		sumCredit += store[i].credit;
	}
	average = sumScore / sumCredit; 
}

void thanks () {
	printf ("\n\n您的GPA是：%.4lf", GPA);
	printf ("\n您的加权平均分是是：%.2lf", average);
	printf ("\n\n感谢您使用本计算器，再会~\n");
}

//主函数 
int main () 
{
	//让窗口好看的设置（没啥特别的用处） 
	system("color 90");
	system("mode con cols=60 lines=35");
	
	//调用欢迎内容 
	welcome();
	
	//输入控制 
	while (i<n) {
		int flag = get(i);
		if (flag == -1)	{
			if(returnGet() == 1)	i -= 2;
			else i--;
		}
		else if (flag == 1)	{
			if(end() == 1)	break;
			else i--;
		}
		else if (flag == 2)	{
			printf("您好，您输入的数据有问题，请重新输入\n");
			i--; 
		}
		i++;
	}
	
	//计算GPA的值 
	calculateGPA(i);
	
	//计算加权平均分的值 
	calculateAve(i);
	
	//输出结果
	thanks();
	 
	//系统暂停 
	system("pause");
	
	return 0;
}

