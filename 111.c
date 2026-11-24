#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

struct Student{
    int id;
    char name[20];
    float score[3];
    float total;
    float average;
};

void input(struct Student*p,int n);
void calc(struct Student*p,int n);
void sort(struct Student*p,int n);
void print(struct Student*p,int n);
int count_pass(struct Student*p,int n);

int main(){
    SetConsoleOutputCP(65001);
    int n;
    printf("请输入学生人数：");
    scanf("%d",&n);
    struct Student *p=(struct Student*)malloc(n*sizeof(struct Student));
    if(p==NULL){
        printf("内存分配失败！\n");  
        return 1;
    }
    input(p,n);
    calc(p,n);
    sort(p,n);
    printf("\n---成绩排名表---\n");
    print(p,n);
    int pass_count=count_pass(p,n);
    printf("\n三门全及格人数：%d\n",pass_count);
    free(p);
    return 0;
}

void input(struct Student*p,int n){
    int i,j;
    for(i=0;i<n;i++){
        printf("\n请输入第%d个学生的信息：\n",i+1);
        printf("学号：");
        scanf("%d",&(p+i)->id);
        printf("姓名：");
        scanf("%s",(p+i)->name);
        printf("请输入三门课程成绩：\n");
       
        for(j=0;j<3;j++){
            scanf("%f",&(p+i)->score[j]);
        }
}
}

void calc(struct Student*p,int n){
    int i,j;
    for(i=0;i<n;i++){
        (p+i)->total=0;
        for(j=0;j<3;j++){
            (p+i)->total+=(p+i)->score[j];
        }
        (p+i)->average=(p+i)->total/3.0;
    }
}

void sort(struct Student*p,int n){
    int i,j;
    struct Student temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if((p+j)->total<(p+j+1)->total){
                temp=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=temp;
            }
        }
    }
}

int count_pass(struct Student*p,int n){
    int i,j,pass_count=0;
    for(i=0;i<n;i++){
        int pass=1;
        for(j=0;j<3;j++){
            if((p+i)->score[j]<60){
                pass=0;
                break;
            }
        }
        if(pass){
            pass_count++;
        }
    }
    return pass_count;
}

void print(struct Student*p,int n){
    int i,j;
    printf("学号\t姓名\t成绩1\t成绩2\t成绩3\t总分\t平均分\n");
    for(i=0;i<n;i++){
        printf("%d\t%s\t", (p+i)->id, (p+i)->name);
        for(j=0;j<3;j++){
            printf("%.2f\t", (p+i)->score[j]);
        }
        printf("%.2f\t%.2f\n", (p+i)->total, (p+i)->average);
    }
}