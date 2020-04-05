//simperilipsi header file
#include "first.h"

//Ta size gia tis shared memories
#define SHMSZ 5
#define SHM_SIZE 5
#define SHMSIZE 10
#define SHM_KEY IPC_PRIVATE
    int main( int argc,char *argv[])
    {

	printf("######### WELCOME TO |TOULOUMIS - LEON| PIZZA #########\n");


//Diavasma ths shared memory poy ftiaxtike apo server gia katastash dianomewn
int dian_id,*dian_free;
key_t keydian =7777;//kleidi gia shared memory
 if ((dian_id = shmget(keydian, SHMSIZE, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
   //arxikopoihsh toy *dianfree sth 1h thesi ths shared memory
   dian_free = (int *)shmat( dian_id, NULL, 0 );

//Diavasma ths shared memory poy ftiaxtike apo server gia katastash psistwn
int free_id,*mux_free;
key_t keymux =9876;
 if ((free_id = shmget(keymux, SHMSIZE, 0666)) < 0){
        perror("shmget");
        exit(1);
    }
//arxikopoihsh toy *mux_free sth 1h thesi ths shared memory
   mux_free = (int *)shmat( free_id, NULL, 0 );
  int asd;


/////////////
//Diavasma ths shared memory poy ftiaxtike apo server gia arithmo pelatwn
int shm_id,*cnt;
key_t my_key =1234;
 if ((shm_id = shmget(my_key, SHM_SIZE, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
//arxikopoihsh toy *cnt sth 1h thesi ths shared memory
  cnt = (int *)shmat( shm_id, NULL, 0 );
  
	 printf("PELATES STO SYSTHMA = %d\n",*(cnt+0) );
	printf("PSISTES - DIANOMEIS -> 0:DIATHESIMOS,1:OXI\n");
	 for(asd =0 ;asd<10;asd++){//emfanish katastashs psistwn-dianomewn
        printf("Psistis[%d] =%d , ",asd,*(mux_free+asd));
	printf("Dianomeas[%d] =%d\n",asd,*(dian_free+asd));
}

   
        int s, t, len,connection_established;
        struct sockaddr_un remote;     //dilosi dieuthinsis tou server

        //arxikopoiisi socket discriptor kai elegxos gia tin dimiourgia tou
        if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            exit(1);
        }


        //orismos oikogeneias socket pou xrisimopoieitai gia tin idia mixani
        remote.sun_family = AF_UNIX;
        //antigrafi tis dieuthinsis tou socket sti dieuthinsi tou server
        strcpy(remote.sun_path, SOCK_PATH);
        //kathorismos tou sinolikou mikous deuthinsis
        len = strlen(remote.sun_path) + sizeof(remote.sun_family);
       
        //me tin klisi tou sistimatos connect() sindeetai o client me ton server
        //se anti8eti periptoso ektiponetai minima lathous
		
        connection_established = connect(s, (struct sockaddr *)&remote, len);
        if (connection_established ==-1) {
            perror("connect");
            exit(1);
        }
        else{
		
            printf("Connected.\n");
	    (*(cnt+0)) ++;//ayksisi tou arithmoy pelatwn kata ena

	  
            printf("create new customer\n");
	    char ord[4];//buffer gia apothikeusi eisodo apo xristi 
	    int i,count;//gia for
			if (argc==1)//gia ena orisma eisodoy
			{
			custom c1;//dimiourgeia pelath                 
			for (i=0;i<3;i++ ) c1.order[i]=0;//arxikopoihsh pinaka
							// paraggelia sto 0
			
			make_order(&c1);//klhsh synarthshs gia 
					//dhmioyrgeia paraggelias
			
			//casting toy c1.order apo struct custom sto ord[4]
			ord[0]=(char)c1.order[0];
			ord[1]=(char)c1.order[1];
			ord[2]=(char)c1.order[2];
			ord[3]=(char)c1.distant;
			}
			if (argc > 1)//se periptwsh pollwn orismatwn
    			{
			int y=0;//deixnei thesi ston ord
			for(count =1;count<argc;count++)
			{
			//apothikeusi ston ord[4] ta orismata eisodoy
			if (strcmp(argv[count],"0")==0) ord[y]=0;
			if (strcmp(argv[count],"1")==0) ord[y]=1;
			if (strcmp(argv[count],"2")==0) ord[y]=2;
			if (strcmp(argv[count],"3")==0) ord[y]=3;
			y++;//auksisi kata 1
			}
			
    			}//if argc>1
			
			//grapsimo ston server ths paraggelias me 4 bits
			if (write(s, ord, 4) == -1) {
                perror("write");
                exit(1);
            }

        }
		(*(cnt+0)) --;//meiwsi toy arithmoy pelatwn otan aposyndethei

		close(s);//kleisimo syndesis
		
	}
	
