#include <stdio.h>
#include "E101.h"
#include <unistd.h>
#include <time.h>

int main()
{
 int err;
 printf("Hello\n");
 err = init(); // initailiser
 int countrun=0;
 int countRow=0;
 int totred=0;  //total redness 
 int totint=0; // total brightness
 int countCol=0;
 float redness=0; // ratio of the redness // declare the redness
 int averageOverTime = 0;
 
 //select_IO(0,0);
	open_screen_stream();
	while (countrun<1000){
    if(countrun % 3== 0){
		if(averageOverTime > 2){ 
	   printf("Ruby is missing \n");
	   break;
         }
		else{
		printf("Ruby is present \n");	
		}
		averageOverTime = 0;
	
		}
	
	take_picture();
	update_screen();
	countRow=0;
	countCol=0;
	totred=0;
	totint=0;
	redness=0; // set the redness
       
		while(countRow<240){	
		
		countCol=0; 
		
			while(countCol<320){ // checking each row
			totred = totred + (int)get_pixel(countRow,countCol,0); //redness
			totint = totint+(int)get_pixel(countRow,countCol,3); // brigthness
			redness = (float)totred/(3.0*(float)totint); // ratio of the redness
			countCol++;
		
			}
		countRow++;
		
		}
		printf( " %d", totred);
		if (totred > 9800000 && totred < 11000000){
		 averageOverTime= averageOverTime-1;
	    }	
		else{
		averageOverTime= averageOverTime +1;	
		}	
			
		
		//printf(" \n");
		//printf("Total red %d\n",totred);
		//printf("Total int %d\n",totint);
		//printf("Redness%f\n",redness);
		sleep1(0,055000);
		countrun++;		
	}
		
	close_screen_stream();
	return 0;	
}

