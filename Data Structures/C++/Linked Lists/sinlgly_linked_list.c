#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *nxt;
};
typedef struct node n;
n *temp = NULL;
n *fst = NULL;
n *ptr = NULL;
void create()
{
    temp = (n *)(malloc(sizeof(n)));
    printf("Enter Data\n");
    scanf("%d", &temp -> data);
    temp -> nxt = NULL;
    if(fst == NULL)
        fst = temp;
    else
        ptr -> nxt = temp;
    ptr = temp;
}
void display()
{   temp = fst;
    do
    {
        printf("%d\t", temp -> data);
        temp = temp -> nxt;
    }while(temp != NULL);
    printf("\n");
}
int main()
{
    while(1){
        create();
        display();
    }
    return 0;
}
