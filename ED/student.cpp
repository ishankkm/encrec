#include<iostream>
#include<fstream>
#include<sstream>
#include "student.h"
#include "keys1.cpp"
#include "enc.cpp"
using namespace std;

void student::read_data()
  {
    cout<<"USN: ";
    cin>>usn; 
    cout<<"Name: ";
    cin>>name;
    cout<<"Branch: ";
    cin>>branch;
    cout<<"Semester: ";
    cin>>semester;
  }

void student::write_file()
  {
    ofstream f4(argw[2],ios::app);
    ofstream file(argw[1],ios::out|ios::app);
    int inspos;
    string inskey;

    inspos=file.tellp();
    
    file<<buffer;

   inskey+=usn+'|';
   f4<<inskey<<inspos;
   f4<<'\n';
    
   
    file.close();
    f4.close();
    indx_lst();           //to create the index file or update
  }

void student::unpack()
  { 
    string sem;
    stringstream s1;
    int ch=1,i=0;

    usn.erase();
    while (buffer[i]!='|')
      usn+=buffer[i++];
    
    name.erase();
    i++;
    while (buffer[i]!='|')
      name+=buffer[i++];
    
    branch.erase();
    i++;
    while (buffer[i]!='|')
      branch+=buffer[i++];
    
    sem.erase();
    i++;
    while (buffer[i]!='$')
      sem+=buffer[i++];
     
    s1<<sem;
    s1>>semester;
  }

int student::binsearch(string key)
{
   ifstream file(argw[2]);
   ifstream f2(argw[1]); 
   int mid,high,low,i,pos,flag=0;
   char sr;
   string addr,buf;
   stringstream s1;
   
   low=file.tellg();
   file.seekg(-2,ios::end); 
   high=file.tellg();
   file.get(sr); 

   while(sr!='\n'){
     --high;
     file.seekg(high,ios::beg);
     file.get(sr);}
        mid=(low+high)/2;
   
   while(low<=high) 
     { 
        buffer.erase();
        file.seekg(mid,ios::beg);

	file.get(sr);

	while(sr!='\n'&& mid>0)
    	 {
      	   file.seekg(--mid);
	   file.get(sr);
        }
        if(mid==0 && file.tellg()==1) 
          file.seekg(ios::beg);
     
   	getline(file,buffer);
        i=0; 
       
        usn.erase();
        while(buffer[i]!='|')
           usn+=buffer[i++];


        cout<<high<<" "<<mid<<" "<<low<<" "<<usn<<endl;

   	if(usn==key){ 
          flag=1;
          break;
	}
   	else if(usn.compare(key)<0)
          {
	    low=mid+1;  
	    file.seekg(low,ios::beg);
	    file.get(sr);  

            while(sr!='\n')
    	     {
      	        file.seekg(++low);
                file.get(sr);
             }
          }
        else if(usn.compare(key)>0)
          {
	    high=mid-1;  
	    file.seekg(high,ios::beg);
	    file.get(sr);
            while(sr!='\n'&& high>0)
    	     {  
      	        file.seekg(--high);
                file.get(sr);
             }
          }    
        mid=(low+high)/2;  
      }


  if(flag)
   {
   addr.erase();
   i=13;
   while(buffer[i]!='\0')
     addr+=buffer[i++]; 

   address=mid;
   //cout<<address;

       s1<<addr;
       s1>>pos; 
       f2.seekg(pos,ios::beg);
       buffer.erase();     
       getline(f2,buf);
       buffer=decryptrec(buf);
       unpack();
    
           cout<<" Key Found!"<<endl;
           cout<<"  USN :"<<usn<<endl;
           cout<<"  Name :"<<name<<endl;
           cout<<"  Branch :"<<branch<<endl;
           cout<<"  Semester: "<<semester<<endl;
           return pos;
	 }
   else{cout<<"Key Not Found!\n";  return -1;}
   
  file.close();
  f2.close();
  
  }

