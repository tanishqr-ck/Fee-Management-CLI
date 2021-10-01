/*Tanishq Rajput*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
FILE *students;
struct st{
char roll[20];
char name[20];
char program[20];
char branch[20];
long fee_hist;
long rem;
long pay;
};
struct st s;
int ssize=sizeof(s);
long pass=1234;
int main()
{
 printf("USER----------------ADMIN\n\n");
printf("Enter Password\n");
long apss;
scanf("%ld",&apss);
if(apss==pass){
 
students=fopen("students.TXT","rb+");
if(students==NULL)
{
students=fopen("students.TXT","wb+");
if(students==NULL){
printf("CANNOT OPEN FILE");
return 0;}
}
printf("LOGED In SUCCESSFULLY!!\n");
char ch;int control=1;
while(control){
printf("\nChoose an action\n");
printf("a.Add,View,delete,or update a student.\n");
printf("b.Check the fee status of any student.\n");
printf("c.Submit fee of student.\n");
printf("d.Exit.\n");
ch=getche();
switch(ch)
{
case 'a':
{
printf("\nChoose any option.\n");
printf("1.Add a student.\n");
printf("2.View student list.\n");
printf("3.Delete student record.\n");
printf("4.Update student record.\n");
int c;
scanf("%d",&c);
switch(c)
{
case 1:
{
printf("Enter roll no.,name,program name,branch named and payable fees\n");
scanf("%s",s.roll);
scanf("%s",s.name);
scanf("%s",s.program);
scanf("%s",s.branch);
scanf("%ld",&s.pay);
s.fee_hist=0;
s.rem=0;
fseek(students,0,SEEK_END);
fwrite(&s,ssize,1,students);
printf("Record added successsfully!!\n");
break;
}
case 2:
{
 int c=1;
printf("STUDENTS LIST::\n");
rewind(students);
while(fread(&s,ssize,1,students)==1)
{
 printf("*************\n");
 printf("%d:-\n",c);
printf("Roll NO: %s\n",s.roll);
printf("Name: %s\n",s.name);
printf("Program: %s\n",s.program);
printf("Branch: %s\n",s.branch);
printf("Fee Payable: %ld\n",s.pay);
printf("Fee Submitted: %ld\n",s.fee_hist);
printf("Remaining Fee to be paid: %ld\n",s.rem);
c++;
}
break;
}
case 3:
{
printf("Enter roll no.,name\n");
char n[20];int x=0;
char r[20];
scanf("%s%s",r,n);
gets(n);
FILE *ft=fopen("Temp.TXT","wb+");
rewind(students);
while(fread(&s,ssize,1,students)==1)
{
if(strcmp(s.name,n)!=0&&strcmp(s.roll,r)!=0)
fwrite(&s,ssize,1,ft);
else
x=1;
}
if(x==1){
fclose(students);
fclose(ft);
remove("students.TXT");
rename("Temp.TXT","students.TXT");
students=fopen("students.TXT","rb+");
printf("Record deleted successsfully!!");}
else
{
printf("\nRecord does not exist.\n");}
break;
}
case 4:
{
printf("Enter roll no.,name\n");
char n[20];int x=0;
char r[20];
scanf("%s%s",r,n);
rewind(students);
while(fread(&s,ssize,1,students)==1)
{
if(strcmp(s.name,n)==0&&strcmp(s.roll,r)==0)
{x=1;
printf("Enter new details\n");
printf("Enter roll no,name,program,branch,Fee Payable.\n");
scanf("%s",s.roll);
scanf("%s",s.name);
scanf("%s",s.program);
scanf("%s",s.branch);
scanf("%ld",&s.pay);
fseek(students,-ssize,SEEK_CUR);
fwrite(&s,ssize,1,students);
printf("Record updated successsfully!!\n");
break;
}
}
if(x==0)
printf("Record does not exist.\n");
break;
}
default:
printf("Wrong choice!!");
}
break;
}
case 'b':
{
printf("\nEnter roll no.,name to see fee record\n");
char n[20];
char r[20];
scanf("%s%s",r,n);int x=0;
rewind(students);
while(fread(&s,ssize,1,students)==1)
{
if(strcmp(s.name,n)==0&&strcmp(s.roll,r)==0)
{x=1;
 printf("Roll NO: %s\n",s.roll);
printf("Name: %s\n",s.name);
printf("Total Fee Payable: %ld\n",s.pay);
printf("Fee Submitted: %ld\n",s.fee_hist);
printf("Standing amount to be submitted: %ld\n",s.rem);
break;
}
}
if(x==0)
printf("Record does not exist.\n");
break;
}
case 'c':
{int x=0;
printf("\nEnter roll no.,name,fee to deposit\n");
char n[20];
char r[20];
long dep;
scanf("%s%s%ld",&r,n,&dep);
FILE *ft=fopen("Temp.TXT","a+");
rewind(students);
while(fread(&s,ssize,1,students)==1)
{
if(strcmp(s.name,n)!=0&&strcmp(s.roll,r)!=0)
fwrite(&s,ssize,1,ft);
else
{
 x=1;
s.fee_hist=dep;s.rem=s.pay-dep;
fwrite(&s,ssize,1,ft);
}
}
if(x==1){
fclose(students);
fclose(ft);
remove("students.TXT");
rename("Temp.TXT","students.TXT");
students=fopen("students.TXT","a+");
printf("%ld Deposited successfully!!\n",dep);}
else
printf("Record does not exist.\n");
break;
}
case 'd':
{
control=0;
break;
}
default:
printf("Wrong choice!!!\n");
}
if(control==1)
printf("Back to main menu....\n");
}}
else
printf("Wrong Password");
return 0;
}