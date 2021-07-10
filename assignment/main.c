#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// structure student
//-----------------------------------------------------------------------------------------------------------------------------------------------------
struct student {
    char name[25];
    int id;
    int date_of_birth[3];
     int score_of_last_year;                        //Data of the student
    struct student *nextptr;           //Address of the next node
}*head,*tail;

 struct student *ptr;
int N;
struct student *createDynArr(int N);
void insert(char name[], int id,int day, int month, int year, int score, int pos);
void display();
void createList(int n); // function to create the list
void Insert_in_list();//function to insert
void displayList();         // function to display the list




//  main function
//--------------------------------------------------------------------------------------------------------------------------------------------------
int main(){

  int ch;

		printf("welcome to our system:\n");
		printf("*******************************************************************************\n");
		printf("for linked list enter (0)\n");
		fflush(stdin);
	    printf("for Array enter (1)\n");
	    scanf("%d", &ch);
	    switch(ch){
case 0:
{
		int n,m,index;
    printf(" Enter the number of students : ");
    scanf("%d", &n);
    if (n==0)
    printf("no students");
    else
    createList(n);

   Insert_in_list();

    printf("\n Data entered in the list : \n");
    displayList();
    break;


}
case 1:
{
	 printf("Enter number of students: ");
    scanf("%d", &N);
    ptr = createDynArr(N);
    display();
      while(1){
        int add;
        printf("Choose an option[1,2] \n 1. Add another student.\n 2. End program\n");
        scanf("%d" , &add );
  if (add == 1){
    int pos, id,score_of_last_year, date_of_birth[3];
    char name[25];
    N++;
    ptr = realloc(ptr, N * sizeof(struct student));
    if (ptr == NULL) {
    printf("Memory not reallocated.\n");
    exit(0);
    }
    else {
    // Memory has been successfully reallocated
    printf("Memory successfully reallocated.\n");
    }
    do{
             fflush(stdin);
    printf("%d students data in array:\n", N - 1 );
    printf("(position should be from 1 to %d)\n", N);
     fflush(stdin);
    printf("Enter position where the data should be stored:\n");
    scanf("%d", &pos);
    }while( pos > N );
     fflush(stdin);
    printf("Enter name:\n");
    scanf("%s", name );
     fflush(stdin);
    printf("Enter id:\n");
    scanf("%d", &id );
     fflush(stdin);
    printf("Enter date of birth:\n");
    for ( int j = 0; j < 3; ++j)
        scanf("%d", &date_of_birth[j] );
         fflush(stdin);
    printf("Enter socre:\n");
    scanf("%d", &score_of_last_year );
    insert(name,id,date_of_birth[0],date_of_birth[1],date_of_birth[2],score_of_last_year,pos);
    display();

  }
  else{
    exit(0);
  }

  }break;
}

}
return 0;
}




//linked list functions
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

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
        head->date_of_birth[j]=date[j];
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
        currentstu->date_of_birth[j]=date[j];
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
  int L=1;
while(L==1)
      {
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
        newstu->date_of_birth[j]=date[j];
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
        newstu->date_of_birth[j]=date[j];
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
        newstu->date_of_birth[j]=date[j];
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
     {
      L=0;
     }
    break;
    }
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
                printf(" %d",tail->date_of_birth[i]);
            }
            printf("\n score of last year= %d\n",tail->score_of_last_year);
            printf("**************************************************************************************\n");

            tail = tail->nextptr;                     // advances the position of current node
        }
    }
}


//Array functios
//-------------------------------------------------------------------------------------------------------------------------------------------

struct student *createDynArr(int N){
    // Memory allocation for noOfstudents structures
    ptr = (struct student *)malloc(N * sizeof(struct student));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
   else {
        // Memory has been successfully allocated
        printf("Memory successfully allocated.\n");
   }

   for (int i = 0; i < N; ++i) {
         fflush(stdin);
        printf("Enter name %d:\n", i+1);
        scanf("%s", (ptr + i)->name );
    fflush(stdin);
        printf("Enter id:\n");
        scanf("%d", &(ptr + i)->id );
         fflush(stdin);
        printf("Enter date of birth:\n");
        for ( int j = 0; j < 3; ++j)
            scanf("%d", &(ptr + i)->date_of_birth[j] );
             fflush(stdin);
        printf("Enter socre:\n");
        scanf("%d", &(ptr + i)->score_of_last_year );
  }
  return ptr;
}
void display(){
    printf("Displaying Information:\n");
  for (int i = 0; i < N; ++i) {
    printf("Name:%s\n ID:%d\n Date of birth:%d/%d/%d\n Score:%d\n", (ptr + i)->name, (ptr + i)->id, (ptr + i)->date_of_birth[0], (ptr + i)->date_of_birth[1], (ptr + i)->date_of_birth[2] , (ptr + i)->score_of_last_year );
  }
}
void insert(char name[], int id,int day, int month, int year, int score, int pos){
    for (int i = N-1; i >= pos; i--)
    {
        for ( int j = 0; j < 25; ++j)
            (ptr + i)->name[j] = (ptr + i - 1)->name[j];
        (ptr + i)->id = (ptr + i - 1)->id;
        for ( int j = 0; j < 3; ++j)
            (ptr + i)->date_of_birth[j] = (ptr + i -1)->date_of_birth[j] ;
        (ptr + i)->score_of_last_year = (ptr + i - 1)->score_of_last_year;
    }

    strcpy((ptr + pos - 1)->name,name);
    (ptr + pos - 1)->id =id;
    (ptr + pos - 1)->date_of_birth[0] = day;
    (ptr + pos - 1)->date_of_birth[1] = month;
    (ptr + pos - 1)->date_of_birth[2] = year;
    (ptr + pos - 1)->score_of_last_year =score;

}


