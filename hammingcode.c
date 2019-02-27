#include <stdio.h>
#include<conio.h>
int finalresult(int s0,int s1,int s2,int codeword_r[]);
 int main() {

int dataword[4],codeword_s[7],codeword_r[7],i,j,yorn,s0,s1,s2,error_pos; char ch;

up:
printf("Enter the 4 bit dataword\n");
for(i=0;i<4;i++){
 scanf("%d",&dataword[i]);
}
 for(i=0;i<4;i++){
codeword_s[i]=dataword[i];
 }
codeword_s[4]=codeword_s[1]^codeword_s[2]^codeword_s[3]; codeword_s[5]=codeword_s[0]^codeword_s[1]^codeword_s[2]; codeword_s[6]=codeword_s[2]^codeword_s[3]^codeword_s[0]; printf("Codeword is:");
for(i=0;i<7;i++){
 printf("%d",codeword_s[i]);
}
 for(i=0;i<7;i++){
codeword_r[i]=codeword_s[i];
 }
printf("\nAny Error in data Transmission(1 for yes and 0 for no)?:");
 scanf("%d",&yorn);
if(yorn==0){
printf("Received Codeword:");
 for(i=0;i<7;i++){
printf("%d",codeword_r[i]);
 }
s0=codeword_r[1]^codeword_r[2]^codeword_r[3]^codeword_r[6];
s1=codeword_r[0]^codeword_r[1]^codeword_r[2]^codeword_r[5];
s2=codeword_r[2]^codeword_r[3]^codeword_r[0]^codeword_r[4];
printf("\nSyndrome:%d %d %d",s0,s1,s2); 
finalresult(s0,s1,s2,codeword_r);
}
 // End of if
else if(yorn==1){
printf("Error position 1 to 7 (1-b3/2-b2/3-b1/4-b0/5-q2/6-q1/7-q0):");
 scanf("%d",&error_pos);
if(codeword_r[error_pos-1]==0){
codeword_r[error_pos-1]=1;
 }
else{ 
codeword_r[error_pos-1]=0;
}
printf("Received Codeword:"); for(i=0;i<7;i++){
printf("%d",codeword_r[i]); }
s0=codeword_r[1]^codeword_r[2]^codeword_r[3]^codeword_r[6];
s1=codeword_r[0]^codeword_r[1]^codeword_r[2]^codeword_r[5];
s2=codeword_r[2]^codeword_r[3]^codeword_r[0]^codeword_r[4];
printf("\nSyndrome:%d %d %d",s0,s1,s2);
finalresult(s0,s1,s2,codeword_r);
}
printf("\nDo you want to check with different option:");
scanf(" %c",&ch);
if(ch=='y'){
goto up;
}
else{
 goto down;
 }
down:
return 0;
 }
int finalresult(int s0,int s1,int s2,int codeword_r[]){
int i;
int pos[8]={6,5,1,4,3,0,2};
int table2[7][3]={{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
char err[10][6]={"q0","q1","b2","q2","b0","b3","b1"};
if(s0==0 && s1==0 && s2==0){
printf("\nFinal Result: No Error in Data\n"); printf("Final Codeword:");
for(i=0;i<7;i++){
printf("%d",codeword_r[i]);
 }
printf("\nFinal Dataword:");
 for(i=0;i<4;i++){
printf("%d",codeword_r[i]);
 }
goto end;
 }
for(i=0;i<7;i++){
if(table2[i][0]==s0 && table2[i][1]==s1 && table2[i][2]==s2 )
{
 printf("\nFinal Result: Single Bit Error in Data at: %s",err[i]);
if(codeword_r[pos[i]]==0)
{
 codeword_r[pos[i]]=1;
}else{
 codeword_r[pos[i]]=0;
}
printf("\nFinal Codeword:");
for(i=0;i<7;i++){
 printf("%d",codeword_r[i]);
}
printf("\nFinal Dataword:");
for(i=0;i<4;i++){
 printf("%d",codeword_r[i]);
}
 break;
}
 }
end:
 return 0;
 }
