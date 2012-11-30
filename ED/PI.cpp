#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include "student.h"
#include "student.cpp"
using namespace std;

class flr:public student//,public encdec
  { 
   public:
    void modify(string);
    int deleter(string);
    void pack();
  };


void flr::pack()
  {
    string temp,sem,temp1;
    stringstream out;
    out<<semester;
    sem = out.str();

    temp.erase();
    
    temp+=usn+'|'+name+'|'+branch+'|'+sem;

    for(;temp.size()<99;)
      temp+='$';

    temp1=encryptrec(temp);

    buffer+=temp1+'\n';
  }

void flr::modify(string key1)
  {
    fstream f4(argw[1]);
    int pos,mf;
    
    if(deleter(key1))
      {
        cout<<"\nWhat to Modify?\n";
        cout<<" 1.USN\n 2.Name\n 3.Branch\n 4.Semester\n Your choice: ";
        cin>>mf;
        
        switch(mf)
	  {
	   case 1: cout<<"USN: ";cin>>usn;break;
	   case 2: cout<<"Name: ";cin>>name;break;
	   case 3: cout<<"Branch : ";cin>>branch;break;
	   case 4: cout<<"Semester: ";cin>>semester;break;
	   default: cout<<"Wrong choice!";
          }
        buffer.erase(); 
        pack();
        write_file(); 
      }
  }


int flr::deleter(string key1)
  {
    fstream f3(argw[1]);
    fstream f4(argw[2]);
    char dm='*';
    int pos=0,flag=0;
    
    pos=binsearch(key1);
    if(pos!=-1)
      {
	
	f3.seekp(pos,ios::beg);
	//f3.put(dm);
	
        usn="*kcvdiji";
        buffer.erase();
        pack();
        f3<<buffer;
        flag=1;
      
    
    /*f4.seekp(++address,ios::beg);
    f4.put(dm);*/
    
    f3.close();
    f4.close();
    indx_lst();
       }
    else {   
       f3.close();
       f4.close(); } 
 

     return pos;
  }


int main(int argc, char *argv[])
  {

    if(argc!=3)
      {
       cout<<"Usage ./a.out <record file> <index file>";
       return 1;
      }
    argw[0]=argv[0];
    argw[1]=argv[1];
    argw[2]=argv[2];

    int ch,num;
    string key;

    flr s1;

    cout<<" Enter 1 to Insert a Record\n Enter 2 to Search a Record\n";
    cout<<" Enter 3 to Delete a Record\n Enter 4 to Modify a Record\nyour choice: ";
    cin>>ch;
    key.erase();
    
    switch(ch)
      {
      case 1: cout<<"How many records to insert? : ";
	      cin>>num;
        
              for(int i=0;i<num;i++)
		{
		  cout<<"Enter data\n";
		  s1.read_data();
         	  s1.pack();
                }
              s1.write_file();
              break;
	      
      case 2: cout<<"Enter the USN to be searched :";
              cin>>key;
	      s1.binsearch(key);
	      break;

      case 3: cout<<"Enter the USN to be deleted :";
	      cin>>key;
	      if(s1.deleter(key))
                cout<<"Record Deleted!!\n";
	      break;

      case 4: cout<<"Enter the USN to be modified :";
	      cin>>key;
              s1.modify(key);
              break;	      
	      
      default: cout<<"\nWrong choice!\n";
      }
    return 0;
  }
