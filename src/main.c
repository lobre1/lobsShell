#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

#include "main.h"
#include "execute.h"

int tokenizer( char inp[], char *inpTok[], char delim[] );

int main( int argc, char *argv[] ){
	struct passwd *pw=getpwuid(getuid());

	const char *homedir=pw->pw_dir;
	char inp[BUFDEF];
	char *inpTok[BUFDEF];
	char dirBuffer[BUFDEF];
	char userBuffer[BUFDEF];
	char userStatus;

	while (1) {
		uid_t u=getuid();
		if (u==0) {
			userStatus='%';
		}else {
			userStatus='$';
		}
		getcwd(dirBuffer, sizeof(dirBuffer));
		printf("[%s]%c ", dirBuffer, userStatus);
		if (fgets(inp, sizeof(inp), stdin)==NULL) {
			if (feof(stdin)) {
				return 0;
			}else{
				perror("fgets");
				return 1;
			}
		}
		if (inp[0]==EOF) {
			break;
		}
		int tokCount=tokenizer(inp, inpTok, DELIM);
		exec(inpTok, tokCount);
	}
}

int tokenizer( char inp[], char *inpTok[], char delim[] ){
	int tokenCount=0;
	char *check=strtok(inp, delim);
	if (inp[0]=='\0' || check==NULL) {return 0;}
	while (check) {
		inpTok[tokenCount++]=check;
		check = strtok(NULL, delim);
	}
	inpTok[tokenCount]=NULL;
	free(check);
	return tokenCount;
}

int quit(){
	exit(0);
}
