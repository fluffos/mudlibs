// hostname.c
// Tells you what host the mud is running on.
// Someone wrote it and didn't add a header.
// Mobydick tacked the header on and added help, 11-20-92
// Someone else 'fixed' it in a most unusual manner. 93-08-26

#include <config.h>
//#include <net/daemons.h>
#include <net/i3.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_hostname()
{
  mapping list=I3_DAEMON->query_mudlist();
  string *names=keys(list);
  mixed vls=values(list); 

    printf( "%s is running on %s, port: %d.\n",
        capitalize(THIS_MUD),
        //(string)DNS_MASTER-> get_host_name(THIS_MUD),
        vls[member_array(mud_name(),names)][1],
        __PORT__,
    );
    return 1;
}

string help() {
	return ("Syntax: hostname\n\n"+
"Tell you the name of the MUD you're playing. For the forgetful..:)\n") ;
}
 
