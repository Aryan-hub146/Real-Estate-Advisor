#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// This structure is defining the attributes of the property 
typedef struct property{
     char loc[100];
     int id;
     int price;
     int area;
     char swim[100];
     char gard[100];

}pro;
pro p1;
FILE *ptr = NULL;
pro arr[30];
pro arr1[20];
pro arr2[20];
pro arr3[20];

// The function of this module is to add the property details to a file 
void add(){
    ptr = fopen("file1.txt","a");
    char no='y';
    int x=1;
    if (ptr == NULL){
      printf("FILE CAN'T BE OPEN");
      exit(1);
    }
    while(no =='y'){
        printf("Enter the location of the property.......  ");
        gets(p1.loc);
        fflush(stdin);
        printf("Enter the id........  ");
        scanf("%d",&p1.id);
        fflush(stdin);
        printf("Enter the price.......  ");
        scanf("%d",&p1.price);
        fflush(stdin);
        printf("Enter the areas (acre's).....  ");
        scanf("%d",&p1.area);
        fflush(stdin);
        printf("Swimming pool available (Yes/No).....  ");
        gets(p1.swim);
        fflush(stdin);
        printf("Garden available (Yes/No)....  ");
        gets(p1.gard);
        fflush(stdin);
        fprintf(ptr,"%s\n%d\n%d\n%d\n%s\n%s\n\n",p1.loc,p1.id,p1.price,p1.area,p1.swim,p1.gard);
        printf("\nTO ADD MORE TYPE (y/n): ");
        scanf("%c",&no);
        fflush(stdin);
    }
    fclose(ptr);
    
} 

// The function of this module is to display all the property avaliable
void display(){
  ptr = fopen("file1.txt","r");
  if (ptr == NULL){
    printf("File Can't be open");
    exit(1);
  }
  int x=0,count=0;
  rewind(ptr);
  while(feof(ptr)==0){
    fscanf(ptr,"%s%d%d%d%s%s",arr1[x].loc,&arr1[x].id,&arr1[x].price,&arr1[x].area,arr1[x].swim,arr1[x].gard);
    x++;
  }
    printf("\n\n        *********************************");
    printf("\n         !!!!   AVAILABLE PROPERTY   !!!!");
    printf("\n        *********************************\n\n");
  for (int i=0;i<20;i++){
    if (arr1[i].id!=0 || arr1[i].price!=0){
    printf("\n\n!!!   DETAILS OF %d PROPERTY   !!!",i+1);
    printf("\n\nLOCATION----> %s",arr1[i].loc);
    printf("\nID----> %d",arr1[i].id);
    printf("\nPRICE----> %d",arr1[i].price);
    printf("\nAREA(acre's)----> %d",arr1[i].area);
    printf("\nSWIMMING POOL----> %s",arr1[i].swim);
    printf("\nGARDEN----> %s\n",arr1[i].gard);
    count = 1;
    }
  }
  fclose(ptr);
  if (count == 0){
    printf("               !!!   NULL   !!!");
  }
  for (int z=0;z<20;z++){
    arr1[z].id=0;
    arr1[z].price=0;
  }
}

// The function of this module is to display the sold out property
void sold(){
  ptr = fopen("sold.txt","r");
  if (ptr == NULL){
    printf("File Can't be open");
    exit(1);
  }
  int x=0,count=0;
  rewind(ptr);
  while(feof(ptr)==0){
    fscanf(ptr,"%s%d%d%d%s%s",arr1[x].loc,&arr1[x].id,&arr1[x].price,&arr1[x].area,arr1[x].swim,arr1[x].gard);
    x++;
  }
    printf("\n\n        *********************************");
    printf("\n         !!!!   SOLD OUT PROPERTY   !!!!");
    printf("\n        *********************************\n\n");
  for (int i=0;i<20;i++){
    if (arr1[i].id!=0 || arr1[i].price!=0){
    printf("\n\n!!!   DETAILS OF %d PROPERTY   !!!",i+1);
    printf("\n\nLOCATION----> %s",arr1[i].loc);
    printf("\nID----> %d",arr1[i].id);
    printf("\nPRICE----> %d",arr1[i].price);
    printf("\nAREA(acre's)----> %d",arr1[i].area);
    printf("\nSWIMMING POOL----> %s",arr1[i].swim);
    printf("\nGARDEN----> %s\n",arr1[i].gard);
    count = 1;
    }
  }
  fclose(ptr);
  if (count == 0){
    printf("               !!!   NULL   !!!");
  }
  for (int z=0;z<20;z++){
    arr1[z].id=0;
    arr1[z].price=0;
  }

}


// The function of this module is to search the property with respect to user's budget
void search(){

  int budget,x=0;
  ptr  = fopen("file1.txt","r");
    if (ptr == NULL){
      printf("FILE CAN'T BE OPEN");
      exit(1);
    }
    
int acre,cho;
printf("\n\n1>>Enter 1 to search through area");
printf("\n2>>Enter 2 to search through price");
printf("\nEnter your choice.......  ");
scanf("%d",&cho);
fflush(stdin);
    rewind(ptr);
    while (feof(ptr)==0){
    fscanf(ptr,"%s%d%d%d%s%s",arr[x].loc,&arr[x].id,&arr[x].price,&arr[x].area,arr[x].swim,arr[x].gard);
    x++;
    }

  fclose(ptr);
  int hj=0,fc=0;
  switch (cho){
    
    case 1:
     printf("Enter your Desired area.....  ");
     scanf("%d",&acre);
     fflush(stdin);
    printf("\n\n        *********************************");
    printf("\n         !!!!   AVAILABLE PROPERTY   !!!!");
    printf("\n        *********************************\n\n");
     for (int i=0;i<30;i++){
     if (acre==arr[i].area || acre>arr[i].area && arr[i].price!=0){
    printf("\n\n!!!   DETAILS OF %d PROPERTY   !!!",fc+1);
    printf("\n\nLOCATION----> %s",arr[i].loc);
    printf("\nID----> %d",arr[i].id);
    printf("\nPRICE----> %d",arr[i].price);
    printf("\nAREA(acre's)----> %d",arr[i].area);
    printf("\nSWIMMING POOL----> %s",arr[i].swim);
    printf("\nGARDEN----> %s\n",arr[i].gard);
      fc++;
      hj=1;
     }
     }
     break;
    case 2:
     printf("Enter your budget: ");
     scanf("%d",&budget);
     fflush(stdin);
    printf("\n\n        *********************************");
    printf("\n         !!!!   AVAILABLE PROPERTY   !!!!");
    printf("\n        *********************************\n\n");
     for (int i=0;i<30;i++){
     if (budget==arr[i].price || arr[i].price<budget && arr[i].price!=0){
    printf("\n\n!!!   DETAILS OF %d PROPERTY   !!!",fc+1);
    printf("\n\nLOCATION----> %s",arr[i].loc);
    printf("\nID----> %d",arr[i].id);
    printf("\nPRICE----> %d",arr[i].price);
    printf("\nAREA(acre's)----> %d",arr[i].area);
    printf("\nSWIMMING POOL----> %s",arr[i].swim);
    printf("\nGARDEN----> %s\n",arr[i].gard);
      fc++;
      hj=1;
    }
     }
    break;
    default:
     printf("\n\n!!!   Enter The Valid Option   !!!");
     hj=1;
  }

if (hj==0){
  printf("\n\n          !!!   NOT FOUND   !!!");
}
  
  int u;
  for (u=0;u<30;u++){
    arr[u].id=0;
    arr[u].price=0;
  }

  }



// The function of this module is to edit the property details like location and price

void edit(){

  int sim,x=0;

  ptr = fopen("file1.txt","r");
    if (ptr == NULL){
      printf("FILE CAN'T BE OPEN");
      exit(1);
    }

    rewind(ptr);
    while (feof(ptr)==0){
    fscanf(ptr,"%s%d%d%d%s%s",arr1[x].loc,&arr1[x].id,&arr1[x].price,&arr1[x].area,arr1[x].swim,arr1[x].gard);
    x++;
    }
    fclose(ptr);
    char ch = 'y';
    int i =0;
    int z,price1;
    char ary[20];
    int gj=0;
    while(ch == 'y'){
      printf("Enter the id of property u want to edit: ");
      scanf("%d",&sim);
      fflush(stdin);
      for (int i=0;i<20;i++){
      if (sim == arr1[i].id){
        printf("\n\nPress 1 to change location");
        printf("\nPress 2 to change price");
        printf("\nEnter ur choice: ");
        scanf("%d",&z);
        fflush(stdin);
        switch (z){
          case 1:
          printf("Enter the location: ");
          gets(ary);
          strcpy(arr1[i].loc,ary);
          printf("\n\n!!!  SUCESSFULLY CHANGED  !!!\n\n");
          break;
          case 2:
          printf("Enter the price: ");
          scanf("%d",&price1);
          arr1[i].price = price1;
          printf("\n\n!!!  SUCESSFULLY CHANGED  !!!\n\n");
          break;
          default:
          printf("Enter valid choice");
        }
        gj=1;
      }
    }
        if (gj==0){
      printf("\n\n!!!   NOT FOUND   !!!");
    }
       gj=0;
        fflush(stdin);
        printf("\n\nTO EDIT MORE TYPE (y/n): ");
        scanf("%c",&ch);
        fflush(stdin);
        
    }


    ptr = fopen("file1.txt","w");
    int j=0;
      while (arr1[j].price!=0){
    fprintf(ptr,"%s\n%d\n%d\n%d\n%s\n%s\n\n",arr1[j].loc,arr1[j].id,arr1[j].price,arr1[j].area,arr1[j].swim,arr1[j].gard);
      j++;
    }
     
     fclose(ptr);
     int g;
  for (g=0;g<20;g++){
      arr1[g].id=0;
      arr1[g].price=0;
}
}


// The function of this module is to delete a record of property

void delete(){

  int sim,x=0;

  ptr = fopen("file1.txt","r");
    if (ptr == NULL){
      printf("FILE CAN'T BE OPEN");
      exit(1);
    }
    rewind(ptr);
    while (feof(ptr)==0){
    fscanf(ptr,"%s%d%d%d%s%s",arr2[x].loc,&arr2[x].id,&arr2[x].price,&arr2[x].area,arr2[x].swim,arr2[x].gard);
    x++;
    }
    fclose(ptr);
    char ch = 'y';
    int i =0;
    char ary[20];
    int k=0;
    while(ch == 'y'){
      printf("Enter the id of property u want to delete: ");
      scanf("%d",&sim);
      fflush(stdin);
      for (int i=0;i<20;i++){
      if (sim == arr2[i].id){
        arr2[i].price = 0;
        arr2[i].id = 0;
        k=1;
        printf("\n\n!!!  SUCESSFULLY DELETED  !!!\n\n");
      }
    }
      if (k==0){
        printf("\n\n!!!   NOT FOUND   !!!");
        break;
      }
        fflush(stdin);
        printf("\nTO DELETE MORE TYPE (y/n): ");
        scanf("%c",&ch);
        fflush(stdin);
        k=0;       
    }
    ptr = fopen("file1.txt","w");
      for (int j=0;j<20;j++){
      if (arr2[j].price!=0){
    fprintf(ptr,"%s\n%d\n%d\n%d\n%s\n%s\n\n",arr2[j].loc,arr2[j].id,arr2[j].price,arr2[j].area,arr2[j].swim,arr2[j].gard);
    }
   }
  fclose(ptr);
  int w;
  for (w=0;w<20;w++){
      arr2[w].id=0;
      arr2[w].price=0;
}
}



// The function help's the user to buy any property 

void buy(){
   int x=0,sim,pay,gj=0;
    ptr = fopen("file1.txt","r");
    if (ptr == NULL){
      printf("FILE CAN'T BE OPEN");
      exit(1);
    }

    rewind(ptr);
    while (feof(ptr)==0){
    fscanf(ptr,"%s%d%d%d%s%s",arr3[x].loc,&arr3[x].id,&arr3[x].price,&arr3[x].area,arr3[x].swim,arr3[x].gard);
    x++;
    }
    fclose(ptr);
    ptr = fopen("sold.txt","a");
    printf("Enter the id of the property u wann'a buy: ");
    scanf("%d",&sim);
    fflush(stdin);
    for (int i=0;i<20;i++){
      if (arr3[i].id==sim){
         printf("Price of this property is: %d",arr3[i].price);
         printf("\n\nPay your amount....  ");
         scanf("%d",&pay);
         fflush(stdin);
         if (pay==arr3[i].price){
          printf("\n\n\n!!!   PAYMENT SUCESSFULL   !!!");
          printf("\n  !!!     PURCHASED      !!!");
          fprintf(ptr,"%s\n%d\n%d\n%d\n%s\n%s\n\n",arr3[i].loc,arr3[i].id,arr3[i].price,arr3[i].area,arr3[i].swim,arr3[i].gard);
          arr3[i].id = 0;
          arr3[i].price = 0;

          
         }
         else if(pay > arr3[i].price){
          printf("\n\n!!!   WE ARE NOT CORRUPTED   !!!");
          
         }
         else if (pay < arr3[i].price){
          printf("\n\n!!!   PAYMENT DECLINED   !!!");
          
         }
       gj=1;
      } 
    }
    fclose(ptr);
    
   if (gj==0){
    printf("\n\n!!!   NOT FOUND   !!!");
   }
    ptr = fopen("file1.txt","w");
    int j;
      for (j=0;j<20;j++){
      if (arr3[j].price!=0 || arr3[j].id!=0){
      fprintf(ptr,"%s\n%d\n%d\n%d\n%s\n%s\n\n",arr3[j].loc,arr3[j].id,arr3[j].price,arr3[j].area,arr3[j].swim,arr3[j].gard);
    }
   }
  fclose(ptr);
   int v;
   for (v=0;v<20;v++){
    arr3[v].id=0;
    arr3[v].price=0;
   }

    
}

void full_fledge(){
  ptr = fopen("file1.txt","r");
  if (ptr==NULL){
    printf("File Can't be open");
    exit(1);
  }
  int x=0;
  rewind(ptr);
  while (feof(ptr)==0){
    fscanf(ptr,"%s%d%d%d%s%s",arr3[x].loc,&arr3[x].id,&arr3[x].price,&arr3[x].area,arr3[x].swim,arr3[x].gard);
    x++;
  }
  int budget,aea,fc=0,count=0;
  char swim1[10],gard1[10];
  printf("Enter Your budget: ");
  scanf("%d",&budget);
  fflush(stdin);
  printf("Enter Your Area: ");
  scanf("%d",&aea);
  fflush(stdin);
  printf("Enter (Yes/No) for Swimming Pool: ");
  gets(swim1);
  fflush(stdin);
  printf("Enter (yes/No) for garden: ");
  gets(gard1);
  fflush(stdin);
  printf("\n\n        *********************************");
  printf("\n         !!!!   AVAILABLE PROPERTY   !!!!");
  printf("\n        *********************************\n\n");
  for (int i=0;i<20;i++){
    if (arr3[i].price<=budget && arr3[i].area<=aea && strcmp(swim1,arr3[i].swim)==0 && strcmp(gard1,arr3[i].gard)==0 && arr3[i].price!=0){
    printf("\n\n!!!   DETAILS OF %d PROPERTY   !!!",fc+1);
    printf("\n\nLOCATION----> %s",arr3[i].loc);
    printf("\nID----> %d",arr3[i].id);
    printf("\nPRICE----> %d",arr3[i].price);
    printf("\nAREA(acre's)----> %d",arr3[i].area);
    printf("\nSWIMMING POOL----> %s",arr3[i].swim);
    printf("\nGARDEN----> %s\n",arr3[i].gard);
    fc++;
    count = 1;
    }

  }
  fclose(ptr);
 if (count==0){
  printf("\n           !!!   NOT FOUND   !!!");
 }
 for (int i=0;i<20;i++){
  arr3[i].id=0;
  arr3[i].price=0;
 }

}

// This is the main function by which user can select the option which is given below

int main(){
    int option;
    printf("\n\n        *********************************");
    printf("\n         !!!!   HEY! USER WELCOME   !!!!");
    printf("\n        *********************************");
    back:
    printf("\n\n\nEnter option 1 for adding any property");
    printf("\nEnter option 2 to display the property");
    printf("\nEnter option 3 to display the sold property");
    printf("\nEnter option 4 to search ");
    printf("\nEnter option 5 to edit the property");
    printf("\nEnter option 6 to delete the property");
    printf("\nEnter option 7 to buy a property ");
    printf("\nEnter option 8 for full fledge search");
    printf("\nEnter option 9 to exit the program");
    printf("\n\nEnter your option........  ");
    scanf("%d",&option);
    fflush(stdin);
    printf("\n\n");
    
    switch (option){
        case 1:
         add();
        break;
        case 2:
         display();
        break;
        case 3:
         sold();
        break;
        case 4:
         search();
        break;
        case 5:
         edit();
         break;
        case 6:
         delete();
        break;
        case 7:
         buy();
        break;
        case 8:
         full_fledge();
        break;
        case 9:
         exit(1);
        break;
        default:
         printf("Enter the valid option !!!\n\n");
    }

    goto back;
    return 0;

}
