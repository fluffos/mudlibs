//#pragma save_binary
/*
// Author unknown (??)
// Help added by Brian (1/28/92)
*/

#include <mudlib.h>

inherit DAEMON ;

int help();

int cmd_echoto(string str) {
    string	who, msg;
    object	ob;
 
    if( !str || sscanf(str,"%s %s", who, msg) != 2 ) {
       return help();
    }
    else if( !(ob=find_living( who=lower_case(who) )) ) {
	notify_fail(who+": no such player.\n");
	return 0;
    }
    else {
	tell_object(ob, sprintf("%-=75s", msg+"\n"));
	printf("%-=75s", "You echo: "+msg+"\n");
	return 1;
    }
}

int
help() {
  write("Command: echoto\nSyntax: echoto <player> <message>\n"+
        "This command sends the message you enter to the player\n"+
	"that you specify. Do not use this command to confuse players.\n") ;
  return 1;
}
