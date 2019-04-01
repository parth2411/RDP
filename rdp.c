#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char input[100];
char prod[100][100];
int pos=-1,l=0,st=-1;
char id;

void A();
void B();
void C();
void D();
void ad();

void ad()
{
	pos++;
}//ad

void A()
{
	if(input[pos]=='a')
	{
	 ad();
	 if(input[pos]=='b')
	 {
	  strcpy(prod[++st],"A->abC");
	  ad();
	  C();
	 }
	 else
	  strcpy(prod[++st],"A->abC - Backtrack");
	 if(input[pos]=='b')
	 {
	  strcpy(prod[++st],"A->aBd");
	  B();
	  ad();
	 }
	 else
	  strcpy(prod[++st],"A->aBd - Backtrack");
	 if(input[pos]=='a')
	 {
	  strcpy(prod[++st],"A->aAD");
	  A();
	  D();
	 }
	 else
	  strcpy(prod[++st],"A->aAD - Backtrack");
	}
}

void B()
{
 int flag=0;
 if(input[pos]=='b' && flag==0)
 {
  flag=1;
  strcpy(prod[++st],"B->bB");
  ad();
  B();
 }
 else
  strcpy(prod[++st],"B->bB - Backtrack");
 
 if(flag==0)
  strcpy(prod[++st],"B->null");
}

void C()
{
 int flag=0;
 if(input[pos]=='d' && flag==0)
  {
   flag=1;
   strcpy(prod[++st],"C->d");
   ad();
  }
  else
   strcpy(prod[++st],"C->d - Backtrack");
  if(flag==0)
   strcpy(prod[++st],"C->null");
}

void D()
{
 int flag=0;
 if(input[pos]=='a' && flag==0)
  {
   flag=1;
   strcpy(prod[++st],"D->a");
   ad();
  }
  else
   strcpy(prod[++st],"D->a - Backtrack");
 if(input[pos]=='b')
  {
   flag=1;
   strcpy(prod[++st],"D->b");
   ad();
  }
  else
   strcpy(prod[++st],"D->b - Backtrack");
  if(flag==0)
   strcpy(prod[++st],"D->null");	
}

void main()
{
 int i=0;
 printf("Write String: ");
 scanf("%s",&input);
 l=strlen(input);
 input[l]='$';
 ad();
 A();

 if(pos==l)
 {
  printf("String Accepted\n");
  for(i=0;i<=st;i++)
   {
     printf("%s\n",prod[i]);
   } 
  }//if
  else
  { 
    printf("String rejected\n");
  }//else
}


