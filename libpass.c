#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define your master password before compile */
char masterpass[6] = "abc123"; 

struct lp
{
	int ids;
	char service[60];
	char user[60];
	char pass[30]; 
};

void menu( char msg[30]);

int main( )
{
	FILE *fp;
	struct lp mylib[20]; 
	char ch;
	int ca, n;
	char status[30]; 
	char sa[60];
	char sb[60];
	char sc[30];
	 
	 
	 
printf(" \n Master password: ");
scanf(" %[^\n]%*c", sc);

if (strcmp(sc, masterpass) == 0) {
	
	strcpy(status, "Library is close.");
	
    
	while (ch != 'q')
	{
	menu(status);
	ch = fgetc(stdin);	 
	printf (" \n");  
	  switch(ch){		  
		  case 'r': 
		       fp = fopen("libpass.dat", "rb");		       
			       if (fp == NULL) 
			           {
						printf ( " \n Unable to open the library!");
						printf ( " \n Do you want to create a new library [0-yes or 1-no]? ");
	                    scanf("%i",&ca);
	                    if (ca == 0)
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
                              printf("\n ID: %d\tService: %s", mylib[n].ids, mylib[n].service);
                            }
						strcpy(status, "Library was read.");
					}
					else { 
						printf ( " Unable to open the library! \n"); 
						exit(0);
						}
			   break;
					
	      case 'w': 
	                if (fp != NULL){ 
	                fclose(fp); 
	                fp = fopen("libpass.dat", "wb+");
	                printf ( " \n Choose a service number [0 - 19]: ");
          		    scanf("%i",&ca);
          		    if ((ca >= 0) && (ca <= 20))
          		    {
						printf(" \n Service....: ");
						scanf(" %[^\n]%*c", sa);
						printf(" \n User.......: ");
						scanf(" %[^\n]%*c", sb);
						printf(" \n Password...: ");
						scanf(" %[^\n]%*c", sc);
						
						    strcpy(mylib[ca].service, sa);
                            strcpy(mylib[ca].user, sb);
                            strcpy(mylib[ca].pass, sc);
                            
			                 for(n = 0; n < 20; ++n)
							  {
							    mylib[n].ids = n;
						       fwrite(&mylib[n], sizeof(struct lp), 1, fp);
						      } 
						
					}
				}
	      break;
	      
          case 'l':
                  if (fp != NULL){ 
                   for(n = 0; n < 20; ++n)
                       {
						   fread(&mylib[n], sizeof(struct lp), 1, fp);
                           printf("\n ID: %d\tService: %s", mylib[n].ids, mylib[n].service);
                       }
          
          		    printf ( " \n Choose a service number [0 - 19]: ");
          		    scanf("%i",&ca);
          		    if ((ca >= 0) && (ca <= 20))
          		    {
						printf (" \n ");
						printf(" \n ID.........: %d", ca);
						printf(" \n Service....: %s", mylib[ca].service);
						printf(" \n User.......: %s", mylib[ca].user);
						printf(" \n Password...: %s", mylib[ca].pass);
						printf (" \n ");
					}
					 
          		    printf ("\n Do you want to exit [0-yes or 1-no]? ");
          		    scanf("%i",&ca);
          		    if (ca == 0){exit(0);}
                  }
          break;   	            
               }
	}
fclose(fp); 
}
else { printf("\n Invalid password!");}
return 0;
}


void menu(char msg[30])
{
system("clear");
printf (" \n ----------------------------------------------");
printf (" \n P A S S W O R D   L I B R A R Y - 20.07");
printf (" \n Developed by Paulo C. Ormonde");
printf (" \n ----------------------------------------------");
printf (" \n Status: %s", msg);
printf (" \n ----------------------------------------------");
printf (" \n ");
		  printf(" \n [r] Read library"); 
	      printf(" \n [l] Password service list"); 
          printf(" \n [w] Write a password service");
printf (" \n");
printf (" \n Choose an option or 'q' to exit: ");
}
