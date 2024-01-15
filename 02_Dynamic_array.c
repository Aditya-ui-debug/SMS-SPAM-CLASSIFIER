#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct dynamicarray
{
    int *ptr;
    int lastindex;
    int capacity;
};
struct dynamicarray * creatarray(int size)
{
    struct dynamicarray *p;
    p=(struct dynamicarray *)malloc(sizeof(struct dynamicarray));
    p->ptr=(int *)malloc(size*sizeof(int));
    p->lastindex=-1;
    p->capacity=size;
    return(p);
}
void append(struct dynamicarray *p,int data)
{
    if(p->capacity==p->lastindex+1)
    {
        doublearray(p);
    }
    p->lastindex+=1;
    p->ptr[p->lastindex]=data;
}
void insert(struct dynamicarray *p,int index,int data)
{
    if(index<0 || index>p->lastindex+1)
    {
        printf("invalid index\n");
    }
    else
    {
        if(p->capacity==p->lastindex+1)
        {
            doublearray(p);
        }
        for(int i=p->lastindex; i>=index; i--)
        {
            p->ptr[i+1]=p->ptr[i];
        }
        p->ptr[index]=data;
        p->lastindex+=1;
    }
}
int count(struct dynamicarray *p)
{
    return(p->lastindex+1);
}
void delete(struct dynamicarray *p,int index)
{
    if(index<0 || index>p->lastindex)
    {
        printf("invalid index\n");
    }
    else
    {
        for(int i=index; i<p->lastindex; i++)
        {
            p->ptr[i]=p->ptr[i+1];
        }
        p->lastindex-=1;
    }
}
void view(struct dynamicarray *p)
{
    for(int i=0; i<=p->lastindex; i++)
    {
        printf("%d ",p->ptr[i]);
    }
    getch();
}
void edit(struct dynamicarray *p,int index,int data)
{
    if(index<0 || index>p->lastindex)
    {
        printf("invalid index\n");
    }
    else{
        p->ptr[index]=data;
    }
}
void get(struct dynamicarray *p,int index)
{
    if(index<0 || index>p->lastindex)
    {
        printf("invalid index\n");
    }
    else{
        printf("%d",p->ptr[index]);
    }
    getch();
}
int search(struct dynamicarray *p,int data)
{
    int c=0;
    for(int i=0; i<=p->lastindex; i++)
    {
        if(p->ptr[i]==data)
        {
            return(1);
            c++;
            break;
        }
    }
    if(c==0)
    return(0);
}
void doublearray(struct dynamicarray *p)
{
    int *s;
    s=(int *)malloc((p->capacity*2)*sizeof(int));
    for(int i=0; i<=p->lastindex; i++)
    {
        s[i]=p->ptr[i];
    }
    free(p->ptr);
    p->ptr=s;
    p->capacity*=2;
}
void fit(struct dynamicarray *p)
{
    int *d;
    d=(int *)malloc((p->lastindex+1)*sizeof(int));
    for(int i=0; i<=p->lastindex; i++)
    {
        d[i]=p->ptr[i];
    }
    free(p->ptr);
    p->ptr=d;
    p->capacity=p->lastindex+1;
}
int menu()
{
    int choice;
    printf("\n 1.append");
    printf("\n 2.insert");
    printf("\n 3.delete");
    printf("\n 4.print");
    printf("\n 5.edit");
    printf("\n 6.get");
    printf("\n 7.search");
    printf("\n 8.fit_array");
    printf("\n 9.exit\n");
    printf("\n Enter your choice...");
    scanf("%d",&choice);
    return(choice);
}

int main()
{
    int data,index,s,size;
    struct dynamicarray *p;
    printf("\nEnter the size of array ");
    scanf("%d",&size);
    p=creatarray(size);
    while(1)
    {
        system("cls");
        printf("\n capacity = %d",p->capacity);
        printf("\n count = %d",count(p));

        switch(menu())
        {
            case 1:printf("\n Enter the data ");
            scanf("%d",&data);
            append(p,data);
            break;
            
            case 2:printf("\n Enter the index number ");
            scanf("%d",&index);
            printf("\n Enter the data to insert ");
            scanf("%d",&data);
            insert(p,index,data);
            break;
            
            case 3:printf("\n Enter the index no.to be deleted ");
            scanf("%d",&index);
            delete(p,index);
            break;
            
            case 4:view(p);
            break;
            
            case 5:printf("\n Enter the index number who's data you want to edit ");
            scanf("%d",&index);
            printf("\n Enter the data ");
            scanf("%d",&data);
            edit(p,index,data);
            break;
            
            case 6:printf("\n Enter the index number who's data you want to print ");
            scanf("%d",&index);
            get(p,index);
            break;
            
            case 7:printf("\n Enter the data you want to search ");
            scanf("%d",&data);
            s=search(p,data);
            if(s==1)
            printf("\n Numeber found... ");
            else
            printf("\n Number not found... ");
            break;
            
            case 8:fit(p);
            break;
            
            case 9:exit(0);
            
            default : printf("wrong choice... ");
        }
    }
    return 0;
}