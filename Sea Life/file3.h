#ifndef FILE3_H
#define FILE3_H

#include "file1.h"
#include "file2.h"


organismoi *org[12][12];
int kill[10]={0};
int day=0;
void thesi(int,int,int ,int );
void anaparagogi(void);
void ti_trwi_ti(int ,int ,int ,int);
void fagwma(void);
void xarths(void);
void kinisi(void);
void molynsh(void);
void fagwma(void);
void topothetisi(int,int,organismoi *);

void stay_alive(void) // CORRECT
{
int i,j;
int ID,size,trof;
cout<<"stay_alive called"<<endl;
for (i=0;i<12;i++)
{
	for (j=0;j<12;j++)
	{
		if (org[i][j]!=NULL)
			{
           // cout<<i<<":"<<j<<endl;
			ID=org[i][j]->getID();
			trof=org[i][j]->getPos_trofhs();
			size=org[i][j]->getSize();
			switch (ID)
			{
			case 1:
			if (size<500 /*|| trof<15*/)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[0]++;
			}
			break;
			
			case 2:
			if (size<300 /*|| trof<10*/ )
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[1]++;
			}
			break;
			
			case 3:
			if (size<50 /*|| trof<5*/)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[2]++;
			}
			case 4:
			if (size<80 /*|| trof<10*/)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[3]++;
			}
			break;
			case 5:
			if (size<800 /*|| trof<350*/)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[4]++;
			}
			break;
			case 6:
			if (size<100 /*|| trof<15*/)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[5]++;
			}
			break;
			case 7:
			if (size<2000 /*||trof<1000*/)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[6]++;
			}
			break;
			case 8:
			if (size<1500 /*|| trof<800*/)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[7]++;
			}
			break;
			case 9:
			if (size<5)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[8]++;
			}
			break;
			case 10:
			if (size<10 || trof<5)
			{
			org[i][j]=NULL;
			delete org[i][j];
			kill[9]++;
			}
			break;
            }//end switch
		}
	}
	
}


cout<<"stay_alive ends"<<endl;	
}//end stay alive

void xarths(void) // CORRECT
{		
cout<<setw(4); 
	 for(int i=0;i<12;i++){
	 cout<<endl;

		 for(int j=0;j<12;j++)
		 {
            if(org[i][j]!=NULL )
			{
				int x = org[i][j]->getID();
				switch(x)
				{
				case 1:
                cout<<"|xtap|";
				break;
				
                case 2:
				cout<<"|kala|";
                break;
                
				case 3:
                     
				cout<<"|midi|";
				break;
				
				case 4:
				cout<<"|gari|";
				break;
				
				case 5:
				cout<<"|tsip|";
				break;
				
				case 6:
				cout<<"|gavr|";
				break;
				
                case 7:
				cout<<"|karx|";
				break;
				  
				case 8:
				cout<<"|delf|";
				break;
				
				case 9:
				cout<<"|fyto|";
				break;
				
                case 10:
				cout<<"|zwo|";
				break;
                                    
				}
        
			}
			else    cout<<"|    |";
					 
		 
		}

	}
	cout<<endl;
}

void kinisi(void) // CORRECT
{
 cout<<"kinisi starts"<<endl;
 bool val1,val2,val;	 
 int count;
 int i2=0;
 int i,j,i1,ar;
 int elx[200][2]={0};
 
for(i=0;i<12;i++)
{	
	
	for (j=0;j<12;j++)
	{
		val1=true;
		for(i1=0;i1<200;i1++)
		{                 
		if (i==elx[i1][0] && j==elx[i1][1]) val1=false;		
		}
		if (val1==true){
        count=0;
		if (org[i][j]!=NULL )
		{
	        if (org[i+1][j]==NULL && i+1<5) count++;
						
			if (org[i-1][j+1]==NULL && i-1>=0 && j+1<5) count++;
		
			if (org[i][j+1]==NULL && j+1<5) count++;
			
			if (org[i+1][j+1]==NULL && i+1<5 && j+1<5) count++;
					
			if (org[i+1][j-1]==NULL && i+1<5 && j-1>=0 ) count++;		
			
			if (org[i][j-1]==NULL && j-1>=0) count++;
			
			if (org[i-1][j-1]==NULL && i-1>=0 && j-1>=0) count++;
          
            if (org[i-1][j]==NULL && i-1>=0) count++;
			
          //  cout<<"count ="<<count<<endl;
			if (count>0)
            {
          //  cout<<"moving "<<i<<","<<j<<":"<<typeid(*org[i][j]).name()<<endl;
			}
		
			
			
            if (count!=0){
			int pos=1+rand()%count;
           // cout<<"pos="<<pos<<endl;
			count=0;
                    
			
			if (org[i-1][j]==NULL && i-1>=0 )
			{//	cout<<"to"<<i-1<<","<<j<<endl;
				count++;
				if(count==pos)
				{org[i-1][j]=org[i][j];
				org[i][j]=NULL;
				delete org[i][j];
			//	cout<<"moved to"<<i-1<<","<<j<<endl;
				}
			}	
			

			if (org[i-1][j+1]==NULL && i-1>=0 && j+1<5)
			{	
              //  cout<<"to"<<i-1<<","<<j+1<<endl;
				count++;
				if(count==pos)
                {org[i-1][j+1]=org[i][j];
                elx[i2][0]=i-1;
				elx[i2][1]=j+1;
				i2++;
                org[i][j]=NULL;
                delete org[i][j];
                /*cout<<"moved to"<<i-1<<","<<j+1<<endl;*/
                }
			}	
			
			if (org[i][j+1]==NULL && j+1<5)
			{	
              //  cout<<"to"<<i<<","<<j+1<<endl;
				count++;
				if(count==pos)
				{org[i][j+1]=org[i][j];
				elx[i2][0]=i;
				elx[i2][1]=j+1;
				i2++;
			//	cout<<"grafetai sto"<<i1<<":"<<i<<"grafetai j"<<j+1<<endl;
				org[i][j]=NULL;
				delete org[i][j];
			/*	cout<<"moved to"<<i<<","<<j+1<<endl;*/}
			}	
						
			if (org[i+1][j+1]==NULL && i+1<5 && j+1<5)
			{	
             //   cout<<"to"<<i+1<<","<<j+1<<endl;
				count++;
				if(count==pos)
                {org[i+1][j+1]=org[i][j];             
                elx[i2][0]=i+1;
				elx[i2][1]=j+1;
				i2++;//cout<<"grafetai sto"<<i1<<":"<<i+1<<"grafetai j"<<j+1<<endl;
                org[i][j]=NULL;
                delete org[i][j];
              /*  cout<<"moved to"<<i+1<<","<<j+1<<endl;*/}
			}	

			if (org[i+1][j]==NULL && i+1<5)
			{	
              //  cout<<"to"<<i+1<<","<<j<<endl;
				count++;
				if(count==pos){
                               org[i+1][j]=org[i][j];
                               elx[i2][0]=i+1;
                               elx[i2][1]=j;
                               i2++;
                               //cout<<"grafetai sto"<<i1<<":"<<i+1<<"grafetai j"<<j<<endl;
                               org[i][j]=NULL;
                               delete org[i][j];
                               //cout<<"moved to"<<i+1<<","<<j<<endl;
                               }
			}	
					
			if (org[i+1][j-1]==NULL && j-1>=0 && i+1<5)
			{	
                //cout<<"to"<<i+1<<","<<j-1<<endl;
				count++;
				if(count==pos){
                               org[i+1][j-1]=org[i][j];
                               elx[i2][0]=i+1;
                               elx[i2][1]=j-1;
                               i2++;
                              // cout<<"grafetai sto"<<i1<<":"<<i+1<<"grafetai j"<<j-1<<endl;
                               org[i][j]=NULL;
                               delete org[i][j];
                            /*   cout<<"moved to"<<i+1<<","<<j-1<<endl;*/}
			}	
		
			if (org[i][j-1]==NULL && j-1>=0)
			{	
                //cout<<"to"<<i<<","<<j-1<<endl;
				count++;
				if(count==pos)
                {org[i][j-1]=org[i][j];
                elx[i2][0]=i;
				elx[i2][1]=j-1;
				i2++;
                org[i][j]=NULL;
                delete org[i][j];
                //cout<<"moved to"<<i<<","<<j-1<<endl;
                }
			}	
			
			if (org[i-1][j-1]==NULL && i-1>=0 && j-1>=0)
			{	
                //cout<<"to"<<i-1<<","<<j<<endl;
				count++;
				if(count==pos)
                {org[i-1][j-1]=org[i][j];
                elx[i2][0]=i-1;
				elx[i2][1]=j-1;
				i2++;
                org[i][j]=NULL;
                delete org[i][j];
                //cout<<"moved to"<<i-1<<","<<j-1<<endl;
                }
			}	
        
        }
			
		}
	}
	}
}	
	cout<<"kinisi ends"<<endl;   
}
//END OF KINISI(VOID)

void fill_array(void)//CORRECT
{
          
srand(time(0));
int i,j,type;
cout<<"random fill of array"<<endl;
for (i=0;i<12;i++)
{
	for (j=0;j<12;j++)
	{	
		

		type=rand()%10;

		if (type==1)
		{
		xtapodi *xtap1=new xtapodi(1+rand()%10,500+int(300*rand()/(RAND_MAX+1.0)),20,0);
		organismoi *ptr=(organismoi*)xtap1;
		org[i][j]=ptr;
		}
		else if(type==2)
		{
		kalamari *kalam1=new kalamari(1+rand()%10,300+int(200*rand()/(RAND_MAX+1.0)),15,0);
		organismoi *ptr=(organismoi*)kalam1;
		org[i][j]=ptr;
		}
		else if(type==3)
		{
		midi *midi1=new midi(1+rand()%5,50+int(30*rand()/(RAND_MAX+1.0)),2,0);
		organismoi *ptr=(organismoi*)midi1;
		org[i][j]=ptr;
		}
		else if(type==4)
		{
		garida *gar1=new garida(1+rand()%10,80+int(20*rand()/(RAND_MAX+1.0)),10,0);
		organismoi *ptr=(organismoi*)gar1;
		org[i][j]=ptr;
		}
		else if(type==5)
		{
		tsipoura *tsip1=new tsipoura(1+rand()%11,800+int(200*rand()/(RAND_MAX+1.0)),150,0);
		organismoi *ptr=(organismoi*)tsip1;
		org[i][j]=ptr;
		}
		else if(type==6)
		{
		gavros *gavr1=new gavros(1+rand()%6,100+int(50*rand()/(RAND_MAX+1.0)),8,0);
		organismoi *ptr=(organismoi*)gavr1;
		org[i][j]=ptr;
		}
		else if(type==7)
		{
		karxarias *karx1=new karxarias(1+rand()%15,2000+int(1000*rand()/(RAND_MAX+1.0)),50,0);
		organismoi *ptr=(organismoi*)karx1;
		org[i][j]=ptr;
		}
		else if(type==8)
		{
		delfini *delf1=new delfini(1+rand()%15,1500+int(500*rand()/(RAND_MAX+1.0)),40,0);
		organismoi *ptr=(organismoi*)delf1;
		org[i][j]=ptr;
		}
		else if(type==9)
		{
		futoplagton *futo1=new futoplagton(1+rand()%5,5+int(15*rand()/(RAND_MAX+1.0)),0);
		organismoi *ptr=(organismoi*)futo1;
		org[i][j]=ptr;
		}
		else if(type==10)
		{
		zwoplagton *zwo1=new zwoplagton(1+rand()%7,10+int(20*rand()/(RAND_MAX+1.0)),3,0);
		organismoi *ptr=(organismoi*)zwo1;
		org[i][j]=ptr;
		}


	}
}	
		
		cout<<"fill_array ends"<<endl;
}


void print_array() // CORRECT
{
cout<<"Present state:"<<endl;
int i;
int j;
       for(i=0;i<12;i++)
       {
                         for(j=0;j<12;j++)
                         {
                                           if (org[i][j]!=NULL)  
                                           {
                                                                 cout<<"position:"<<i<<","<<j<<" exists: ";
                                                                 cout<<typeid(*org[i][j]).name()<<" with ID:"<<org[i][j]->getID()<<endl;     //cout<<org[i][j]->getSize()<<endl;
                                                                 
                                                                 
                                           }
                                                                 
                                                           
                         }
                                          
       }
}





int top[300][2]={0};////////////////////////////////////////////////////////////////////////////////
int pt=0;

void anaparagogi(void)
{
int j,i,i1;
bool val;
for (i=0;i<12;i++)
{
	for(j=0;j<12;j++)
	{
		val=true;
		for (i1=0;i1<300;i1++)
			if (i==top[i1][0] && j==top[i1][1]) val=false;
			
	/*if (val==true)            cout<<"true"<<endl;
	else cout<<"false"<<endl;*/
		if (org[i][j]!=NULL && val==true)
		{
			if (i+1<5 && j-1>=0)	thesi(i+1,j-1,i,j);
			if (j-1>=0)				thesi(i,j-1,i,j);
			if (i-1>=0 && j-1>=0) 	thesi(i-1,j-1,i,j);
			if (i-1>=0)				thesi(i-1,j,i,j);
			if (i-1>=0 && j+1<5)	thesi(i-1,j+1,i,j);      
			if (j+1<5)				thesi(i,j+1,i,j);          
			if (j+1<5 && i+1<5)		thesi(i+1,j+1,i,j);     
			if (i+1<5)				thesi(i+1,j,i,j);           
		}
	}	
}
//for (i1=0;i1<25;i1++) cout<<top[i1][0]<<" : "<<top[i1][1]<<endl;
}



void thesi(int ni,int nj,int i,int j)
{		 
    organismoi *org1;
	int i1;
	bool val=true;
	for (i1=0;i1<25;i1++)
		if (ni==top[i1][0] && nj==top[i1][1]) 
			val=false;	
	if (org[ni][nj]!=NULL && val==true)
		{
            
		if(org[i][j]->getID()==org[ni][nj]->getID())
		{
            top[pt][0]=i;
            top[pt][1]=j;
            pt++;
             top[pt][0]=ni;
            top[pt][1]=nj;
            pt++;                                       
			if (org[i][j]->getID()==1)
				{
				//cout<<"genithike xtapodi sti thesi"<<i<<j<<endl;
				xtapodi *xtap1=new xtapodi(1,500+int(300*rand()/(RAND_MAX+1.0)),20,0);
				organismoi *org1=(organismoi*)xtap1;
				topothetisi(i,j,org1);
				}
		
				else if (org[i][j]->getID()==2)
				{
			//	cout<<"genithike kalamari"<<i<<j<<endl;
				kalamari *kalam1=new kalamari(1,300+int(200*rand()/(RAND_MAX+1.0)),15,0);
				organismoi *org1=(organismoi*)kalam1;
				topothetisi(i,j,org1);
				}
				
				else if (org[i][j]->getID()==3)
				{
			//	cout<<"genithike midi"<<i<<j<<endl;
				midi *midi1=new midi(1,50+int(30*rand()/(RAND_MAX+1.0)),2,0);
				organismoi *org1=(organismoi*)midi1;
				topothetisi(i,j,org1);
				}
	
				else if (org[i][j]->getID()==4)
				{
			//	cout<<"genithike garida"<<i<<j<<endl;
				garida *gar1=new garida(1,80+int(20*rand()/(RAND_MAX+1.0)),10,0);
				organismoi *org1=(organismoi*)gar1;
				topothetisi(i,j,org1);
				}
				
				else if (org[i][j]->getID()==5)
				{
			//	cout<<"genithike tsipoura"<<i<<j<<endl;
				tsipoura *tsip1=new tsipoura(1,800+int(200*rand()/(RAND_MAX+1.0)),150,0);
				organismoi *org1=(organismoi*)tsip1;
				topothetisi(i,j,org1);
				}
				
				else if(org[i][j]->getID()==6)
				{
			//	cout<<"genithike gavros"<<i<<j<<endl;
				gavros *gavr1=new gavros(1,100+int(50*rand()/(RAND_MAX+1.0)),8,0);
				organismoi *org1=(organismoi*)gavr1;
				topothetisi(i,j,org1);
				}
				
				else if (org[i][j]->getID()==7)
				{
			//	cout<<"genithike karxarias"<<i<<j<<endl;
				karxarias *karx1=new karxarias(1,2000+int(1000*rand()/(RAND_MAX+1.0)),50,0);
				organismoi *org1=(organismoi*)karx1;
				topothetisi(i,j,org1);
				}
				
				else if (org[i][j]->getID()==8)
				{
			//	cout<<"genithike delfini"<<i<<j<<endl;
				delfini *delf1=new delfini(1,1500+int(500*rand()/(RAND_MAX+1.0)),40,0);
				organismoi *org1=(organismoi*)delf1;
				topothetisi(i,j,org1);
				}
				
				else if (org[i][j]->getID()==9)
				{
			//	cout<<"genithike futo"<<i<<j<<endl;
				futoplagton *futo1=new futoplagton(1,5+int(15*rand()/(RAND_MAX+1.0)),0);
				organismoi *org1=(organismoi*)futo1;
				topothetisi(i,j,org1);
				}
			
				else if (org[i][j]->getID()==10)
				{
			//	cout<<"genithike zwo"<<i<<j<<endl;
				zwoplagton *zwo1=new zwoplagton(1,10+int(20*rand()/(RAND_MAX+1.0)),30,0);
				organismoi *org1=(organismoi*)zwo1;
				topothetisi(i,j,org1);

				}
            //    cout<<"calling top"<<endl;	
				
		//		cout<<"topothetisi called"<<endl;
		}		
	}

}



void topothetisi(int i,int j,organismoi *org1)
{


if (org[i-1][j+1]==NULL && i-1>=0 && j+1<5) 		
{
   org[i-1][j+1]=org1;
   top[pt][0]=i-1;
   top[pt][1]=j+1;
   pt++;
  // cout<<org[i-1][j+1]->getID();
  // cout<<"place"<<i-1<<":"<<j+1<<endl;
}

else if (org[i][j+1]==NULL && j+1<5) 				
{
    org[i][j+1]=org1;
	top[pt][0]=i;
	top[pt][1]=j+1;
	pt++;
  //   cout<<org[i][j+1]->getID();
  //   cout<<"place"<<i<<":"<<j+1<<endl;
}     
					
else if (org[i+1][j+1]==NULL && i+1<5 && j+1<5) 	
{
    org[i+1][j+1]=org1;
	top[pt][0]=i+1;
	top[pt][1]=j+1;
	pt++;
  //  cout<<org[i+1][j+1]->getID();
  //  cout<<"place"<<i+1<<":"<<j+1<<endl;
}

else if (org[i+1][j-1]==NULL && i+1<5 && j-1>=0) 	
{
     org[i+1][j-1]=org1;
	 top[pt][0]=i+1;
	top[pt][1]=j-1;
	pt++;
  //   cout<<org[i+1][j-1]->getID();
  //   cout<<"place"<<i+1<<":"<<j-1<<endl;
}

else if (org[i][j-1]==NULL && j-1>=0) 				
{
     org[i][j-1]=org1;
	 top[pt][0]=i;
	top[pt][1]=j-1;
	pt++;
   //  cout<<org[i][j-1]->getID();
   //  cout<<"place"<<i<<":"<<j-1<<endl;
}

else if (org[i-1][j-1]==NULL && i-1>=0 && j-1>=0) 	
{
     org[i-1][j-1]=org1;
	 top[pt][0]=i-1;
	top[pt][1]=j-1;
	pt++;
 //    cout<<org[i-1][j-1]->getID();
//	 cout<<"place"<<i-1<<":"<<j-1<<endl;
}     				
else if (org[i-1][j]==NULL && i-1>=0)				
{
     org[i-1][j]=org1;
	 top[pt][0]=i-1;
	top[pt][1]=j;
	pt++;
 //    cout<<org[i-1][j]->getID();
//	 cout<<"place"<<i-1<<":"<<j<<endl;
}				

else if (org[i+1][j]==NULL && i+1<5)				
{
    org[i+1][j]=org1;
	top[pt][0]=i+1;
	top[pt][1]=j;
	pt++;
 //   cout<<org[i+1][j]->getID();
  //  cout<<"place"<<i+1<<":"<<j<<endl;
}
//cout<<"returning"<<endl;
}



void fagwma(void) // CORRECT //
{
int i,j;
bool val;
cout<<"fagwma called"<<endl;
for (i=0;i<12;i++)
{
	for (j=0;j<12;j++)
	{
		val=true;
        if (org[i][j]!=NULL )
        {
        if (org[i+1][j-1]!=NULL&& j-1>=0 &&i+1<5)  
        {
         val=false;                       
        ti_trwi_ti(i+1,j-1,i,j);
      
        }
         if (org[i][j-1]!=NULL&& j-1>=0)                          
         {
           val=false;                                              
         ti_trwi_ti(i,j-1,i,j); 
             
         }
        if (org[i-1][j-1]!=NULL&& i-1>=0 && j-1>=0)                           
        {
          val=false;
          ti_trwi_ti(i-1,j-1,i,j);
          
        }
		if (org[i-1][j]!=NULL&& i-1>=0) 
        {
           val=false;                                  
        ti_trwi_ti(i-1,j,i,j);
        }
		 if (org[i-1][j+1]!=NULL&&i-1>=0)  
         {
             val=false;                  
           ti_trwi_ti(i-1,j+1,i,j);
         }
		 if (org[i][j+1]!=NULL&&j+1<5)
         {
         val=false;
         ti_trwi_ti(i,j+1,i,j);
         }
		  if (org[i+1][j+1]!=NULL &&i+1<5 &&j+1<5)  
          {
          val=false;
          ti_trwi_ti(i+1,j+1,i,j);
          }
		   if (org[i+1][j]!=NULL&&i+1<5)                        
           {
           val=false;
           ti_trwi_ti(i+1,j,i,j);
           }
        
		if (val==true)
		{
		int size1=org[i][j]->getSize();
		size1-=org[i][j]->getPos_trofhs();		
		}
        }
	}
}
cout<<"fagwma ends"<<endl;
}


void ti_trwi_ti(int ni ,int nj,int i, int j) // CORRECT //

{
int ID1,ID2;
//cout<<"ti trwei ti runs"<<endl;
//if (org[i][j]==NULL ||org[ni][nj]==NULL) cout<<"NULL POINTER"<<endl;
ID1=org[i][j]->getID();
//cout<<ID1<<endl;
ID2=org[ni][nj]->getID();
//cout<<ID2<<endl;
//cout<<"ti trwei ti runs"<<endl;
	if (ID1!=ID2)
	{	
		int pi8=1+rand()%10;
	//	cout<<pi8<<endl;
        if (pi8>=5)
		{
		if(ID1==1 || ID1==2 )
		{
		//	if (ID1==1) cout<<"xtapodi trwei "<<endl;
		//	else cout<<"kalamari trwei "<<endl;
			if (ID2==9||ID2==10 ||ID2==4 ||ID2==3)
			{
                           
			if (ID2==9) kill[8]++;
			else if (ID2==10) kill[9]++;
			else if (ID2==4) kill[3]++;
			else if (ID2==3) kill[2]++;
			org[i][j]->eat(org[ni][nj]);
			org[ni][nj]=NULL;
			delete org[ni][nj];
            
            }
		}	
		else if (ID1==3)
		{
	//	cout<<"midi trwei"<<endl;
		if (ID2==9 || ID2==10)
		{
                 
		org[i][j]->eat(org[ni][nj]);
		org[ni][nj]=NULL;
		delete org[ni][nj];
		if (ID2==9) kill[8]++;
		else if (ID2==10) kill[9]++;
        
		}
		}
		else if(ID1==4)
		{
//		cout<<"garida trwei "<<endl;
		if (ID2==9 || ID2==10 || ID2==3)
		{
                  
		org[i][j]->eat(org[ni][nj]);
		org[ni][nj]=NULL;
		delete org[ni][nj];
		if (ID2==9) kill[8]++;
		else if (ID2==10) kill[9]++;
		else if (ID2==3) kill[2]++;
        
        }
		}
		else if(ID1==5)
		{
	//	cout<<"tsipoura trwei"<<endl;
	    
		if (ID2==4 || ID2==6 || ID2==10 ||ID2==9 ||ID2==2)
		{
		org[i][j]->eat(org[ni][nj]);
		org[ni][nj]=NULL;
		delete org[ni][nj];
		if (ID2==9) kill[8]++;
		else if (ID2==10) kill[9]++;
		else if (ID2==2) kill[1]++;
		else if (ID2==4) kill[3]++;
		else if (ID2==6) kill[5]++;
        
        }
		}
		else if(ID1==6)
		{
//		cout<<"gavros trwei"<<endl;
		if (ID2==9 || ID2==10 || ID2==4)
		{
        
		org[i][j]->eat(org[ni][nj]);
		org[ni][nj]=NULL;
		delete org[ni][nj];
		if (ID2==9) kill[8]++;
		else if (ID2==10) kill[9]++;
		else if (ID2==4) kill[3]++;
        
		}
		}
		else if(ID1==7 || ID1==8)
		{
		//if (ID1==7) cout<<"karxarias trwei"<<endl;
	//	else cout<<"delfini trwei"<<endl;
		if (ID2!=7 && ID2!=8)
		{
        
       // cout<<"trwei"<<endl;
		org[i][j]->eat(org[ni][nj]);
		org[ni][nj]=NULL;
		delete org[ni][nj];
		if (ID2==9) kill[8]++;
		else if (ID2==10) kill[9]++;
		else if (ID2==2) kill[1]++;
		else if (ID2==4) kill[3]++;
		else if (ID2==6) kill[5]++;
		else if (ID2==1) kill[0]++;
		else if (ID2==3) kill[2]++;
		else if (ID2==5) kill[4]++;
    
		}
		}
		else if(ID1==10)
		{
		if (ID2==9)
		{
		org[i][j]->eat(org[ni][nj]);
		org[ni][nj]=NULL;
		delete org[ni][nj];
		kill[8]++;
		}
		}
	

	}
}
}


					
void dixtya(void) // CORRECT //
{
	int x1,x2,y1,y2,i,j;
	cout<<"Epilex8hkan dixtya"<<endl;
	cout<<"Eisagete syntetagmenes gia ta dixtya opou x1<x2 kai y1<y2"<<endl;
	cout<<"x1=";
	cin>>x1;
	cout<<"x2=";
	cin>>x2;

	while(x1<0||x1>11 && x2<0||x2>11){cout<<"la8os dwse 8etikh timh >0 kai <12"<<endl; 
		cout<<"x1=";
		cin>>x1;
		cout<<"x2=";
		cin>>x2;}
	cout<<"y1=";
	cin>>y1;
	cout<<"y2=";
	cin>>y2;
	
	while(y1<0||y2>11 && y2<0||y2>11){cout<<"la8os dwse 8etikh timh >0 kai <12"<<endl; 
		cout<<"y1=";
		cin>>y1;
		cout<<"y2=";
		cin>>y2;}
	
	for(i=x1;i<=x2;i++){
		for(j=y1;j<=y2;j++){
			org[i][j]=NULL;
            delete org[i][j];
            }}
}

void molynsh(void)// CORRECT //
{
	int x,y;
	cout<<"Epilex8hke molynsh"<<endl;
	cout<<"Eisagete syntetagmenes gia to shmeio molynshs"<<endl;
	cout<<"x=";
	cin>>x;
	
	while(x<0||x>11){cout<<"la8os dwse 8etikh timh >0 kai <12"<<endl;
		cout<<"x=";
		cin>>x;}
	cout<<"y=";
	cin>>y;	
	
	while(y<0||y>11)
                   {cout<<"la8os dwse 8etikh timh >0 kai <12"<<endl; 
		           cout<<"y=";
		cin>>y;}
	
	org[x][y]=NULL;
	delete org[x][y];
    if(x-1>=0)
    {
    org[x-1][y]=NULL;
	delete org[x-1][y];
    }
    if (x-1>=0 &&y-1>=0)
    {
    org[x-1][y-1]=NULL;
	delete org[x-1][y-1];
    }
    if (x-1>=0 && y+1<5)
    {
    org[x-1][y+1]=NULL;
	delete org[x-1][y+1];
    }
    if (x+1<5)
    {
    org[x+1][y]=NULL;
	delete org[x+1][y];
    }
    if (x+1<5 && y-1>=0)
    {
    org[x+1][y-1]=NULL;
	delete org[x+1][y-1];
    }
    if (x+1<5 && y+1<5)
    {
    org[x+1][y+1]=NULL;
	delete org[x+1][y+1];
    }
    if (y-1>=0)
    {
    org[x][y-1]=NULL;
	delete org[x][y-1];
    }
    if (y+1<5)
    {
    org[x][y+1]=NULL;
    delete org[x][y+1];
    }
    }
	
	
	void epelekse_organismo(void){
      
      int k;
		cout<<"Epelexe eidos organismou:"<<endl;
		cout<<"1)xtapodi"<<endl;
		cout<<"2)kalamari"<<endl;
		cout<<"3)Mydi"<<endl;
		cout<<"4)garida"<<endl;
		cout<<"5)tsipoura"<<endl;
		cout<<"6)gavros"<<endl;
		cout<<"7)karxarias"<<endl;
		cout<<"8)delfini"<<endl;
		cout<<"9)futoplagton"<<endl;
		cout<<"10)zwoplagton"<<endl;
		
		cin>>k;
		int i,j;
		cout<<"Dwse syntetagmenes:"<<endl;
		cout<<"i=";
		cin>>i;
		while(i<0||i>11){cout<<"la8os dwse 8etikh timh >0 kai <11"<<endl; cin>>i;}
		cout<<endl;
		cout<<"j=";
		cin>>j;
	while(j<0||j>11){cout<<"la8os dwse 8etikh timh >0 kai <11"<<endl; cin>>j;}
		
		while(org[i][j]!=NULL){cout<<"la8os suntetagmenes "<<endl;
		cout<<"la8os dwse allh timh gia to i"<<endl; cin>>i;
        cout<<"la8os dwse allh timh gia to j"<<endl; cin>>j;
        }
	
	
	if (k==1)
		{
		xtapodi *xtap1=new xtapodi(1+rand()%10,500+int(300*rand()/(RAND_MAX+1.0)),20,0);
		organismoi *ptr=(organismoi*)xtap1;
		org[i][j]=ptr;
		}
		else if(k==2)
		{
		kalamari *kalam1=new kalamari(1+rand()%10,300+int(200*rand()/(RAND_MAX+1.0)),15,0);
		organismoi *ptr=(organismoi*)kalam1;
		org[i][j]=ptr;
		}
		else if(k==3)
		{
		midi *midi1=new midi(1+rand()%10,50+int(30*rand()/(RAND_MAX+1.0)),2,0);
		organismoi *ptr=(organismoi*)midi1;
		org[i][j]=ptr;
		}
		else if(k==4)
		{
		garida *gar1=new garida(1+rand()%10,80+int(20*rand()/(RAND_MAX+1.0)),10,0);
		organismoi *ptr=(organismoi*)gar1;
		org[i][j]=ptr;
		}
		else if(k==5)
		{
		tsipoura *tsip1=new tsipoura(1+rand()%10,800+int(200*rand()/(RAND_MAX+1.0)),150,0);
		organismoi *ptr=(organismoi*)tsip1;
		org[i][j]=ptr;
		}
		else if(k==6)
		{
		gavros *gavr1=new gavros(1+rand()%10,100+int(50*rand()/(RAND_MAX+1.0)),8,0);
		organismoi *ptr=(organismoi*)gavr1;
		org[i][j]=ptr;
		}
		else if(k==7)
		{
		karxarias *karx1=new karxarias(1+rand()%10,2000+int(1000*rand()/(RAND_MAX+1.0)),50,0);
		organismoi *ptr=(organismoi*)karx1;
		org[i][j]=ptr;
		}
		else if(k==8)
		{
		delfini *delf1=new delfini(1+rand()%10,1500+int(500*rand()/(RAND_MAX+1.0)),40,0);
		organismoi *ptr=(organismoi*)delf1;
		org[i][j]=ptr;
		}
		else if(k==9)
		{
		futoplagton *futo1=new futoplagton(1+rand()%10,5+int(15*rand()/(RAND_MAX+1.0)),0);
		organismoi *ptr=(organismoi*)futo1;
		org[i][j]=ptr;
		}
		else if(k==10)
		{
		zwoplagton *zwo1=new zwoplagton(1+rand()%10,10+int(20*rand()/(RAND_MAX+1.0)),30,0);
		organismoi *ptr=(organismoi*)zwo1;
		org[i][j]=ptr;
		}
		
}     

void wait ( int seconds )	// CORRECT //
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}


void detail_org(int i,int j) // CORRECT //
{
     int ID=org[i][j]->getID();
     switch (ID)
     {
            case 1:cout<<"xtapodi\n";break;
            case 2:cout<<"kalamari\n";break;
            case 3:cout<<"midi\n";break;
            case 4:cout<<"garida\n";break;
            case 5:cout<<"tsipoura\n";break;
            case 6:cout<<"gavros\n";break;
            case 7:cout<<"karxarias\n";break;
            case 8:cout<<"delfini\n";break;
            case 9:cout<<"futoplagton\n";break;
            case 10:cout<<"zwoplagton\n";break;
     }
     cout<<"age = "<<org[i][j]->getAge();
     cout<<"\nsize = "<<org[i][j]->getSize();
     cout<<"\nvathmos anaptyxhs = "<<org[i][j]->getGrade_vol();
     if (ID!=9)  cout<<"\nposothta trofhs = "<<org[i][j]->getPos_trofhs();
     cout<<endl<<endl;
     wait(7);
     
}            
     
void menu1(void) // CORRECT //
{
cout<<"epelexe:"<<endl;
cout<<"1.START"<<endl;//49
cout<<"2.PAUSE"<<endl;//50
cout<<"3.RESTART"<<endl;//51
cout<<"4.END"<<endl;//52
}
void menu2(void) // CORRECT //
{
cout<<"1.DIXTYA"<<endl;
cout<<"2.MOLYNSH"<<endl;
cout<<"3.XARTHS"<<endl;
cout<<"4.LISTA ORGANISMWN"<<endl;
cout<<"5.RESUME"<<endl;
cout<<"6.PLHROFORIES/ OMADA ORGANISMWN"<<endl;
}

void anaptyxi(void) // CORRECT //
{
int i,j;
int vol,size,nsize;
for(i=0;i<12;i++)
{
	for(j=0;j<12;j++)
	{
		if (org[i][j]!=NULL)
		{
			vol=org[i][j]->getGrade_vol();
			size=org[i][j]->getSize();
			nsize=size+vol;
			org[i][j]->organismoi::setSize(nsize);
			org[i][j]->organismoi::setAge(org[i][j]->getAge()+1);
			
		}
	}
}
}

void statistika(void)
{
int i,j,type;
int count[10]={0};
int mo[10]={0};
int trof[10]={0};
for (i=0;i<12;i++)
{
	for (j=0;j<12;j++)
	{
		if (org[i][j]!=NULL)
		{
		type = org[i][j]->getID();
		if (type==1)
		{
		count[0]++;
		mo[0]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[0]+=org[i][j]->getPos_trofhs();
		}
		else if(type==2)
		{
		count[1]++;
		mo[1]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[1]+=org[i][j]->getPos_trofhs();
		}
		else if(type==3)
		{
		count[2]++;
		mo[2]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[2]+=org[i][j]->getPos_trofhs();
		}
		else if(type==4)
		{
		count[3]++;
		mo[3]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[3]+=org[i][j]->getPos_trofhs();
		}
		else if(type==5)
		{
		count[4]++;
		mo[4]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[4]+=org[i][j]->getPos_trofhs();
		}
		else if(type==6)
		{
		count[5]++;
		mo[5]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[5]+=org[i][j]->getPos_trofhs();
		}
		else if(type==7)
		{
		count[6]++;
		mo[6]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[6]+=org[i][j]->getPos_trofhs();
		}
		else if(type==8)
		{
		count[7]++;
		mo[7]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[7]+=org[i][j]->getPos_trofhs();
		}
		else if(type==9)
		{
		count[8]++;
		mo[8]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[8]+=org[i][j]->getPos_trofhs();
		}
		else if(type==10)
		{
		count[9]++;
		mo[9]+=org[i][j]->getSize( );//na diairesw me count
		if (day%7==0)	trof[9]+=org[i][j]->getPos_trofhs();
		}
		}
	}
}
cout<<"\nMESOS OROS MEGETHWN:"<<endl;
for (i=0;i<10;i++)
{
    if (count[i]!=0)
    {
switch (i)
     {
            case 0:
			
			cout<<"xtapodi: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<" ,  mo katanalwsi = ";
			cout<<trof[i];
			
			}
			cout<<endl;
			break;
            
			case 1:
			cout<<"kalamari: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<",mo katanalwsi = ";
			cout<<trof[i];
			}
			cout<<endl;
			break;
            
			case 2:
			
			cout<<"midi mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<"midi mo katanalwsi = ";
			cout<<trof[i];
			}
			cout<<endl;
			break;
			
            case 3:
			cout<<"garida: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<"garida mo katanalwsi = ";
			cout<<trof[i];
			}
			cout<<endl;
			break;
			
            case 4:
			cout<<"tsipoura: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<",mo katanalwsi = ";
			cout<<trof[i];
			}
			cout<<endl;
			break;
			
            case 5:
			cout<<"gavros: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<", mo katanalwsi = ";
			cout<<trof[i];
			}
			cout<<endl;
			break;
			
            case 6:
			cout<<"karxarias: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<" ,mo katanalwsi = ";
			cout<<trof[i];
			}
			cout<<endl;
			break;
			
            case 7:
			cout<<"delfini: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<",mo katanalwsi = ";
			cout<<trof[i];
			}
			cout<<endl;
			break;
			
            case 8:
			cout<<"futoplagton: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<", mo katanalwsi = ";
			cout<<trof[i];
            }
			cout<<endl;
			break;
            
			case 9:
			cout<<"zwoplagton: mo megethous = ";
			mo[i]/=count[i];
			cout<<mo[i];
			if (day%7==0)
			{
			trof[i]/=count[i];
			cout<<",mo katanalwsi = ";
			cout<<trof[i];
			}
			cout<<endl;
			break;
     }
     }
}
int than=0;
double k;
for(i=0;i<10;i++) than+=kill[i];
cout<<"\nTHANATOI:"<<endl;
for(i=0;i<10;i++)
{

     switch (i)
     {
            case 0:
		 k=static_cast<double>(kill[0])/than;
			cout<<"thanatoi xtapodiwn= "<<k*100<<"%"<<endl;;
			break;
            
			case 1:
			 k=static_cast<double>(kill[1])/than;
			cout<<"thanatoi kalamariwn= "<<k*100<<"%"<<endl;;
			break;
			
            case 2:
		 k=static_cast<double>(kill[2])/than;
			cout<<"thanatoi midiwn= "<<k*100<<"%"<<endl;;
			break;
            case 3:
			 k=static_cast<double>(kill[3])/than;
			cout<<"thanatoi garidwn= "<<k*100<<"%"<<endl;;
			break;
            case 4:
			k=static_cast<double>(kill[4])/than;
			cout<<"thanatoi tsipourwn= "<<k*100<<"%"<<endl;;
			break;
            case 5:
		k=static_cast<double>(kill[5])/than;
			cout<<"thanatoi gavrwn= "<<k*100<<"%"<<endl;;
			break;
            case 6:
			 k=static_cast<double>(kill[6])/than;
			cout<<"thanatoi karxariwn = "<<k*100<<"%"<<endl;;
			break;
            case 7:
			 k=static_cast<double>(kill[7])/than;
			cout<<"thanatoi delfiniwn= "<<k*100<<"%"<<endl;;
			break;
            case 8:
			 k=static_cast<double>(kill[8])/than;
			cout<<"thanatoi futoplagtwn= "<<k*100<<"%"<<endl;;
			break;
            case 9:
		    k=static_cast<double>(kill[9])/than;
			cout<<"thanatoi zwoplagton= "<<k*100<<"%"<<endl;;
			break;
     }
}
cout<<endl;
}

#endif
