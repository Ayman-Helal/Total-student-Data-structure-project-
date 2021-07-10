#include <stdio.h>
#include <stdlib.h>

struct student
{
    int id;
    char name[25];
    int birth_of_date[3];
    int score_of_last_year;                        //Data of the student
    struct student *nextptr;           //Address of the next node
}*head,*tail;

void createList(int n); // function to create the list
void Insert_in_list();//function to insert 
void displayList();         // function to display the list

int main()
{
    int n,m,index;

		printf("welcome to our system:\n");
		printf("*******************************************************************************\n");

    printf(" Input the number of students : ");
    scanf("%d", &n);
    if (n==0)
    printf("no students");
    else
    createList(n);
    
   Insert_in_list();
   
    printf("\n Data entered in the list : \n");
    displayList();
    return 0;






























































}
void createList(int n)
{
    struct student *currentstu;
    int num,score, i,j,date[3];
    char name1[25];
    head = (struct student *)malloc(sizeof(struct student));

    if(head == NULL) //check whether the head is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the first student through keyboard
 fflush(stdin); // to solve buffer problem

      printf(" enter name of student 1 : ");
         gets(name1);
       strcpy(head->name,name1);


        printf(" enter ID of student 1 : ");
        scanf("%d", &num);
        head->id = num;

   printf(" enter birth of date of student 1 :     (press enter key after every number)\n ");
    for(j=0;j<=2;j++)
        {
        scanf(" %d",&date[j]);
        head->birth_of_date[j]=date[j];
        }

       printf(" enter score of last year of student 1 : ");
       scanf("%d",&score);
       head->score_of_last_year=score;

        head->nextptr = NULL; // links the address field to NULL
        tail = head;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            currentstu = (struct student *)malloc(sizeof(struct student));
            if(currentstu == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                fflush(stdin);

                 printf(" enter name of student %d: ",i);
               gets(name1);
               strcpy(currentstu->name,name1);

               printf(" enter Id of student %d : ", i);
                scanf(" %d", &num);
                currentstu->id = num;


            printf(" enter birth of date of student %d:",i);
            printf("      (press enter key after every number)\n ");

            for(j=0;j<=2;j++)
        {
        scanf(" %d",&date[j]);
        currentstu->birth_of_date[j]=date[j];
        }



        printf(" enter score of last year of student %d: ",i);
       scanf("%d",&score);
       currentstu->score_of_last_year=score;



                currentstu->nextptr = NULL; // links the address field of currentstu with NULL

                tail->nextptr = currentstu; // links previous node i.e. tail to the currentstu
                tail = tail->nextptr;
            }
        }
    }
}

void Insert_in_list()
{
	int c,num,score,j,date[3];
  char name1[25];
  
	  printf(" if you want to : \n insert a new student in the beginning enter (1) \n insert a new student in the end enter(2) \n insert anew student in the middle (3) \n finish (0) ");
    scanf("%d", &c);

    switch(c)
    {

case 1 :
   
  {
  struct student *newstu;
  newstu=(struct student *)malloc(sizeof(struct student));

    if(newstu == NULL) //check whether the newstu is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
      // reads data for the first student through keyboard
 fflush(stdin); // to solve buffer problem

      printf(" enter name of the new student  : ");
         gets(name1);
       strcpy(newstu->name,name1);


        printf(" enter ID of the new student: ");
        scanf("%d", &num);
        newstu->id = num;

   printf(" enter birth of date of the new student :     (press enter key after every number)\n ");
    for(j=0;j<=2;j++)
        {
        scanf(" %d",&date[j]);
        newstu->birth_of_date[j]=date[j];
        }

       printf(" enter score of last year of the new student : ");
       scanf("%d",&score);
       newstu->score_of_last_year=score;

      newstu->nextptr = NULL; // links the address field of newstu with NULL
      newstu->nextptr=head; // insert the new student in the beginning of the linked list
      head=newstu;
    }}
    break;
case 2 :
{

  struct student *newstu;
  newstu=(struct student *)malloc(sizeof(struct student));

    if(newstu == NULL) //check whether the newstu is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
      // reads data for the first student through keyboard
 fflush(stdin); // to solve buffer problem

      printf(" enter name of the new student  : ");
         gets(name1);
       strcpy(newstu->name,name1);


        printf(" enter ID of the new student: ");
        scanf("%d", &num);
        newstu->id = num;

   printf(" enter birth of date of the new student :     (press enter key after every number)\n ");
    for(j=0;j<=2;j++)
        {
        scanf(" %d",&date[j]);
        newstu->birth_of_date[j]=date[j];
        }

       printf(" enter score of last year of the new student : ");
       scanf("%d",&score);
       newstu->score_of_last_year=score;

      newstu->nextptr = NULL; // links the address field of newstu with NULL
      tail->nextptr=newstu; // insert the new student in the end of the linked list
      tail=newstu;
}}
    break;
case 3 :
	{
	
         int k,i;
  struct student *newstu,*prestu,*nxtstu;

  printf("enter the position(the position should be greater than 1): ");
  scanf("%d",&k);
  k=k-1;


  prestu=head;

  for(i=0;i<k-1;i++)
  {
     prestu=prestu->nextptr; //moving through the linked list to reach the index
  }
  nxtstu=prestu->nextptr;

  newstu=(struct student *)malloc(sizeof(struct student));

    if(newstu == NULL) //check whether the newstu is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
      // reads data for the first student through keyboard
 fflush(stdin); // to solve buffer problem

      printf(" enter name of the new student  : ");
         gets(name1);
       strcpy(newstu->name,name1);


        printf(" enter ID of the new student: ");
        scanf("%d", &num);
        newstu->id = num;

   printf(" enter birth of date of the new student :     (press enter key after every number)\n ");
    for(j=0;j<=2;j++)
        {
        scanf(" %d",&date[j]);
        newstu->birth_of_date[j]=date[j];
        }

       printf(" enter score of last year of the new student : ");
       scanf("%d",&score);
       newstu->score_of_last_year=score;

       newstu->nextptr=NULL;  //links the address field of newstu with NULL

       newstu->nextptr=nxtstu;  // insert the new student between prestu and nxtstu
       prestu->nextptr=newstu;

}}
    break;
case 0 :
    break;
    }
  
}



void displayList()
{
    int i;
    struct student *tail;
    if(head == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tail = head;
        while(tail != NULL)
        {
            // prints the data of current node
           printf(" name = %s\n", tail->name);
           printf(" ID = %d\n", tail->id);
           printf(" date of birth= ");
            for (i=0;i<=2;i++)
            {
                printf(" %d",tail->birth_of_date[i]);
            }
            printf("\n score of last year= %d\n",tail->score_of_last_year);
            printf("**************************************************************************************\n");

            tail = tail->nextptr;                     // advances the position of current node
        }
    }
}
