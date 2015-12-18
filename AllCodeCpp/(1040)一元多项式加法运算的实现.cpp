#include <iostream>
#include <string>
using namespace std;

typedef struct polynomial  
{  
    int factor;//系数  
    int indice;//指数  
    struct polynomial *next;  
}LinkList;

void creat(LinkList *&L,int *factors,int *indices,int len)
{
	L = new LinkList;
	LinkList *s,*r = L;
	int i;
	for(i = 0;i < len;i++)
	{
		s = new LinkList;
		s->factor = factors[i];
		s->indice = indices[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

int findSameIndice(LinkList *L,int indice)
{
	LinkList *r = L->next;
	int myFactor = 0;
	while(r!=NULL)
	{
		if(indice==r->indice)
		{
			myFactor = r->factor;
			break;
		}
		r = r->next;
	}
	return myFactor;
	
}

void addPoly(LinkList *L1,LinkList *L2,LinkList *&L3)
{
	LinkList *r = L1->next;
	int factors[50],indices[50];
	int index = -1;
	while(r!=NULL)
	{
		int m = findSameIndice(L2,r->indice);
		index++;
		indices[index] = r->indice;
		factors[index] = r->factor + m;
		r = r->next;
	}
	r = L2->next;
	while(r!=NULL)
	{
		int m = findSameIndice(L1,r->indice);
		if(0==m)
		{
			index++;
			indices[index] = r->indice;
			factors[index] = r->factor;
		}
		r = r->next;
	}
	creat(L3,factors,indices,index);
	return;
}

void VisitList(LinkList *L)  
{  
    LinkList *p;  
    p = L->next;  
    if (p==NULL)  
    {  
        cout<<"0"<<endl;  
    }  
    while (p) 
    {  
        cout<<p->factor<<"x^"<<p->indice;  
        p = p->next;  
        if(p != NULL)  
            cout<<"+";  
    }  
    cout<<endl;  
}

int main()
{
	LinkList *L1 = NULL,*L2 = NULL,*L3 = NULL;
	int factors[50],indices[50];
	string temp;
	int index = -1,i;
	while(cin>>temp){
		index++;
		if (int(temp[0]) - '0' == 0 && int(temp[2]) - '0' == 0)break;
		factors[index] = int(temp[0])- '0';
		indices[index] = int(temp[2])- '0';
	}
	creat(L1, factors, indices, index);

	for (i = 0; i < index;i++)
	{
		factors[i] = 0;
		indices[i] = 0;
	}
	index = -1;
	while(cin>>temp){
		index++;
		if (int(temp[0]) - '0' == 0 && int(temp[2]) - '0' == 0)break;
		factors[index] = int(temp[0]) - '0';
		indices[index] = int(temp[2]) - '0';
	}
	creat(L2, factors, indices, index);
	addPoly(L1,L2,L3);
	VisitList(L3);
	return 0;
}
