

#ifndef FILE1_H
#define FILE1_H

class organismoi 
{
     
             int age;
             int size;
             int grade_vol;
             int pos_trofhs;
             int ID;
     public:
            organismoi(int ,int,int,int );
            organismoi(int,int,int);
            organismoi();
            ~organismoi();
            
            void  setAge(int a);
            virtual void setSize(int);            
            void setGrade_vol(int);
            void setPos_trofhs(int);
            virtual void setID(int);
            void eat(organismoi *ip);
            
            virtual int getID();
            int  getAge()const;
            int  getSize()const;
            int   getGrade_vol()const;
            int getPos_trofhs()const;
            
};
               
//start of plagton(futoplagton,zwoplagton)
class plagton:public organismoi {
     public:
            plagton(int,int,int,int);
            plagton(int,int,int);
            virtual ~plagton();
      };
      
      
class futoplagton:public plagton {
      private:
              static int ID;
      public:
              futoplagton(int,int,int);
              ~futoplagton();
              int getID();
                  void setID();         
      } ;
                           
class zwoplagton:public plagton {
      private:
              static int ID;
      public:
             zwoplagton(int,int,int,int);
             virtual ~zwoplagton();
             int getID();
             void setID();
             };
  //end plagton (futoplagton,zwoplagton)
  
  //start of mi_plagton(aspondila,spondilota)
class mi_plagton:public organismoi
{
         public:
             mi_plagton(int,int,int,int);
             virtual ~mi_plagton();
            // void setSize(int);
            };
 //start of aspondila(kalamari,xtapodi,midi,garida)            
class aspondila:public mi_plagton{
      public:
             aspondila(int,int,int,int);         
             ~aspondila();                   
             };
                               
class kalamari:public aspondila{
           public:
                  kalamari(int,int ,int,int);
                  ~kalamari();
                
                  int getID();
                  void setID();
           private:
                   int size;
                   static int ID;
                   };
                   
     class xtapodi:public aspondila{
         public:
              
              xtapodi(int =0,int =0,int=0,int=0);
              ~xtapodi();
           
              int getID();
              void setID();
         private:     
              static int ID;                                                          
                    };
                    
     class midi:public aspondila{
           public:
                  midi(int,int,int,int);
                  ~midi();
                  int getID();
                  void setID();
           private:
                   static int ID;
                   };
                   
     class garida:public aspondila{
           public:
                  garida(int,int,int,int);
                  ~garida();
                  int getID();
                  void setID();
           private:
                   static int ID;
                   };
       //end aspondila
  
  //start of spondilota(tsipoura,gavros,karxarias,delfini)     
     class spondilota:public mi_plagton{
             public:
                   spondilota(int,int,int,int);
                   ~spondilota();
                   };
                   
       class tsipoura:public spondilota{
             public :
                    tsipoura(int,int,int,int);
                    ~tsipoura();
                    int getID();
                  void setID();
             private:
                     static int ID;
                     };
                     
       class gavros:public spondilota{
             public:
                    gavros(int,int,int,int);
                    ~gavros();
                    int getID();
                  void setID();
             private:      
                     static int ID;
                     };
                     
       class karxarias:public spondilota{
             public:
                    karxarias(int,int,int,int);
                    ~karxarias();           
                    int getID();
                  void setID();
             private:
                     static int ID;
                     };
                     
       class delfini:public spondilota{
             public:
                    delfini(int,int,int,int);
                    ~delfini();
                    int getID();
                    void  setID();
             private:
                      static int ID;
                      };
  

int xtapodi::ID=1;


int kalamari::ID=2;


int midi::ID=3;


int garida:: ID=4;


int tsipoura::ID=5;


int gavros::ID=6;


int karxarias::ID=7;
 

int delfini::ID=8; 
  

int futoplagton ::ID=9;
        
              

  int  zwoplagton::   ID=10;
  #endif   
                          
         
                      
                                                      
                                 
                                             
                               
                                                              
                    
                                                
             
