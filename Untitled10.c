#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define CAR 1
#define SCOOTER 2

/* to store vehicle number, and its
   row-col position in an array */
struct vehicle
{
	int num ;
	int row ;
	int col ;
  int type ;
} ;

int parkinfo[4][10] ;  /* a 2-D array to store number of vehicle parked */
int vehcount ;  /* to store total count of vehicles */
int carcount ;	/* stores total count of cars */
int scootercount ;  /* stores total count of scooters */

void display( ) ;
void changecol ( struct vehicle * ) ;
struct vehicle * add ( int, int, int, int ) ;
void del ( struct vehicle * ) ;
void getfreerowcol ( int, int * ) ;
void getrcbyinfo ( int, int, int * ) ;
void show( ) ;

/* decrements the col. number by one
   this fun. is called when the data is
   shifted one place to left */
void changecol ( struct vehicle *v )
{
	v -> col = v -> col - 1 ;
}

/* adds a data of vehicle */
struct vehicle * add ( int t, int num, int row, int col )
{
    struct vehicle *v ;

    v = ( struct vehicle * ) malloc ( sizeof ( struct vehicle ) ) ;

    v -> type = t ;
    v -> row = row ;
    v -> col = col ;

	  if ( t == CAR )
      carcount++ ;
    else
    	scootercount++ ;

    vehcount++ ;
	  parkinfo[row][col] = num ;
}


