
#include "file1.h"
#ifndef FILE2_H
#define FILE2_H
//class organismoi
organismoi::organismoi(int a,int s,int g,int p)
{
                           setAge(a);
                           setSize(s);
                           setGrade_vol(g);
                           setPos_trofhs(p);
                           void setSize(int);
}

organismoi::organismoi(int a,int s,int g)
{
                           setAge(a);
                           setSize(s);
                           setGrade_vol(g);
} 
organismoi::organismoi(){};                         
                           
organismoi::~organismoi()
{
                        cout<<"deconstructor organismos runs"<<endl;//
}                        


void organismoi::setAge(int a){ age=a;}
void organismoi::setSize(int s){size=s;}
void organismoi::setGrade_vol(int g){ grade_vol=g;}
void organismoi::setPos_trofhs(int p){pos_trofhs=p;}
void organismoi::setID(int i){organismoi:: ID=i;}
//end void set fuctions

int organismoi::getAge()const{return age;}
int organismoi::getSize()const{return size;}
int organismoi::getGrade_vol()const{return grade_vol;}
int organismoi::getPos_trofhs()const{return pos_trofhs;}
int organismoi::getID(){ return ID;}
//end int get fuctions

void organismoi::eat(organismoi *ip)
{
    int x=getSize();
     int y=ip->getSize();
     int new_size=x+y;
     int trof=getPos_trofhs();
     trof+=y;
     setPos_trofhs(trof);
     setSize(new_size);

     organismoi::setSize(new_size); 
     }
//end organismoi

//start plagton
plagton::plagton(int a,int s,int g,int p):organismoi(a,s,g,p){}
plagton::plagton(int a,int s,int g):organismoi(a,s,g){}

plagton::~plagton(){
                    cout<<"deconstractor plagton runs"<<endl;
                    }

futoplagton::futoplagton(int a,int s,int g):plagton(a,s,g){}

futoplagton::~futoplagton() {
                            cout<<"deconstractor futoplagton runs"<<endl;
                            }
                            

void futoplagton::setID()
{
     organismoi::setID(futoplagton::ID);
}     

int futoplagton::getID()
{   
    return futoplagton::ID;
}                                  

zwoplagton::zwoplagton (int a,int s,int g,int p):plagton(a,s,g,p){}

zwoplagton::~zwoplagton(){
                          cout<<"deconstractor zwoplagton runs"<<endl;
                          }

void zwoplagton::setID()
{
     organismoi::setID(zwoplagton::ID);
}     

int zwoplagton::getID()
{   
    return zwoplagton::ID;
}      
//end plagton

//start mi_plagton
mi_plagton::mi_plagton(int a,int s,int g,int p):organismoi(a,s,g,p){  }

mi_plagton::~mi_plagton(){
                          cout<<"deconstractor mi_plagton runs"<<endl;
                          }  
aspondila::aspondila(int a,int s,int g,int p):mi_plagton(a,s,g,p){}

aspondila::~aspondila(){
                        cout<<"destructor aspondila runs"<<endl;
                        }


xtapodi::xtapodi(int a,int s,int g,int p):aspondila(a,s,g,p)
{    
                    
}

xtapodi::~xtapodi() {
                   cout<<"destructor xtapodi runs "<<endl;
                   }
 
                                

void xtapodi::setID()
{
     organismoi::setID(xtapodi::ID);
}     

int xtapodi::getID()
{   
    return xtapodi::ID;
}      

midi::midi(int a,int s,int g,int p):aspondila(a,s,g,p){}

midi::~midi() {
              cout<<"destructor midi runs"<<endl;
              }
   


void midi::setID()
{
     organismoi::setID(midi::ID);
}     

int midi::getID()
{   
    return midi::ID;
}      

garida::garida(int a,int s,int g,int p):aspondila(a,s,g,p){}

garida::~garida() {
              cout<<"destructor garida runs"<<endl;
              }
   
          
void garida::setID()
{
     organismoi::setID(garida::ID);
}     

int garida::getID()
{   
    return garida::ID;
}      


kalamari::kalamari(int a,int s,int g,int p):aspondila(a,s,g,p){}

kalamari::~kalamari() {
         cout<<"destructor kalamari runs"<<endl;
              }


void kalamari::setID()
{
     organismoi::setID(kalamari::ID);
}     

int kalamari::getID()
{   
    return kalamari::ID;
}                  
     
//end aspondila  
               
//start spondilota                  
spondilota::spondilota(int a,int s,int g,int p):mi_plagton(a,s,g,p) {}

spondilota::~spondilota() {
                          
 cout<<"destructor spondilota runs"<<endl;
              }

tsipoura::tsipoura(int a,int s,int g,int p):spondilota(a,s,g,p){}

tsipoura::~tsipoura() {
           cout<<"destructor tsipoura runs"<<endl;
              }   
  
                    
  
void tsipoura::setID()
{
     organismoi::setID(tsipoura::ID);
}     

int tsipoura::getID()
{   
    return tsipoura::ID;
}                           
gavros::gavros(int a,int s,int g,int p):spondilota(a,s,g,p){}

gavros::~gavros() {
                  
 cout<<"destructor gavros runs"<<endl;
              }
      
 
                 

void gavros::setID()
{
     organismoi::setID(gavros::ID);
}     

int gavros::getID()
{   
    return gavros::ID;
}       
                  
karxarias::karxarias(int a,int s,int g,int p):spondilota(a,s,g,p){}
karxarias::~karxarias() {
                        cout<<"destructor karxarias runs"<<endl;
                        }
  
     
           

void karxarias::setID()
{
     organismoi::setID(karxarias::ID);
}     

int karxarias::getID()
{   
    return karxarias::ID;
}      
delfini::delfini(int a,int s,int g,int p):spondilota(a,s,g,p){}

delfini::~delfini() {
cout<<"destructor delfini runs "<<endl;
}

 


void delfini::setID()
{
     organismoi::setID(delfini::ID);
}     

int delfini::getID()
{   
    return delfini::ID;
}               
//end of spondilota
#endif



