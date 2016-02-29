
//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
using namespace std;
class student
{
string	 usn,name,sem;
public:
	void read();
	void pack();
	void unpack();
};
fstream fp;
void student::read(void)
{
	cout<<"enter the student usn,name,sem"<<endl;
	cin>>usn;
	cin>>name;
	cin>>sem;
}
void student::pack(void)
{
	string buffer;
	buffer=usn+"|"+name+"|"+sem;
	//while(buffer.length()<50)
    //buffer+='*';
	buffer.resize(100,'$');
    fp<<buffer;
}
void student::unpack(void)
{
	string extra;
	fp.open("txt.txt",ios::in);
	getline(fp,usn,'|');
	cout<<usn;
	getline(fp,name,'|');
	cout<<name;
	getline(fp,sem,'|');
	getline(fp,extra);
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
       fp.close();
       break;
case 2:s1.unpack();
       break;
}
}
return 0;
}
