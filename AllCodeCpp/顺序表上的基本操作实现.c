顺序表上的基本操作实现 
标签： 顺序表 基本操作 初始化 插入 删除 合并 逆置 it	
标题：	顺序表上的基本操作实现
时 限：	1000 ms
内存限制：	10000 K
总时限：	3000 ms
描述：	在顺序存储结构实现基本操作：初始化、创建、插入、删除、查找、遍历、逆置、合并运算。
输入：	请输入线性表La的长度:n
a1 a2 a3 ...an（数值有序，为降序）
请输入要插入到线性表La中的数字x和插入的位置i:x i
请输入要删除数字的位置:i
请输入要查找的数字:x
请输入线性表长度:m
b1 b2...bm(数值有序，为升序)
输出：	创建好的线性表La=a1 a2...an
插入一个数字后的线性表a1 a2...an+1
删除一个数字后的线性表a1 a2...an
查找一个输入的数字后如果找到，输出该数字的位置i,如果没有找到，输出"没有找到x"的信息。
逆置a1 a2...an后的线性表an an-1...a1
合并两个线性表后的线性表
输入样例：	
请输入线性表La的长度：5
请输入线性表La中的元素：14 11 10 9 5
请输入要插入到线性表La中的数字x和插入的位置i：8 4
线性表La=14 11 10 8 9 5
请输入要删除的数字的位置：4
线性表La=14 11 10 9 5
请输入要查找的数字：10
找到，10在第3个位置
逆置后的线性表La=5 9 10 11 14
请输入线性表Lb的长度：4
请输入线性表Lb中的元素：1 3 6 9
合并La和Lb后的线性表为：1 3 5 6 9 9 10 11 14


#include<stdio.h>
#define MaxSize 100
typedef int DataType;

typedef struct//定义结构体Seqlist
{
    DataType list[MaxSize];
    int size;
} SeqList;

//初始化顺序表L
void ListInitiate(SeqList *L)
{
    L->size=0;               //定义初始数据元素个数
}

int ListLength(SeqList L)//当前数据元素个数
{
    return L.size;
}


int ListInsert(SeqList *L,int i,DataType x)
{
    int j;
    if(L->size>=MaxSize)
    {
        printf("顺序表已满无法插入!\n");
        return 0;
    }
    else if(i<0||i>L->size)
    {
        printf("i is error");
        return 0;
    }
    else
    {
        for(j=L->size; j>i-1; j--)L->list[j]=L->list[j-1];

        L->list[i-1]=x;
        L->size++;
        return 0;
    }
}


//删除数据元素
int ListDelete(SeqList *L,int i)
{
    int j;
    if(L->size<=0)
    {
        printf("顺序表已无数据元素可删!\n");
        return 0;
    }
    else if(i<0||i>L->size-1)
    {
        printf("i is error\n");
        return 0;
    }
    else
    {
        //*x=L->list[i];
        for(j=i; j<=L->size-1; j++)L->list[j-1]=L->list[j];

        L->size--;
        return 0;
    }
}


//查找数据元素
int ListSearch(SeqList L,DataType x)
{
    int i;
    for (i=0; i<L.size; i++)
    {
        if(L.list[i]==x)
        {
            printf("找到，%d在第%d个位置",x,i+1);
            return 0;
        }

    }
    printf("没有找到%d",x);

    return 0;

}

//逆置
int ListReverse(SeqList *L)
{
    int i,m=L->size/2,n=L->size;
    DataType tmp;

    for (i=0; i<m; i++)
    {
        tmp=L->list[i];
        L->list[i]=L->list[n-1-i];
        L->list[n-1-i]=tmp;

    }
}

//合并
int  ListMerger(SeqList *La,SeqList *Lb,SeqList *Lc)
{
    int i=0,j=0,k=0;
    while(i<La->size&&j<Lb->size)
    {
        if(La->list[i]<Lb->list[j])
        {
            Lc->list[k]= La->list[i];
            i++;
            k++;
        }

        else
        {
            Lc->list[k]= Lb->list[j];
            j++;
            k++;
        }
    }
    while(i<La->size)
    {
        Lc->list[k++]= Lb->list[i++];
    }



    while(j<Lb->size)
    {
        Lc->list[k++]= La->list[j++];
    }
    Lc->size=k;
    return 0;
}

int main(void)
{
    SeqList La,Lb,Lc;
    int i,x;
    int n,m;//线性表长度

    ListInitiate(&La);
    printf("请输入线性表La的长度:");
    scanf ("%d",&n);
    La.size=n;
    printf("请输入线性表La中的元素:");
    for(i=0; i<n; i++)
        scanf ("%d",&La.list[i]);

    printf("请输入要插入到线性表La中的数字x和插入的位置i:");
    scanf("%d%d",&x,&i);
    ListInsert(&La,i,x);
    printf("线性表La=");
    for(i=0; i<La.size; i++)
        printf("%d ",La.list[i]);

    printf("\n请输入要删除的数字的位置:");
    scanf("%d",&i);
    ListDelete(&La,i) ;
    printf("线性表La=");
    for(i=0; i<La.size; i++)
        printf("%d ",La.list[i]);

    printf("\n请输入要查找的数字:");
    scanf("%d",&x);
    ListSearch(La,x);
    ListReverse(&La);
     printf("\n逆置后的线性表La=");
    for(i=0; i<La.size; i++)
        printf("%d ",La.list[i]);

    ListInitiate(&Lb);
    printf("\n请输入线性表Lb的长度:");
    scanf ("%d",&m);
    Lb.size=m;
    printf("请输入线性表Lb中的元素:");
    for(i=0; i<m; i++)
        scanf ("%d",&Lb.list[i]);
    ListInitiate(&Lc);

    ListMerger(&La,&Lb,&Lc);
    printf("合并后La和Lb后的线性表:");
    for(i=0; i<Lc.size; i++)
        printf ("%d ",Lc.list[i]);
    return 0;
}