#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student {
    char name[25];
    int id;
    int date_of_birth[3];
    int score_of_last_year;
    };

struct student *createDynArr(int N);
void insert(char name[], int id,int day, int month, int year, int score, int pos);
void display();

struct student *ptr;
int N;

int main(){
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

  }
}







































































































































































































































































































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

