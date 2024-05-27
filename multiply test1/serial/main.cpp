#include<iostream>
#include<conio.h>
#include <unistd.h>
using namespace std;
void generate_random(int [][100],int,int);
void print(int [][100],int,int);
void multi(int[][100],int[][100],int[][100],int,int,int);
int i,j;
main()
{
int a[100][100],b[100][100],c[100][100];
int m=10,n=10,p=10;
//cout<<"matrix A row=";
//cin>>m;
//cout<<"\n"<<"matrix A column=";
//cin>>n;
//cout<<"\n"<<"matrix B column=";
//cin>>p;
generate_random(a,m,n);
cout<<"A:\n";
print(a,m,p);
cout<<"\n\n";

generate_random(b,n,p);
cout<<"B:\n";
print(b,m,p);
cout<<"\n\n";

multi(a,b,c,m,n,p);

cout<<"A*B:\n\n";
print(c,m,p);
return 0;
}

//***********
void generate_random(int a[][100],int m,int n)
{
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
a[i][j] = (rand() % 100 + 1);
}
}//end of for
}//end of read()
//**********
void print(int a[][100],int m,int n)
{
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
cout<<a[i][j]<<"\t";
cout<<"\n";
}
}//end of print()
//**********
void multi(int a[][100],int b[][100],int c[][100],int m,int n,int p)
{
for(i=0;i<m;i++)
{
for(j=0;j<p;j++)
{
c[i][j]=0;
for(int k=0;k<n;k++)
{
c[i][j]+=a[i][k]*b[k][j];
usleep(10);
}
}
}//end of for
}//end of multi()
