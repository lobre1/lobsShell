#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "execute.h"
#include "builtin.h"

const char *operators[]={"||", "&&", ";"};

int exec( char **cmd, int numOfToks ){
	for (int i=0; i<numOfCmds; i++) {
		if (strcmp(cmd[0], cmds[i])==0) {
			return ( *cmdsFunc[i] )( cmd );
		}
	}
	pid_t p=fork();
	if(p<0){
		perror("Fork failed");
		return 1;
	}
	if(p>0){
    /*int status;
    waitpid(p, &status, 0);
    if (WIFEXITED(status)) {
        int execStat=WEXITSTATUS(status);
        if (execStat!=0) {
            printf("FALSe%d\n", WEXITSTATUS(status));
        }
    }*/
		p=wait(NULL);
		return 0;
	}
	if(p==0){
		int h=execvp(cmd[0], cmd);
		if( h==-1 ){
			perror("Command not found");
			return 1;
		}
  }
		exit(0);
	return 1;
}

