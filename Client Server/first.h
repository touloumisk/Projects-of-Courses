//simperilipsi aparaititon vivliothikon
#include <stdio.h>       //gia eisodo eksodo dedomenon

#include <stdlib.h>      //gia tin sinartisi exit()
#include <errno.h>       //gia tin sta8era EINTR
#include <string.h>      //gia xeirismo string
#include <unistd.h>

#include <sys/types.h>  //vasikoi tipoi dedomenon sistimatos
#include <sys/wait.h>   //gia tin sinartisi waitpid()
#include<sys/ipc.h>	//gia IPC_CREAt
#include<sys/shm.h>	//gia shared memory
#include<sys/sem.h>	//gia semaphore
#include <sys/socket.h> //vasikoi orismoi socket
#include <sys/un.h>

#define PERMS 0666
#define SOCK_PATH "/tmp/echo_socket"    //orismos socket path
#define LISTENQ 1                     //o arithmos ton eiserxomenon sindeseon $

                                       //na mpoun stin oura protou klithei i a$
#define Nmaxpizza 3

//dikoi mas orismoi gia semaphore

void sem_op(int id, int value)//gia prakseis se semaphore
{
 struct sembuf op;
 int v;
 op.sem_num=0;
 op.sem_op=value;
 op.sem_flg=SEM_UNDO;
 if((v=semop(id,&op,1)) < 0)
  printf("\n Error executing semop instruction");
}


void sem_create(int semid, int initval)//gia dimiourgeia semaphore

{
 int semval;
union semun
{
 int val;
 struct semid_ds *buf;
 unsigned short *array;
}s;
s.val=initval;
if((semval=semctl(semid,0,SETVAL,s))<0)
  printf("\n Erroe in executing semctl");
}

void sem_wait(int id)//elatwnei to semaphore kata 1
{
 int value = -1;
 sem_op(id,value);
}
void sem_signal(int id)//auxanei to semaphore kata 1
{
 int value=1;
 sem_op(id,value);
}

//struct gia tous pelates tis pitsaria
typedef struct custom{
        int order[3]; //order[0] #special ,order[1] #margarita, order[2] #pepperoni
        int distant; //distant == 1 einai makrinos ,0 kontinos
        
        }custom;
        


void make_order(custom* c)//gia dhmioyrgeia paraggelias
        {     //ch:eisodo apo xristi type,count: metritis gia arithmo pizzes
              int ch,count;
	      //num:arithmos pizzwn gia kathe eidos,dist->distant
	      int num,dist;
               printf("make order :0-special , 1-margarita , 2-pepperoni,-1 finished:");
               count = 0;//arxikpoihsh count
               scanf("%d",&ch);
	       //eisodos dedomenwn mexris otou o xrhsths na pathsei -1 h
	      //o arithmos pizzawn poy exei paraggilei >3
               while (ch!=-1 && count<Nmaxpizza)
               {
            
               printf("\nhow many ");
               match(ch);//antistixisi eisodoy xrhsth ston typo pizzas
               scanf("%d",&num);//poses pizzes thelei
               //prosthesi toy arithmoy poy thelei sto eidos sto synoliko metriti
               count += num;
               if (count>3)//den mporei na paraggilei alles pizzes
               {           printf("you cannot give again num");
                            do//elegxos eggirotitas otan de mporei na paraggilei alles
                            {          count -=num;
                                        scanf("%d",&num);
                            }while (count+num>3); 
                            count+=num;
                }
                c->order[ch] += num ;//antistoixish sto struct ston pinaka paraggelias
                printf ("count = %d \n",count);
                            printf("OK ! \n");
                            if (count<3) {printf("give type:");
                            scanf("%d",&ch);}
               
               }
		printf("Eiste makria? (0:konta | 1:makria):");
		scanf("%d",&dist);
		do{//elenxos egkirotitas gia lathos arithmo
		if (dist!=0 && dist!=1) 
		{printf("Dwste ksana (0:konta | 1:makria):");
		scanf("%d",&dist);
		}
		}while (dist!=0 && dist!=1);
		
		if (dist == 0) c->distant = 0;//antixisi eisodos xristi sto struct
		else c->distant =1;
        }
        
void match(int s)//antistoixisi akereoy se eidos pizzas
{
     if (s==0) printf ("specials ");//0-special
     if (s==1) printf ("margaritas ");//1-,aragarita
     if (s==2) printf ("pepperonis ");//2-pepperoni
     printf ("would you like:");
     return;
}

