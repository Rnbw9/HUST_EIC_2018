#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _char_fre
{
    char a;
    int fre;
}char_fre;

typedef struct _HuffmanTree
{
    char ch;
    int weight;
    int parent,lchild,rchild;
}*HuffmanTree,HTree;

typedef char** HuffmanCode;

void Select(HuffmanTree HT,int n,int* s1,int* s2)//修改多次 值得反思
{
    int i,m1,m2;
    HuffmanTree begin=HT;
    m1=m2=1000;//要设得足够大才不会出错
    for(i=1;i<=n;i++,HT++)
    {
        if(HT->parent!=0)
            continue;
        else
        {
            if(HT->weight<=m1)
            {
                m1=HT->weight;
                *s1=i;
            }
        }
    }
    HT=begin;
    for(i=1;i<=n;i++,HT++)
    {
        if(HT->parent!=0)
            continue;
        else
        {
            if(HT->weight<=m2&&i!=*s1)
            {
                m2=HT->weight;
                *s2=i;
            }
        }
    }
}

void HuffmanCoding(HuffmanTree HT,HuffmanCode HC,char_fre* element,int n)
{
    //Initializing and Coding part
    if(n<=1) return;
    int m=2*n-1;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTree));
    HuffmanTree p=HT+1;
    int i,j,k,c,f,s1=1,s2=1,start;
    for(i=1;i<=n;i++,p++,element++)
    {
        p->ch=element->a;
        p->weight=element->fre;
        p->parent=0;
        p->lchild=0;
        p->rchild=0;
    }
    for( ;i<=m;i++,p++)
    {
        p->ch='#';
        p->weight=0;
        p->parent=0;
        p->lchild=0;
        p->rchild=0;
    }
    for(i=n+1;i<=m;i++)
    {
        Select(HT+1,i-1,&s1,&s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
    char* cd;
    cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(i=1;i<=n;i++)
    {
        start=n-1;
        for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
        {
            if(HT[f].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
        }
        HC[i]=(char*)malloc((n-start)*sizeof(char));
        strcpy(HC[i],&cd[start]);
    }
    free(cd);
    for(i=1;i<=n;i++)
    {
        printf("%c:",HT[i].ch);
        puts(HC[i]);
    }
    //Encoding Decoding part
    char string[]={"THIS PROGRAM IS MY FAVORITE"};
    char STRING[200]={'\0'};
    for(i=0;i<strlen(string);i++)
    {
        for(j=1;j<=n;j++)
        {
            if(string[i]==HT[j].ch)
            {
                printf("%s",HC[j]);
                strcat(STRING,HC[j]);
            }
        }
    }
    printf("\n");
    char code[20]={'\0'};
    for(i=0,j=0;i<strlen(STRING);i++,j++)
    {
        code[j]=STRING[i];
        code[j+1]='\0';
        for(k=1;k<=n;k++)
        {
            if(strcmp(code,HC[k])==0)
                {
                    code[0]='\0';
                    j=-1;
                    printf("%c",HT[k].ch);
                }
        }
    }
    printf("\n");
}
void main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int i;
    char_fre element[27]={{' ',186},{'A',64},{'B',13},{'C',22},{'D',32},{'E',103},{'F',21},{'G',15},
    {'H',47},{'I',57},{'J',1},{'K',5},{'L',32},{'M',20},{'N',57},{'O',63},{'P',15},{'Q',1},{'R',48},
    {'S',51},{'T',80},{'U',23},{'V',8},{'W',18},{'X',1},{'Y',16},{'Z',1}};
    HuffmanCoding(HT,HC,element,27);
}
