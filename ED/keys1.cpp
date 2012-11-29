#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;


//void student::quicksort(string a[],int,int);
void student::indx_lst()
 {
   ifstream file1(argw[1]);
   ofstream file2(argw[2]);
   stringstream out;
   string buf,usn1,a[1000],add,buf1;
   int i=0,j=0,l=0,m;

   while(!file1.eof())
     {

       buf.erase();
       usn1.erase();
       out.str("");
       m=file1.tellg();
       out<<m;
       add = out.str();
       getline(file1,buf1);
       buf=decryptrec(buf1);
       i=0;

       while(buf[i]!='|')
	 {
	   usn1+=buf[i++];
         }
	   //cout<<usn1<<endl;

       if(!file1.eof()&&usn1[0]!='*')
	 {
           a[j]=usn1;
           a[j]=a[j]+'|'+add;
           j++;
           //file2<<usn1<<'\n';
         }
   
     }   
   quicksort(a,0,j-1);
   int k=0; 

   while(k<j)
     {
      file2<<a[k]<<endl; 
      k++;
     }

   file1.close();
   file2.close();
  }

void student::quicksort(string a[],int l,int h)
 {
  string temp;
  int i,j,pivot;
  if(l<h)
   {
    pivot= l;
    i= l;
    j= h;
    while(i<j)
     {
      while(a[i].compare(a[pivot])<=0)
       i++;
      while(a[j].compare(a[pivot])>0)
       j--;
      if(i<j)
       {
        temp= a[i];
        a[i]= a[j];
        a[j]= temp;
       }
     }
    temp= a[pivot];
    a[pivot]= a[j];
    a[j]= temp;
    quicksort(a,l,j-1);
    quicksort(a,j+1,h);
   }
 }
