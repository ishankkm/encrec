#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

/*
  class encdec
   {
      string key2;
      string encpt;

    public:
      string encryptrec(string);
      string decryptrec(string);

   };
*/

string student::encryptrec(string org)
  {
   int i=0,j;
   string tmp;
   ifstream file1("ekey.txt");
   getline(file1,encpt);
   
   while(key2.length()<99)
     key2+=encpt;
   
    tmp.erase();
    while(i<99)
     {
       j=((int)org[i]+(int)key2[i]);

       if((int)key2[i]<95)
        {          
          if(j<127)
           {
             tmp+=(char)j;
           }
          else
           {
             j-=95;
             tmp+=(char)j;
           }
        }
       else
        {
          if(j<222)
           {
             j-=95;
             tmp+=(char)j;
           }
          else
           {
             j-=190;
             tmp+=(char)j;
           }
        }
     i++;

     
     }
     
   file1.close();
   return tmp;

 }

string student::decryptrec(string tmp)
 {
   int i=0,j;
   char tmp1[100];
   string org;//,tmp;
   ifstream file2("ekey.txt");
   //ifstream file3("3.txt");
   getline(file2,encpt);

   while(key2.length()<99)
     key2+=encpt;
  
  /* file3.read(tmp1,99);
   
   while(i<99){
    cout<<tmp1[i]; tmp+=tmp1[i++]; }
   cout<<endl;
   //cout<<tmp<<endl;*/

   //getline(file3,tmp); cout<<tmp<<endl;
   
   org.erase();
   
   i=0;
   while(i<99)
     {
       j=((int)tmp[i]-(int)key2[i]); 

       if((int)key2[i]<95)
        {
         if(((int)key2[i]+32)<=(int)tmp[i] && (int)tmp[i]<127)
          {
            org+=(char)j;
          }
         else
          {
            j+=95;
            org+=(char)j;
          }
        }
       else
        {
          if(((int)key2[i]-63)<=(int)tmp[i] && (int)tmp[i]<127)
           { 
             j+=95;
             org+=(char)j;
           }
          else
           {
             j+=190;
             org+=(char)j;
           }
        }

      i++;

     }
    //cout<<org<<endl;
    return org;
 }


/*
int main()
 {
   encdec ea;
   ofstream f5("3.txt");
   string s1="1MS10IS00009|Name9|ISE|sem-1$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",temp1;

   temp1=ea.encryptrec(s1); //cout<<s1<<endl<<temp1<<endl;

   f5<<temp1;
   f5.close();
   temp1=ea.decryptrec(s1); cout<<temp1<<endl;



   return 0;

 }*/

