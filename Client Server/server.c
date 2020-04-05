#include "first.h"
#include <time.h>
#include <string.h>
//orismos statherwn apo ekgwnisi
const int tmarg = 10; 		// t margarita
const int tpep = 12;		// t pepporini
const int  tspec = 15;		// t special
const int tmakr = 10;		// t dianomis makria
const int tkont = 5;		// t dianomis konta
const int Npsist= 10;		// arithmos psistwn
const int Ndian = 10;		// arithmos dianomewn
const int tverylong = 1; 	// t very long

int mutex[10];			//semaphores gia psistwn
int muxdian[10];		//semaphores gia dianomeis

void sig_chld( int signo );    //synarthsh gia eksafanisi fantasmatvn paidiwn
void psisimo(int,int);	//synarthsh gia psisimo paraggelias
void dianomi(int,int);  //synarthsh gia dianomi paraggelias
void kill_server();     //synarthsh gia xeirismo shmatwn SIGINT

#define SHM_SIZE 5
#define SHMSIZE 10
#define SHM_KEY IPC_PRIVATE
int free_id;
int *mux_free;
int *dian_free;

int main(void)
{
int asd;//gia xrhsh sth for
key_t keydian = 7777;//kleidi gia dimiourgeia shared memory

//Dimiourgeia  shared memory gia apothikeusi katastashs dianomewn
int dian_id = shmget(keydian, SHMSIZE, 0600 | IPC_CREAT);
/*έλεγχος για την περίπτωση αποτυχίας δημιουργίας shared memory, και έξοδος*/
        if ( dian_id < 0 ) 
        {
                printf("---> Could not create shared memory!\n");
                exit(1);
        }
	//apothikeusi shared memory sth prwth thesi toy *dian_free
        dian_free = (int *)shmat( dian_id, NULL, 0 );
        
        for(asd=0;asd<10;asd++) *(dian_free +asd) = 0;//arxikopoihsh me 0:oloi eleytheroi

////////////////

key_t keymux = 9876;
//Dimioyrgeia shared memory gia apothikeusi katastashs psistwn
free_id = shmget(keymux, SHMSIZE, 0600 | IPC_CREAT);
/*έλεγχος για την περίπτωση αποτυχίας δημιουργίας shared memory, και έξοδος*/
        if ( free_id < 0 ) 
        {
                printf("---> Could not create shared memory!\n");
                exit(1);
        }
//Apothikeusi ths shared memory sth 1h thesi toy mux_free
        mux_free = (int *)shmat( free_id, NULL, 0 );

	for(asd=0;asd<10;asd++) *(mux_free +asd) = 0;//arxikoihsh 0 oloi eletheuri


int shm_id;
int *cnt;
key_t my_key = 1234;
//Dimiourgeia shared memory gia apothikeusi arithmoy pelatwn
shm_id = shmget(my_key, SHM_SIZE, 0600 | IPC_CREAT);
/*έλεγχος για την περίπτωση αποτυχίας δημιουργίας shared memory, και έξοδος*/
	if ( shm_id < 0 ) 
	{
		printf("---> Could not create shared memory!\n");
		exit(1);
	}
//apothikeusi ths shared memory sth 1h thesi toy *cnt
	cnt = (int *)shmat( shm_id, NULL, 0 );
	*(cnt+0) = 0;


signal( SIGINT, kill_server );


int i=0;
int count = 0;
int pid;

        //dilosi file descriptors pou epistrefontai apo tin klisi 
        //tis sinartisis socket kai accept antistoixa
        int listenfd, connfd;
        //dilosi mikon dieuthinseon tou client kai server antistoixa
        int clilen, len;
        //dilosi metriton gia for loops
        // int counter, k;
        //arxikopoiisi metavliton gia elegxo sinthikon
        //  int  reg_user, correct_user, menu, connected_member_number;
        //dilosei dieuthiseon server kai client antistoixa
        struct sockaddr_un servaddr, cliaddr;
        
	//dilosi buffer opou apothikeuontai xaraktires gia xrisi
        //stis sinartiseis sistimatos read kai write
        char str[4];
        
        //dilosi id diergasias tis child proccess
        
	pid_t childpid;
	//Dimiourgeia semaphore gia kathe psisti
	for(i=0;i<Npsist;i++)///
	{
	if((mutex[i] = semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
	{
	printf("\n can't create mutex semaphore %d",i);
	exit(1);
	}
	sem_create(mutex[i],1);
	
	}
	
	//Dhmioyrgeia semaphore gia kathe dianomea
	for(i=0;i<Ndian;i++)
        {
        if((muxdian[i] = semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
        {
        printf("\n can't create mutex semaphore %d",i);
        exit(1);
        }
        sem_create(muxdian[i],1);

        }

        //eidopoiisi sti diergasia pateras oti i diergasia paidi exei
        //stamatisei i exei kanei exit        
        signal( SIGCHLD, sig_chld );    

        //dimiourgia tou end point tou server
        if ((listenfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            exit(1);
        }

        servaddr.sun_family = AF_UNIX;            //kathorismos tou tipou tou socket se local (Unix Domain)
        strcpy(servaddr.sun_path, SOCK_PATH);     //kathorismos tou onomatos aftou tou socket
        unlink(servaddr.sun_path);                //svisimo opoioudipote proigoumenou socket me to idio filename
        //sinoliko mikos dieuthinseos server
        len = strlen(servaddr.sun_path) + sizeof(servaddr.sun_family);

        //elegxos sindesis socket descriptor me ena local port kai ektiposi
        //minimatos sfalmatos se periptosi sfalmatos
        if (bind(listenfd, (struct sockaddr *)&servaddr, len) == -1) {
            perror("bind");
            exit(1);
        }

        //dimiourgia mias listas aitiseon gia tous clients me mikos LISTENQ
        if (listen(listenfd, LISTENQ) == -1) {
            perror("listen");
            exit(1);
        }
        /*atermonos vrogxos pou periexei ton kodika me ton opoio ginetai i sindesi 
          me ton client kai eksipiretite.*/      
        for(;;) {




            //sfalma kata ti diadikasia anagnosis kai grafeis apo kai ston client
            int done;
            
            //stis sinartiseis sitimatos read kai write
            int str_length;

            printf("Waiting for a connection...\n");
            //kathorismos megethous dieuthinsis tou client
            clilen = sizeof(cliaddr);

            //antigrafi tis epomenis aitisis apo tin oura aitiseon 
            //sti metavliti connfd kai diagrafi tis apo tin oura
            connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen); 
		if (connfd == -1){
                perror("accept");
                exit(1);
            	}
			//Dhmioyrgeia 2 diergasiwn mia gia eksypiretisi
			//kai mia gia kleisimo syndesis
			pid = fork();
			//Child executes here
			if(pid ==0)
			{

  
            		printf("Connected PELATIS:%d--\n",*(cnt+0));
			//close(listenfd);///////
			//megethos minimatos client 
			int str_len = read(connfd, str, 4);
		
			printf("specials %d \n",str[0]);
			printf("margaritas %d \n",str[1]);
			printf("peperonis %d \n",str[2]);
 			printf("apostash %d\n",str[3]);
			char c0 = str[0];//casting specias se char c0
                        char c1 = str[1];//casting margaritas se char c1
                        char c2 = str[2];//casting pepperonis se char c2
                        int val_spec = (int)c0;//poses special se int
                        int val_marg = (int)c1;//poses margaritas se int
                        int val_pep = (int)c2;//poses pepperonis se int
			//Ypologismos synolikou xronoy psisimoy paraggelias
                        int t = tspec*val_spec+tmarg*val_marg+tpep*val_pep;
			
			int status;//gia wait pid
			//dilwseis metavlitwn gia fork mia gia kathe pizza
			pid_t my_f,endID;
			pid_t f0,f03,f031,f02,f01;
			pid_t f1,f13,f131,f12,f11;
			pid_t f2,f23,f231,f22,f21;
			my_f = fork();
			if(my_f==0) 
			{

			//c0 :poses special thelei
			if (c0==1)
			{f01=fork(); 
			if(f01==0){ psisimo (tspec,count); break;}
			}
			else if(c0==2)
			{
			f0=fork();
			if(f0==0) 
			{
			f02 = fork();
			if(f02 ==0){psisimo(tspec,count);break;}
			else {psisimo(tspec,count);break;}
			}
			}//else if c0=2
			else if(c0==3)
			{
			f03=fork();
			if(f03==0) psisimo(tspec,count);
                        else	
				{f031 = fork();
			if (f031==0) psisimo(tspec,count);
			else  psisimo(tspec,count);
				

				}	
			}
			//c1 poses margarites thelei
			if (c1==1){f11=fork(); if(f11==0){ psisimo (tmarg,count);break;}}///
                        else if(c1==2)
                        {
                        f1=fork();
                        if(f1==0) {f12 = fork();if(f12 ==0)psisimo(tmarg,count);
                                                else psisimo(tmarg,count);break;}

                        }
                        else if(c1==3)
                        {
                        f13=fork();
                        if(f13==0) psisimo(tmarg,count);
                        else    
                                {f131 = fork();
                        if (f131==0) psisimo(tmarg,count);
                        else  psisimo(tmarg,count);


                                }       
                        }//c1==3
			//c2:poses pepperonis
 			if (c2==1){f21=fork(); if(f21==0){ psisimo (tpep,count);break;}}///
                        else if(c2==2)
                        {
                        f2=fork();
                        if(f2==0) {f22 = fork();if(f22 ==0)psisimo(tpep,count);
                                                else psisimo(tpep,count);break;}

                        }
                        else if(c2==3)
                        {
                        f23=fork();
                        if(f23==0) psisimo(tpep,count);
                        else    
                                {f231 = fork();
                        if (f231==0) psisimo(tpep,count);
                        else  {psisimo(tpep,count);}


                                }       
                        }//c2==3


			}//BIG FORK
			else{
			//wait pid gia na teleiwsei prwta to psisimo 
			//kai meta ginetai dianomi
			for(i = 0; i < 20; i++) {
           		endID = waitpid(my_f, &status, WNOHANG|WUNTRACED);
           		if (endID == -1) {            /* error calling waitpid       */
             		 perror("waitpid error");
              		exit(EXIT_FAILURE);
           		}//endif
           		else if (endID == 0) sleep(1);


			else break;
			}//endfor

			//Kalesma dianomis me tkont an einai kontinos 
			// h me tmakr an einai makrinos
			if (str[3]== 0) dianomi(tkont,count);
			else dianomi(tmakr,count);
			    }
			}//Parent executes here
			//Kleisimo syndesis kai auksisi toy count
			else {close(connfd);count++;}


}
}
//Kwdikas sig_child
void sig_chld( int signo )
{
       pid_t pid;
       int stat;
       while ( ( pid = waitpid( -1, &stat, WNOHANG ) ) > 0 ) {
              printf( "Child %d terminated.\n", pid );
       }
}

//Kwdikas psisimatos
void psisimo(int t,int count)
{
int i;
int flag = 0;
			printf("PSISIMO PARAGGELIAS \n");
			//Trexoume mia for gia epilogh psisti poy 
			//tha analavei thn pizza
			for(i = 0;i<10;i++)
                        {
			//Elegxos an einai eleutheros
                        if (*(mux_free+i) == 0)
                        {
			flag =1;
                        *(mux_free+i) = 1;//Den einai eleutheros
                        printf("psistis[%d] working\n",i);
			//sem_wait wste kamia allh diergasi na mi 
			//mporei na ton xrisimopoihsei
                        sem_wait(mutex[i]);
                        sleep(t);//oso o xronos psisimatos pizzas
                        sem_signal(mutex[i]);//eleutherwsh semaphore
                        *(mux_free+i) = 0;//ksana einai eleutheros
                        printf("psistis[%d] free\n",i);
			return;
                        }//end if mux_free ==0
			else {
			if (i==9 && flag ==0) 
			{
		//	printf("NO FREE PSISTIS\n");
			sleep(1);
			
			i=0;
			}//end if i=9
                        }//end else
}//endfor

}//end psisimo


void dianomi(int t,int count)
{


int i;
int flag = 0;
 			printf("DIANOMI PARAGGELIAS \n");
			//Trexoume mia for gia peilogh dianomea poy
			//analamvanei thn dianomh
                        for(i = 0;i<10;i++)
                        {
			//An einai eleutheros
                        if (*(dian_free+i) == 0)
                        {
			flag =1 ;
			//Thetoyme 1 ara den einai eleutheros
                        *(dian_free+i) = 1;
                        printf("dianomeas[%d] working\n",i);
			//Kamia allh diergasia na min ton vlepei eleuthero
                        sem_wait(muxdian[i]);
			//Anenergos gia oso diastima diarkei h dianomi
                        sleep(t);
			//Apeleutherosi semaphore
                        sem_signal(muxdian[i]);
			//Eidopoihsh shared memory oti einai eleutheros
                        *(dian_free+i) = 0;
                        printf("dianomeas[%d] free\n",i);
                        return;
                        }
			else {
                        if (i==9 && flag ==0) 
                        {
                  //      printf("NO FREE DIANOMEAS\n");
                        sleep(1);

                        i=0;
                        }//end if i=9
                        }
}




}

void kill_server() /*συνάρτηση εξουδετέρωσης πατέρα*/
{

	
	signal( SIGINT, kill_server );

	shmctl(free_id, IPC_RMID, NULL); /*διαγραφή κοινής μνήμης*/
	printf("** ! ** SERVER PROCESS WAS TERMINATED!\n");

/*εξουδετέρωση διεργασίας*/
	exit(1);
}
