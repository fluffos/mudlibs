// A quick hack for a unix-like command here...
// added by Buddha@TMI (5-24-92)
// Visibility check added by Pallando, (93-02-05)
// User count added by Moby, 94-03-02

#include <mudlib.h>

inherit DAEMON ;

int cmd_users() { 
	object *who;
	int i;
        who = filter_array(users(),"filter",this_object(),previous_object());
	for (i=0;i<sizeof(who);i++) {
		if(objectp(who[i])) write((string)who[i]->query("name") + " ");
		else write("(null) ");
	}
	write("\n");
	write (sizeof(who)+" users logged in.\n") ;
	return 1;
}

int filter( object user, object player ) { return visible( user, player ); }

int help() {
	write ("Usage: users\n\n"+
"Returns a barebones list of logged-in users.\n"+
	"" );
	return 1 ;
}
