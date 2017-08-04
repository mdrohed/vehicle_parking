#include<stdio.h>
#include <string.h>

struct book
{
    char code[20];
    char name[20];
    char date[20];
    char to[20];
    char form[20];
    int cost;
}b;
int seat = 60;
void insert_details ();//for inserting bus details
void viewAll ();//for view all data
void find ();//for finding data
void book_ticket ();//for booking tickets
void old_record ();//for user to find easy
void main()
{
    int a;
    do{
    printf("\n=======================================================================================================================");
    printf("\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Bus Ticket Management System");
    printf("\n");
    printf("\n=======================================================================================================================");

    printf("\n Press<1> Insert bus");
    printf("\n Press<2> View All Bus");
    printf("\n Press<3> Find Bus");
    printf("\n Press<4> Book Ticket");
    printf("\n Press<5> View All Transections");
    printf("\n Press<0> Exit");

    printf("\n\nEnter Your Choice :: ");
    scanf("%d",&a);

    switch (a)
    {
    case 1 :
        insert_details ();
        break;

    case 2 :
       viewAll ();
        break;

    case 3 :
        find ();
        break;

    case 4 :
        book_ticket ();
        break;

    case 5 :
        old_record ();
        break;

    case 0 :
        exit (0);
            break;

    default:
            printf("wrong choice !");
            break;
    }
    }while(a!=0);



}

void insert_details()
{
    FILE *fp;
    struct book b;
    printf("Enter bus code: ");
    scanf("%s",b.code);
    printf("Enter bus name: ");
    scanf("%s",b.name);
    printf("Enter Date: ");
    scanf("%s",b.date);
    printf("Enter Ticket Price: ");
    scanf("%d",&b.cost);
     printf("To: ");
    scanf("%s",b.to);
     printf("Form: ");
    scanf("%s",b.form);

    fp=fopen("data.text","a");
    if(fp==NULL)
    {
        printf("File Not Found");
    }
    else
        {
            fprintf(fp,"\n%s %s %s %s %s %d \n",b.code,b.name,b.date,b.to,b.form,b.cost);
            printf("Record insert Successful");
        }
        printf("\n");
        fclose(fp);
}
void find()
{
    struct book b;
    FILE *fp;
    char st[20];

    char ch[20];
    printf("Enter Bus code :");
    scanf("%s",ch);
    //system("clear");
    fp=fopen("data.text","r+");
     if(fp==NULL)
     {
         printf("File does not found !\n");
         exit(1);
     }
     else
     {
         while(!feof(fp))
         {
             fscanf(fp,"%s %s %s %s %s %d ",b.code,b.name,b.date,b.to,b.form,&b.cost);
             strcpy(st,b.code);
             if(strcmp(st,ch) == 0)
             {
                 //fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);//
                 printf("\n Record Found\n");
                 printf("\n\t\tCode ::%s",b.code);
                 printf("\n\t\tbus name ::%s",b.name);
                 printf("\n\t\tbus date ::%s",b.date);
                 printf("\n\t\tTo ::%s",b.to);
                 printf("\n\t\tForm ::%s",b.form);
                 printf("\n\t\tprice of ticket ::%d",b.cost);
             }
         }

     }
     fclose(fp);

}
void viewAll()
{
    char ch;
    FILE *fp;

    fp=fopen("data.text","r");
     if(fp==NULL)
    {
        printf("File does not found !");
        exit(1);
    }
    else
    {
        //system("clear");
        while( (ch=fgetc(fp) ) !=EOF )
            printf("%c",ch);
    }
     fclose(fp);

}
void book_ticket()
{
    struct book b;
    FILE *fp;

    FILE *ufp;

    int total_seat,mobile,total_amount;
    char name[20];


    char ch; //used display all buses
    char bus_code[20]; //for searching

    //display all buses by default for bus code
        fp=fopen("data.text","r");
     if(fp==NULL)
    {
        printf("File does not found !");
        exit(1);
    }
    else
    {
        //system("clear");
        while( ( ch = fgetc(fp) ) !=EOF )
            printf("%c",ch);
    }
    fclose(fp);

    //display end
    printf("\n For book ticket choice bus(Enter bus Code First Latter)");
    printf("Enter Bus Code :");
    scanf("%s",bus_code);
    //system ("clear");
         fp=fopen("data.text","r");
     if(fp==NULL)
    {
        printf("File does not found !");
        exit(1);
    }
    else
    {
        while(fscanf(fp,"%s %s %s %s %s %d",b.code,b.name,b.date,b.to,b.form,&b.cost)!= EOF)
        {
            if(strcmp(b.code,bus_code) == 0)
            {
                 //printf("%s /%s /%s /%d",b.code,b.name,b.date,b.cost);//
                 printf("\n Record Found\n");
                 printf("\n\t\tCode ::%s",b.code);
                 printf("\n\t\tbus name ::%s",b.name);
                 printf("\n\t\tbus date ::%s",b.date);
                 printf("\n\t\tTo ::%s",b.to);
                 printf("\n\t\tForm ::%s",b.form);
                 printf("\n\t\tprice of ticket ::%d",b.cost);
        }
    }


}
printf("\n your name :");
scanf("%s",name);
printf("\n mobile number :+88");
scanf("%d",&mobile);
printf("\n Total number of tickets :");
scanf("%d",&total_seat);

total_amount= b.cost * total_seat;

printf("\n ENJOY Journey \n");
printf("\n\t\tname : %s",name);
printf("\n\t\tmobile Number : %d",mobile);
printf("\n\t\tbus name : %s",b.name);
printf("\n\t\tTo ::%s",b.to);
printf("\n\t\tForm ::%s",b.form);
printf("\n\t\tTotal seats : %d",total_seat);
printf("\n\t\tcost per tickets : %d",b.cost);
printf("\n\t\tTotal Amount : %d",total_amount);

ufp=fopen("oldTransection.text","a");
if(ufp==NULL)
{
    printf("File not found");
}
else
{
    fprintf(ufp,"%s %d %d %d %s %s %s %d \n",name,mobile,total_seat,total_amount,b.name,b.to,b.form,b.cost);
    printf("\n Record insert successfully to the old record file");
}
printf("\n");
fclose(ufp);
fclose(fp);
}
void old_record()
{
    char ch;
    FILE *fp;
    //system("clear");
    fp=fopen("oldTransection.text","r");
    if(fp==NULL)
    {
        printf("File not found !");
        exit(1);
    }
    else
    {
        //system("clear");
        while( ( ch = fgetc(fp) ) !=EOF )
            printf("%c",ch);
    }
    fclose(fp);


}


