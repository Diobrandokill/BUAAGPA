//������ΪGPA����Ȩƽ���ּ�������������BUAA���õ��㷨
//���ʱ��Ϊ2020.1.24�����޺����޸ļƻ� 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 100

//��ӭ���������� 
void welcome () {
	//��ʼ�� 
	printf("*********************************************************\n");
	printf("**         ��ӭʹ��GPA���Ȩƽ���ּ�����               **\n");
	printf("**      �������������ڱ������պ����ѧGPA�㷨          **\n");
	printf("**    �����������Խ���ϵͳ��ʾΪ׼������������ο�   **\n");
	printf("**  ���ߣ�����������  ��ϵ��ʽ��kongyoubuaa@gmail.com  **\n");
	printf("*********************************************************\n\n\n");
	
	//������ 
	printf("*********************************************************\n");
	printf("**         ��������ÿһ����Ҫ����ɼ���ѧ��            **\n");
	printf("**      �����Ҫ�޸���һ����Ϣ��������-1 -1���س�      **\n");
	printf("**          �����Ҫ�������룬������0 0���س�          **\n");
	printf("**          �밴��ʾҪ�����룬������100�ſγ�          **\n");
	printf("**     �ɼ���ѧ�ּ��Կո������ÿ����������밴�س�    **\n");
	printf("*********************************************************\n\n\n");
}

//��ش洢�ռ��ʼ�� 
int i = 0;
struct part{	
	double score;
	double credit;
	};
struct part store[105];
double GPA;
double average;//��ش洢�ռ��ʼ������ 

//��ȡ������Ϣ 
int get (int i) {
	printf("���� %d �ſε� �ɼ���ѧ�� �ֱ�Ϊ�����ÿո��������", i + 1);
	scanf("%lf%lf", &store[i].score, &store[i].credit);
	//printf("%lf%lf", store[i].score, store[i].credit);
	if(store[i].score==-1 && store[i].credit==-1)	return -1;//�޸� 
	if(store[i].score==0 && store[i].credit==0)	return 1;//�������� 
	if(store[i].score<0 || store[i].score>100 
		|| store[i].credit<0 || store[i].credit>10)	return 2;//�쳣���� 
	return 0;//�������� 
}

//�޸�����ȷ�Ϻ��� 
int returnGet() {
	int flag;
	printf("ȷ���޸���һ�������ȷ���밴1��ȡ���޸��밴0����");
	scanf("%d", &flag);
	return flag;
}

//ֹͣ����ȷ�Ϻ��� 
int end() {
	int flag;
	printf("ȷ��ֹͣ���룿��ȷ���밴1�����������밴0����");
	scanf("%d", &flag);
	return flag;
}

//����ƽ��GPA 
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

//�����Ȩƽ���� 
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
	printf ("\n\n����GPA�ǣ�%.4lf", GPA);
	printf ("\n���ļ�Ȩƽ�������ǣ�%.2lf", average);
	printf ("\n\n��л��ʹ�ñ����������ٻ�~\n");
}

//������ 
int main () 
{
	//�ô��ںÿ������ã�ûɶ�ر���ô��� 
	system("color 90");
	system("mode con cols=60 lines=35");
	
	//���û�ӭ���� 
	welcome();
	
	//������� 
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
			printf("���ã�����������������⣬����������\n");
			i--; 
		}
		i++;
	}
	
	//����GPA��ֵ 
	calculateGPA(i);
	
	//�����Ȩƽ���ֵ�ֵ 
	calculateAve(i);
	
	//������
	thanks();
	 
	//ϵͳ��ͣ 
	system("pause");
	
	return 0;
}

