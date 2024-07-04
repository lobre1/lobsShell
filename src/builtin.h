#ifndef BUILTIN_H

extern char *cmds[];
extern int numOfCmds;
extern int ( *cmdsFunc[] )( char *arg[] );

int cdCmd( char *args[] );
int exitCmd( char *args[] );
int pwdCmd( char *args[] );

#endif
