// compile
// gcc -Wall -o "libpass" "libpass.c" 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define your master password before compile */
//char masterpass[6] = "pco22"; 
char pwda[30]="a";
char pwdb[30]="b";
char sha256[80]="000";
char pwd256[80]="000";
char status[80]="none";

struct lp
{
	int ids;
	char service[60];
	char user[60];
	char pass[30]; 
};

void menu( char msg[30]);
int checkpass(char check[30]);
void password(void);

int main( )
{
	FILE *fp;
	struct lp mylib[20]; 
	char ch;
	char ans[2];
	int ca, n;
	char status[30]; 
	char sa[60];
	char sb[60];
	char sc[30];
	 
	fp = NULL;

system("clear");
printf(" \n");	 
printf(" \n Master password: ");
scanf(" %[^\n]%*c", sc);


if (checkpass(sc) == 0) 
 
 {    //compare password

 strcpy(status, "Library is close.");

		       fp = fopen("libpass.dat", "rb");			       	       
			       if (fp == NULL) 
			           {
						printf ( " \n Unable to open the library!");
						printf ( " \n Do you want to create a new library [y or n]? ");
                        scanf(" %[^\n]%*c", ans);
	                    if ((ans[0] == 'y') || (ans[0] == 'Y'))
	                       {
							 fp = fopen("libpass.dat", "wb+");
							  for(n = 0; n < 20; ++n)
							  {
								      strcpy(mylib[n].service, "---");
                                      strcpy(mylib[n].user, "---");
                                      strcpy(mylib[n].pass, "---");
								  mylib[n].ids = n;
						    	 fwrite(&mylib[n], sizeof(struct lp), 1, fp);
						      } 
						   }
					}
					
				  if (fp != NULL) 
				  {     
					        for (n = 0; n < 20; ++n)
                            {
						     fread(&mylib[n], sizeof(struct lp), 1, fp);
                             // printf("\n ID: %d\tService: %s", mylib[n].ids, mylib[n].service);
                            }
						strcpy(status, "Library loaded.");
                  fclose(fp);
			   
	
    
 while (ch != 'q')
	{
	menu(status);
	ch = fgetc(stdin);	 
	printf (" \n");  
	  switch(ch){	
	    				
	      case 'a': 
	      	   fp = fopen("libpass.dat", "wb+");
	                if (fp != NULL){ 
	               system("clear");
                   for(n = 0; n < 20; ++n)
                          printf("\n ID: %d\tService: %s", mylib[n].ids, mylib[n].service);
                    printf (" \n ----------------------------------------------");
	                printf ( " \n Choose a service number [0 - 19]: ");
          		    scanf("%i",&ca);
          		    
          		    if ((ca >= 0) && (ca <= 19))
          		    {
          		     system("clear");
          		        printf (" \n ----------------------------------------------");
						printf (" \n    DEFINE A SERVICE ");
						printf (" \n ----------------------------------------------");
						printf (" \n ");
						printf(" \n    Service....: ");
						scanf(" %[^\n]%*c", sa);
						printf(" \n    User.......: ");
						scanf(" %[^\n]%*c", sb);
						printf(" \n    Password...: ");
						scanf(" %[^\n]%*c", sc);
						
						    strcpy(mylib[ca].service, sa);
                            strcpy(mylib[ca].user, sb);
                            strcpy(mylib[ca].pass, sc);
                            
			                 for(n = 0; n < 20; ++n)
							  {
							    mylib[n].ids = n;
						       fwrite(&mylib[n], sizeof(struct lp), 1, fp);
						      } 
						fclose(fp);
						strcpy(status, "New service defined.");
					}
				}
			  break;
		
		
		
				
		  case 'd': 
			  password();
			  strcpy(status, "New password defined."); 
			  break;
	     
	     
	     
	      
          case 'l':
                  fp = fopen("libpass.dat", "rb");
                  if (fp != NULL){ 
                  system("clear");
                   for(n = 0; n < 20; ++n){
						   fread(&mylib[n], sizeof(struct lp), 1, fp);
                           printf("\n ID: %d\tService: %s", mylib[n].ids, mylib[n].service);
                       }
                    printf ("\n  ----------------------------------------------");
          		    printf ( "\n  Choose a service number [0 - 19]: ");
          		    scanf("%i",&ca);
                   
                    system("clear");
                   
          		    if ((ca >= 0) && (ca <= 19)){        		        
          		     
          		        printf (" \n ----------------------------------------------");
						printf (" \n    SERVICE INFORMATION ");
						printf (" \n ----------------------------------------------");
						printf (" \n ");
						printf (" \n    ID.........: %d", ca);
						printf (" \n    Service....: %s", mylib[ca].service);
						printf (" \n    User.......: %s", mylib[ca].user);  	
						printf (" \n    Password...: %s", mylib[ca].pass);
						printf (" \n ");
						
				        printf ("\n Do you want to exit [y or n]? ");
          		        scanf(" %[^\n]%*c", ans);
	                    
          		        
          	         	if (ans[0] == 'y' || ans[0] == 'Y'){ 
          	         	fclose(fp); 
          	         	exit(0);
          	         	} 
          	         	else { 
          	         	   fclose(fp); 
          	         	   strcpy(status, "Library loaded.");
          	         	   }
                     }
                 }
            break;
          
				} //switch	
			} //while
			
          } 
	 else { 
		   printf ( " Unable to open the library! \n"); 
		   exit(0);
	    }
  }
 return 0;
}


void menu(char msg[30])
{
system("clear");
printf (" \n ----------------------------------------------");
printf (" \n  P A S S W O R D   L I B R A R Y - 21.02");
printf (" \n  Developed by Paulo C. Ormonde");
printf (" \n ----------------------------------------------");
printf (" \n  Status: %s", msg);
printf (" \n ----------------------------------------------");
printf (" \n ");	       
          printf(" \n    [l] List services");
          printf(" \n    [a] Add a password service");
          printf(" \n    [d] Define a new password");
printf (" \n");
printf (" \n Choose an option or 'q' to exit: ");
}



/*Define new password*/
//----------------------------------------------------------------------
void password(void)
{
	char str[80]="";
    
    strcpy(pwda, "a");
    strcpy(pwdb, "b");
   
   while ( strcmp(pwda, pwdb) != 0)
   {
     system("clear");
        printf (" \n ----------------------------------------------");
		printf (" \n    NEW PASSWORD CONFIGURATION ");
		printf (" \n ----------------------------------------------");
		printf (" \n ");
	    printf (" \n ");
		printf (" \n Type a new password......: ");
		scanf(" %[^\n]%*c", pwda);
		printf (" \n Confirm your password....: ");
		scanf(" %[^\n]%*c", pwdb);
    }

       strcat(str,"echo ");
       strcat(str,pwda);   
       strcat(str, " | sha256sum > lic.sha");  
	   system(str);
}




/*Check the password entry*/
//----------------------------------------------------------------------

int checkpass(char check[30])
{
    FILE *fa;
    FILE *fb;
    
    int result;
    
    char str[80]="";
    
  strcat(str,"echo ");
  strcat(str,check);   
  strcat(str, " | sha256sum > lic.pass");      
  system(str);
 
 
    fa = fopen("lic.sha", "r");
		if (fa == NULL){
		     printf("\n Could not open lic.sha file");
		      password();
			  strcpy(status, "New password defined."); 
		     result = 0;
		   }
		   else {
		     fgets(sha256, 80, fa);
		    fclose(fa);
		   }
		   
       fb = fopen("lic.pass", "r");
		if (fb == NULL){
		     printf("\n Could not open lic.pass file");
		     result = 1;
		   }
		   else {
		     fgets(pwd256, 80, fb);
		    fclose(fb);
		   }
		   
		 if (strcmp(pwd256, sha256) == 0) { result = 0; }
		 
  return result;
}




