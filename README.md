Encryption Decryption of Fixed Length Records
======

This repository contains the code for encrypting and decrypting a fixed length record and storing them in files.
Search, deletion and modification operation can also be performed on these records. A primary index is also created with
USN as primary key which can be used to perform binary search. The key used for encryption is stored in another file. 
The key can be of any length.

There are 8 files in this repository.
1. ekey.txt      : stores the key used for encryption
2. enc.cpp       : the functions used for encryption and decryption
3. keys1.cpp     : the functions used for creating and sorting the index file
4. PI.cpp        : the main program and flr class
5. rec_index.txt : the index file
6. records.txt   : the records in encrypted form
7. student.cpp   : the student class
8. student.h     : declaration of the student class

Working:
First the user input is taken such as USN,name,branch and semester. Then a fixed length record is created using the 
feilds. The record is then encrypted and stored in 'records.txt'. Then the index file is updated. To perform the search 
operation the index file 'rec_index.txt' is looked up for the USN. If the record is present an address is returned. From 
the address the corresponding record is taken out which is in encrypted form. Then the record is decrypted and its 
corresponding feilds are extracted. For the deletion operation first the record is searched and if found the record is 
deleted from the 'records.txt' file and the updation is made in the index file. Similarly for updation operation the 
record is first deleted and the updated record is reinserted.