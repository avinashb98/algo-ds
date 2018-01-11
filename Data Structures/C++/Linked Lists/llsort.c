#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *nxt;
};
typedef struct node n;
n *temp,*fst,*ptr;
n* create()
{   temp,fst,ptr=NULL;
    int t;
    printf("Enter the number of elements in list.\n");
    scanf("%d",&t);
    while(t--)
    {
        temp=(n*)(malloc(sizeof(n)));
        printf("Enter data.\n");
        scanf("%d",&temp->data);
        temp->nxt=NULL;
        if(fst==NULL)
            fst=temp;
        else
            ptr->nxt=temp;
    }
    return fst;
}
n* sort(n *first,n *second)
{
    n *temp1,*temp2; //pointers for navigating through two LLs
    int one,two=0;//to determine the lenghts of the lists
    for(temp1=first;temp1->nxt!=NULL;temp1=temp1->nxt)
    one++;
    for(temp1=second;temp1->nxt!=NULL;temp1=temp1->nxt)
    two++;
    if(one<two)//to make sure the one with the greater length is the first LL
    {
        n *swap;
        swap=second;
        second=first;
        first=swap;
    }
    temp1=first;
    temp2=second;
    while(temp2!=NULL)//second list because it is smaller
    {   for(temp1=first;temp!=NULL;temp=temp->nxt)
        {    if(temp2->data>temp1->data)
            {
                if(temp1->nxt->data>temp2->data)//if the second value lies between two values of first
                {   temp2->nxt=temp1->nxt;
                    temp1->nxt=temp2;
                }
                else
                {
                    temp2->nxt=temp1->nxt->nxt;
                    temp1->nxt->nxt=temp2;
                }
                goto LOOP;
            }
            else
            {
                if(temp1==first)//if the second value is the smallest
                {
                    temp2->nxt=first;
                    first=temp2;
                }
                else//if  there is another smaller value
                {
                    n *temp3;
                    for(temp3=first;temp3->nxt!=temp1;temp3=temp3->nxt);//to have the pointer placed at a previous node than the first
                    temp2->nxt=temp1;
                    temp3->nxt=temp2;
                }
                goto LOOP;
            }
        }
        LOOP:temp2=temp2->nxt;
    }
    return first;
}
void main()
{
    n *a,*b;
    a=create();
    b=create();
    n *first=sort(a,b);
    for(temp=first;temp->nxt!=NULL;temp=temp->nxt)
    printf("%d\t",temp->data);
    printf("\n");
}
