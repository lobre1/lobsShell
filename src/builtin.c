#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "builtin.h"
#include "main.h"

char *cmds[]={
	"cd",
	"exit",
	"pwd",
};

int numOfCmds=sizeof(cmds)/sizeof(char*);
int ( *cmdsFunc[] )( char *arg[] )={
	&cdCmd,
	&exitCmd,
	&pwdCmd,
};

int cdCmd( char *args[] ){
	if (chdir(args[1])==-1) {
		perror("cd:");
	}
	return 0;
}
int exitCmd( char *args[] ){
	quit();
	return 0;
}
int pwdCmd( char *args[] ){
	char dirBuf[1024];
	if (getcwd(dirBuf, sizeof(dirBuf))==NULL) {
		perror("pwd:");
		return 1;
	}
	printf("%s\n", dirBuf);
	return 0;
}

