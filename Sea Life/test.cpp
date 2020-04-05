#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include <new>
#include <conio.h>
using namespace std;
#include "file1.h"
#include "file2.h"
#include "file3.h"
	 	 
int main()
{ 
int ch,ch1,ch2,ch3,ch4,ch5,ch6;
bool val;
menu1();
ch=getch();
if (ch==49)
{
	fill_array();
	xarths();
	cout<<"resuming in ";
		int j=5;
		while (j) 
        {cout<<j<<"s";
        j--;
        wait(1);}
        if (j==0) cout<<endl;
		
	val=true;
}
	while (val)
	{
		day++;
		cout<<"Day "<<day<<endl;
		wait(2);
		kinisi();
		wait(2);
		fagwma();
		wait(2);
		anaparagogi();
	    stay_alive();
	    wait(2);
	    anaptyxi();
	    wait(2);
		menu1();
		//wait(3);
	    //ch1 = 48;
		//if (kbhit())  ch1=getch();
		cin>>ch1;
		if (ch1==2)
		{
             cout<<"\nPAUSE selected"<<endl;       
             menu2();    
 			
			while(true){
            ch2=0;
			ch2=getch();
			if (ch2==49)
			{
			dixtya();
			menu2();
			}
			else if (ch2==50)
			{
			molynsh();
			menu2();
			}
			else if (ch2==51)
			{
			xarths();
			cout<<"please wait"<<endl;
			wait(5);
			menu2();
			}
			else if (ch2==52)
			{
			char ch3,ch4;
			print_array();
			cout<<"please wait"<<endl;
			wait(5);
			cout<<"Thes na eisageis organismo? y(yes)-n(no)"<<endl;
			cin>>ch3;
			if (ch3=='y') epelekse_organismo();
			cout<<"Theleis plhroforia gia organismo?y(yes)-n(no)"<<endl;
			cin>>ch4;
			if (ch4=='y') 
			{
			int x,y;
			cout<<"dwse x,y"<<endl;
			cout<<"x=";
			cin>>x;
			cout<<"\ny=";
			cin>>y;
			detail_org(x,y);
			}
			menu2();
			wait(5);
			}
			else if (ch2==53) break;
			else if(ch2==54) {statistika();menu2();wait(4);}
			}
		}	
		else if (ch1==3)
		{	
		fill_array();
		day=0;
		cout<<"PROGRAM RESTARTING IN 5s"<<endl;
		wait(5);
		}
		else if (ch1==4)
		{
         cout<<"Terminating program"<<endl;
		 wait(5);
         break;
		}
	}
}
			
			



