//      /bin/ambassador/_man.c
//      from the Nightmare Mudlib
//      a command for accessing efun, simul_efun, and lfun man pages
//      created by Hanse@Nightmare 930117

#include <std.h>

inherit DAEMON;

#define man_dirlist ({ "efun", "lfun", "man" })
#define NULL 0
 
varargs void man( string name );
int help();
 
varargs string *find_manpage(string root, mixed arg, string name);
 
int cmd_man( string str )
{
     string arg, name;
 
     if( ! str )
     {
          return help();
     }
     sscanf( str, "%s",  name );
     man( name );
     return 1;
}
 
int valid_man_read( string *manentry ) {  return 1;  }
 
varargs void man( string name ) {
     string *manent;
 
     manent = find_manpage( name );
     if( manent )
     {
          if( valid_man_read( manent ) )
          {
               this_player()->more( manent[2] );
          }
          else
               write( "man:  no permission\n" );
     }
     else
     {
          if( name )
               write("man: "+name+" not found.\n");
     }
}
 
varargs string *find_manpage( string name )
{
     int i;
     string *rv;
 
     rv = allocate( 3 );
 
     for( i=0 ; i<sizeof(man_dirlist) ; i++ )
     {
           rv[0] = man_dirlist[i];
           rv[2] = "/doc/" + rv[0] + "/" + name;
           if( file_size( rv[2] ) > 0 ) break;
     }
     if( i == sizeof( man_dirlist ) ) rv = NULL;
     return rv;
}
 
int help() {
  write("Command: man\nSyntax: man [secnum] <topic>\n"+
        "This command gives you more information on the topic\n"+
        "if available.  Secnum is an optional section number\n"+
        "designation.  You are encourage to use man as much as\n"+
        "possible to help solve your problems.\n");
  return 1;
}
