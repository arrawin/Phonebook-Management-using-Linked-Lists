#include<stdio.h>
#include<stdlib.h>
void createphone();
void insertphone();
void delphone();
void displayphone();
struct node
{
char number[200];
char name[200];
struct node *link;
};
struct node *first=NULL,*last=NULL,*next,*prev,*cur;
void createphone()
{
 cur=(struct node*)malloc(sizeof(struct node));
 printf("\nENTER THE NAME OF THE PERSON: ");
 scanf("%s",cur->name);
 num: printf("\nENTER THE PHONE NUMBER OF THE PERSON: ");
 scanf("%s",cur->number);
 int length =   strlen(cur->number);
 if(length == 11 || length<10){
    printf("\nENTER A VALID NUMBER AND TRY AGAIN\n");
    goto num;

  }
 cur->link=NULL;
 first=cur;
 last=cur;
}
void insertphone()
{
 int pos,c=1;
 cur=(struct node*)malloc(sizeof(struct node));
 printf("\nENTER THE NAME OF THE PERSON: ");
 scanf("%s",cur->name);
 num: printf("\nENTER THE PHONE NUMBER OF THE PERSON: ");
 scanf("%s",cur->number);
 int length =   strlen(cur->number);
 if(length == 11 || length<10){
    printf("\nENTER A VALID NUMBER AND TRY AGAIN\n");
    goto num;
 }
 printf("\nENTER THE POSITION: ");
 scanf("%d",&pos);
 if((pos==1) &&(first!=NULL))
 {
cur->link = first;
 first=cur;
 }
 else
 {
 next=first;
 while(c<pos)
 {
 prev=next;
 next=prev->link;
 c++;
 }
 if(prev==NULL)
 {
 printf("\nINVALID POSITION\n");
 }
 else
 {
 cur->link=prev->link;
 prev->link=cur;
 }
}
}
void delphone()
{
int pos,c=1;
printf("\nENTER THE POSITION TO DELETE CONTACT DETAILS: ");
scanf("%d",&pos);
if(first==NULL)
{
printf("\nLIST IS EMPTY\n");
}
else if(pos==1 && first->link==NULL)
{
printf("\n DELETED CONTACT NAME IS %s AND NUMBER IS %s\n",first->name,first->number);
free(first);
first=NULL;
}
else if(pos==1 && first->link!=NULL)
{
cur=first;
first=first->link;
cur->link=NULL;
printf("\n DELETED CONTACT NAME IS %s AND NUMBER IS %s\n",cur->name,cur->number);
free(cur);
}
else
{
next=first;
while(c<pos)
{
next=next->link;
c++;
}
cur->link=next->link;
next->link=NULL;
if(next==NULL)
{
printf("\nINVALID POSITION\n");
}
else
{
printf("\n DELETED CONTACT NAME IS %s AND NUMBER IS %s\n",next->name,next->number);
free(next);
}
}
}
void displayphone()
{
 cur=first;
 while(cur!=NULL)
 {
 printf("\n NAME     :%s",cur->name);
 printf("\n NUMBER   :%s\n",cur->number);
 cur=cur->link;
 }
}

void main()
{
    int ch;
    do
    {

    printf("\n\n*******WELCOME TO PHONEBOOK MANAGEMENT SYSTEM*******\n");
    printf("\n!!!!!!You can easily CREATE,ADD, DELETE, DISPLAY numbers!!!!!!!!\n");
    printf("\n---------MY PHONEBOOK---------");
    printf("\n\n MAIN MENU\n\n");
    printf("1.CREATE CONTACT\n2.ADD CONTACT\n3.DELETE CONTACT\n4.DISPLAY ALL CONTACTS\n");
    printf("\nENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      createphone();
      displayphone();
      break;

      case 2:
      insertphone();
      displayphone();
      break;

      case 3:
      delphone();
      displayphone();
      break;

      case 4:
      exit(0);
    }
}while(ch<=3);
}

