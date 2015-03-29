#include <stdio.h>
#include <stdlib.h>
#include "createProcess.h"
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <dirent.h>
#include "killProcessById.h"


void killProcessById(char *argumenten[]){
    int pidToKill;

    pidToKill = atoi(argumenten[1]);
        
    if(pidToKill != 0){

        kill(pidToKill,SIGTERM);

        createProcess("ps",NULL);

        char chkUserInput = ' ';
        char usrinput;

        while(chkUserInput != 'y'){
            printf("\nBent u tevreden met het resultaat? kies dan 'y'\nBent u dat niet, en wilt u het process met SIGKILL beeindigen? Kies dan 'n'\ny/n : \n");

            usrinput = getchar();
            if(usrinput == 'y' || usrinput == 'n'){
                if(usrinput == 'y'){
                    chkUserInput = 'y';
                }
                else {
                    printf("Het kill proces wordt met SIGKILL uitgevoerd.\n");
                    kill(pidToKill,SIGKILL);
                    chkUserInput = 'y';
                }
            }
            else{
                break;
            }
        }
    }
    else{
        perror("Geen geldig waarde.");
    }
}
