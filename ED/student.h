#ifndef STUDENT_H
#define STUDENT_H

using namespace std;
static char *argw[2];


class student
  { 
   protected:
    string name;
    string usn;
    string branch;
    int semester;
    int address;
    string buffer;
    string key2;
    string encpt;

   public: 
    void read_data();
    void unpack();
    void write_file();
    int binsearch(std::string);
    string encryptrec(string);
    string decryptrec(string);
    void quicksort(string a[],int,int);
    void indx_lst();
  };

#endif

