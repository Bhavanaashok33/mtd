#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include<string.h>
#include<fstream>
#include<unistd.h>
#include<stdint.h>

using namespace std;
void convertDectoHex(char output[],int ip_addr[]) {       
int i,newArr[6],k,ctr;     
for ( i=0; i<6; i++) {         
newArr[i] = 0;         
switch(output[i]) {             
case 'A': newArr[i]=10;                 
break;             
case 'B': newArr[i]=11;                 
break;             
case 'C': newArr[i]=12;                 
break;             
case 'D': newArr[i]=13;                 
break;             
case 'E': newArr[i]=14;                 
break;             
case 'F': newArr[i]=15;                 
break;             
default: newArr[i] = int(output[i])-48;        
 }    
 } 
int j=3; 
ctr = j;     
for (i=0; i<6; i++) {         
for (k=0; k<4; k++) {             
ip_addr[j] = newArr[i] %2;             
newArr[i] /= 2;             
j--;             
ctr++;         
}         
j=ctr;     
}          
i=0;     
int arr[3];        
char result[6];     
for (k=0;k<3; k++) {         
ctr = 128;         
arr[k] = 0;                
for (int j=0; j<8; j++) {             
arr[k] += ip_addr[i]*ctr;             
ctr /=2;             
i++;       
  }     
}

 char string[15];

//system("ping 10.10.1.1 -c 1");
}

int main(void)
{

uint64_t start_state = 0x000005;
uint64_t lfsr = start_state;
int ip_addr[24];
char output[6];
unsigned long int period=0;
FILE *myfile;
myfile=fopen("cputime_lfsr_update.text", "a");
//clock_t t;
//t=clock();
//double tume_spent;
char buffer[30];



//wall time

//struct timeval tv;
//time_t curtime;
//gettimeofday(&tv,NULL);
//curtime=tv.tv_sec;
//strftime(buffer,30,"%T.",localtime(&curtime));
//printf("%s%ld\n",buffer,tv.tv_usec);


int clockcycle=0;
do{
do{


clock_t t;                                                                                                     
t=clock();
                                         
unsigned lsb = lfsr &1;
lfsr >>=1;

if(lsb==1)
lfsr ^=0xE00040u;
//sprintf(output,"%X",lfsr);

//convertDectoHex(output,ip_addr);
t=clock()-t;                                                                                                     
double time_taken =((double)t)/CLOCKS_PER_SEC;                                                                   
fprintf(myfile,"%f seconds", time_taken);                                                                        
fprintf(myfile,"\n");

++period;
}
while(lfsr !=start_state && period!=1);
printf("period cycle %d : %lu \n",clockcycle+1,period);
period=0;
clockcycle ++;
}
while(clockcycle!=1);

//t=clock()-t;
//double time_taken =((double)t)/CLOCKS_PER_SEC;
//fprintf(myfile,"%f seconds", time_taken);
//fprintf(myfile,"\n");

//char buffer2[230];
//struct timeval tv2;
//time_t curtime2;
//gettimeofday(&tv2,NULL);
//curtime2=tv2.tv_sec;
//strftime(buffer2,30,"%T.",localtime(&curtime2));
//printf("%s%ld seconds\n",buffer2,tv2.tv_usec);

return 0;
}




































