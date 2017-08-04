#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 1000
#define SIZE 100

struct time
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliSecond;
};

typedef struct time Time;


struct information
{
    char name[20];
    char phoneNumber[20];
    char VIN[18];
    char serialnumber[7];
    char type[12];
    int  row;
    int  column;
    Time starttime;
};

typedef struct information Info;

struct Admin
{
    char admin_name[20];
    char password[20];
};

typedef struct Admin section;

section admin;
Info info[MAX];
char disp[SIZE][SIZE];
int total=0;
int totalCar = 0;
int totalBike = 0;
int totalAuto = 0;
int totalOthers = 0;
double entryCost = 0.0;
double cost = 0.0;
double lateCost = 0.0;
int Row;
int Column;
int count = 0;

void create_addmin_sec();
int checking();


void setMaininfo();
void changeMaininfo();

Time getCurrentTime();

void add();
Info createInfo();

void readfile();
void readmainfile();

void verifyvehicletypeinf(char*,int,int);
int verifyvehicletype(char*,int,int);
int verifyVIN(char*,char*);
int VerifyPhoneNumber(char*);

void searchvehicle();
int search(char*, char*);

void genaralDisplay();
void searchdisplay(int,int);
void searchingbydisplay();
int srarcbydisplay(int,int);

void departure();
int departuresearch(char*,char*);
void del(int);

void viewAll();

int getTotal(int);


int main (void)
{
    system("color 1a");
    FILE *f;
    f=fopen("total.txt","r");
    fscanf(f,"%d",&total); //fscanf(fileObject,)




    int i;
    int choice;
    int choice2;
    int choice3;
    int choice4;
    int choice5;
    int T;
    int ck;

    system("cls");
    printf("\n\n\n%30sVEHICLE PARKING MANAGEMENT SYSTEM\n\n"," ");
    for(i=0;i<35;i++)
    {
        if(i==0)
        {
            printf("%30s"," ");
        }
        printf("%c",254);
    }
    int cek;
    cek = checking();
    if(cek==1)
    {
        system("cls");
        printf("\n\n\n");
        printf("%40sVEHICLE PARKING\n"," ");
        printf("%40s===============\n\n\n"," ");
        printf("%30sMain Menu >>>\n\n\n"," ");
        printf("%30s_______________________________\n"," ");
        printf("%30s-------------------------------\n"," ");
        printf("%30s|| [1] Add Vehicle%11s||\n%30s|| [2] Search Vehicle%8s||\n%30s|| [3] Total Vehicle Parked%2s||\n%30s|| [4] View All%14s||\n%30s|| [5] Departure Vehicle%5s||\n%30s|| [6] Set Main info%9s||\n%30s|| [7] Change Admin password%1s||\n%30s|| [0] Exit%18s||\n"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ");
        printf("%30s_______________________________\n\n"," ");
        printf("%30s  Enter Your Choice  :  "," ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            {
                system("cls");
                printf("\n\n%30s Add Vehicle >>>\n\n"," ");
                add();
                printf("\n\n%30sThere %s Total %d vehicle Entered \n\n"," ",total > 1 ? "Are" : "is",total);
                system("pause");
                break;
            }
        }
    }else{
      system("cls");
        printf("\n\n\n%30sPlease enter right password\n\n"," ");
        system("pause");
        return main();
    }
}

int checking()
{
    printf("\n\n\n%30sAdmin Log-in >>>"," ");
    FILE *adm=fopen("admin.txt","r");

    if(adm==NULL)
    {
        return 1; //log in
    }
    char temp[15];
    char temp2[15];
    char temp3[20];
    char temp4[20];
    fscanf(adm,"%s %s",temp3,temp2);
    printf("\n\n\n\n%30sEnter The Admin Name      : "," ");
    scanf("%s",temp4);
    printf("%30sPlease Enter The Password : "," ");
    scanf("%s",temp);

    if(strcmp(temp,temp2)==0 && strcmp(temp4,temp3)==0)
    {
        return 1; //right pass log in
    }
    else
    {
        printf("\n\n\n%40s Wrong Password\a\n\n"," ");
        system("pause");
        return -1;
    }
    fclose(adm);
}

void readmainfile()
{
    FILE *fp = fopen("maininfo.txt","r+");
    fscanf(fp,"%d %d %lf %lf %lf",&Row,&Column,&entryCost,&cost,&lateCost);
                                  //5      6      50.00    40.00   100.00
    fclose(fp);
}

int verifyvehicletype(char *TYPE,int r,int c)
{

    char typecar[4]="car";
    char typebike[5]="bike";
    char typeauto[5]="auto";

    if(r-1>Row || c-1>Column)
    {
        return -1;
    }

    if(strcmp(TYPE,typecar)==0)
    {
        if(disp[r-1][c-1] == 'C'|| disp[r-1][c-1]=='A' || disp[r-1][c-1]=='B'|| disp[r-1][c-1]=='O')
        {
            printf("\n\n%30sNot Empty Try Another Location !\n\n"," ");
            return -1 ;
        }

        else
        {
            disp[r-1][c-1] = 'C';
            totalCar++;
            return 1;
        }
    }

   else if(strcmp(TYPE,typebike)==0)
    {
        if(disp[r-1][c-1] == 'C'|| disp[r-1][c-1]=='A' || disp[r-1][c-1]=='B'|| disp[r-1][c-1]=='O')
        {
            printf("%30sNot Empty Try another Location !\n"," ");
            return -1;
        }

        else
        {
            disp[r-1][c-1] = 'B';
             totalBike++;
             return 1;
        }

    }
   else if(strcmp(TYPE,typeauto)== 0)
    {
       if(disp[r-1][c-1] == 'C'|| disp[r-1][c-1]=='A' || disp[r-1][c-1]=='B'|| disp[r-1][c-1]=='O')
       {
         printf("%30sNot Empty Try another Location !\n"," ");
         return -1;
       }

       else
       {
           disp[r-1][c-1] = 'A';
           totalAuto++;
           return 1;
       }

    }
   else
    {
        if(disp[r-1][c-1] == 'O' || disp[r-1][c-1]== 'A' || disp[r-1][c-1]== 'B' || disp[r-1][c-1]== 'C')
        {
           printf("%30sNot Empty Try another Location !\n"," ");
           return -1;
        }

        else
        {
            disp[r-1][c-1] = 'O';
            totalOthers++;
            return 1;
        }

    }
}

void add()
{
    FILE *f;
    Info data = createInfo();
    info[total] = data;

    if(count==0)
    {
      total++;
    }
    f=fopen("total.txt","w");
    fprintf(f,"%d",total);
    fclose(f);

}

Info createInfo()
{
    FILE *file;
    FILE *fp = fopen("maininfo.txt","r+");
    Time start;
    Info temp;
    char vehicletype[12];
    char vin[18];
    char serial_number[7];
    char pnum[20];
    int rw;
    int cl;
    int check;
    int check2;
    int check3;
    system("cls");
    if(fp==NULL)
    {
        printf("\n\n\n%40sPlease Set Main Info !\n"," ");
        count++;
        return;
    }

    file = fopen("information.txt", "r+");
    printf("\n\n\n\n");
    genaralDisplay();


    printf("%30sENTRY FORM \n\n\n"," ");
    printf("%30sEnter The Owners Name         :  "," ");
    scanf("%s",temp.name);
    do
    {
    printf("%30sEnter The Type of Vehicle     :  "," ");
    scanf("%s",temp.type);
    printf("\n%30sSelect Place  \n"," ");
    printf("%30sEnter the Valid Row Number    :  "," ");
    scanf("%d",&temp.row);
    printf("%30sEnter the Valid Column Number :  "," ");
    scanf("%d",&temp.column);
    rw = temp.row;
    cl = temp.column;
    strcpy(vehicletype,temp.type);
    check3=verifyvehicletype(vehicletype,rw,cl);
    }
    while(check3==-1);

    do
    {
    printf("%30sEnter VIN (17 chra)           :  "," ");
    scanf("%s",temp.VIN);
    printf("%30sEnter Serial Number(6 char)   :  "," ");
    scanf("%s",temp.serialnumber);
    strcpy(vin,temp.VIN);
    strcpy(serial_number,temp.serialnumber);
    //check = verifyVIN(vin,serial_number);
    }
    while(check==-1);

    do
    {
    printf("%30sEnter the Phone Number        :  "," ");
    scanf("%s",temp.phoneNumber);
    strcpy(pnum,temp.phoneNumber);
    //check2=VerifyPhoneNumber(pnum);
    }
    while(check2==-1);
    printf("\n\n");
    system("pause");

    start = getCurrentTime();
    temp.starttime = start;
    system("cls");
    printf("\n\n\n%30sVehicle Information >>>\n\n\n"," ");
    printf("%30s||Date                    : %d/%d/%d\n"," ",temp.starttime.wDay,temp.starttime.wMonth,temp.starttime.wYear);
    printf("%30s||Owners Name             : %s\n"," ",temp.name);
    printf("%30s||VIN                     : %s\n"," ",temp.VIN);
    printf("%30s||Serial Number           : %s\n"," ",temp.serialnumber);
    printf("%30s||Owners Phone Number     : %s\n"," ",temp.phoneNumber);
    printf("%30s||Vehicle Type            : %s\n"," ",temp.type);
    printf("%30s||Place                   : Row(%d) Column(%d)\n"," ",temp.row,temp.column);
    printf("%30s||Arrival Time            : %d-%d-%d\n\n\n"," ",temp.starttime.wHour,temp.starttime.wMinute,temp.starttime.wSecond);

    if(total==0)
    {
        file=fopen("information.txt", "w");
        fprintf(file,"%s %s %s %s %s %d %d %d %d %d %d %d ",temp.name,temp.VIN,temp.serialnumber,temp.phoneNumber,temp.type,temp.row,temp.column,temp.starttime.wDay,temp.starttime.wMonth,temp.starttime.wYear,temp.starttime.wHour,temp.starttime.wMinute);

    }
    else
    {

        file=fopen("information.txt", "a");
        fprintf(file,"%s %s %s %s %s %d %d %d %d %d %d %d ",temp.name,temp.VIN,temp.serialnumber,temp.phoneNumber,temp.type,temp.row,temp.column,temp.starttime.wDay,temp.starttime.wMonth,temp.starttime.wYear,temp.starttime.wHour,temp.starttime.wMinute);

    }
    genaralDisplay();
    fclose(fp);
    fclose(file);
    count=0;
    return temp;
}

void genaralDisplay()
{
       int i,j,r=1,loop;


    printf("\t\t\t");
    for(loop=1;loop<=Column;loop++)
    {
        printf("      %d   ",loop);
    }

    printf("\n");
    printf("\t\t\t");

    for(loop=1;loop<=Column;loop++)
    {
        printf("..........");
    }
    printf("\n\n");
    printf("\t");
    for(i=0;i<Row;i++)
    {
        printf("\t%d |>  ",r);
        r++;
        for(j=0;j<Column;j++)
        {
            if(disp[i][j]=='x')
            {
                printf("   [     ]",disp[i][j]);
            }
            else if(disp[i][j]=='A' || disp[i][j]=='B' || disp[i][j]=='C' || disp[i][j]=='O')
            {
                printf("   [  %c  ]",disp[i][j]);
            }
            else
            {
                printf("   [   %c ]",disp[i][j]);
            }
        }
        printf("\n");
        printf("\t");
    }
    printf("\n\n%30s             DISPLAYING VEHICLE\n\n\n\n"," ");
}
Time getCurrentTime()
{
    Time TM;

    GetSystemTime(&TM);

    TM.wHour = TM.wHour + 6;

    if(TM.wHour>=24)
    {
        TM.wHour = TM.wHour - 24;
        TM.wDay  = TM.wDay + 1;
    }

    return TM;
}
