
//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
string buffer;
fstream fp;
int key;
class student
{
string	 usn,name,branch,sem;
public:
	void read();
	void pack();
	void write();
	void unpack();
};
void student::read(void)
{
	cout<<"enter the student usn,name,sem"<<endl;
	cin>>usn;
	cin>>name;
	cin>>branch;
	cin>>sem;
}
void student::pack(void)
{
	string buffer;
	buffer=usn+"|"+name+"|"+branch+"|"+sem;
	//while(buffer.length()<50)
    //buffer+='*';
	buffer.resize(100,'$');
    fp<<buffer;
}
void student::write(void)
{
	string buffer;
	fstream fp;
	fp.open("txt.txt",ios::out|ios::app);
    fp<<buffer;
	fp.close();
}
int search(string key)
{
 student s1;
 int pos;
 fp.open("txt.txt",ios::in);
 while(!fp.eof())
 {
 getline(fp,buffer);
 pos=fp.tellp();
 s1.unpack();
 }
 if(usn==key)
	 return pos;
 else
	 cout<<"record not found";
}
void student::unpack(void)
{
	int i=0;
	string buffer;
	while(!buffer[i]=='|')
	{
		usn+=buffer[i++];
	}
	i++;
	while(!buffer[i]=='|')
	{
	  name+=buffer[i++];
	}
	i++;
	while(!buffer[i]=='|')
	{
	 branch+=buffer[i++];
	}
	i++;
	while(!buffer[i]=='|')
	{
		sem+=buffer[i++];
	}
	i++;
}
int main()
{
	student s1;
	int ch,i;
	for(i=0;i<=3;i++)
	{
	cout<<"enter your choice"<<endl;
	cin>>ch;
switch(ch)
{
case 1:s1.read();
       fp.open("txt.txt",ios::out);
       if(!fp)
       cout<<"not opened";
       s1.pack();
       s1.write();
       fp.close();
       break;
case 2:cout<<"enter the key to be searched";
       cin>>key;
	   s1.search(key);
       break;
default:exit(0);
}
	}
return 0;
}
