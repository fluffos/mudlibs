// File  :  /cmds/adm/_what.c

#include <mudlib.h>
#include <writef.h>
#include <daemons.h>
 
inherit DAEMON ;

void divider() {
    write(@ENDTEXT
------------------------------------------------------------------------------
ENDTEXT
    );
}

int cmd_what(string arg) {
    object *list;
    string line;
    int i, s;
    object link ;

    if (!adminp(geteuid(this_player()))) {
        return 0;
    }

    divider();
    list = users(); 
 
    if (!(s = sizeof(list))) {
	write("\tWow, no one is logged on. How'd you manage that? ;)\n");
	divider();
        return 1;
    }
 
    if (s > 1)
	write("\t\t   There are "+ sizeof(list) +" users connected.\n");
    else
	write("\t\tHow lonely!  You're the only one here.\n");

    divider();
    printf("%-14s%-6s%-58s",
	"Name","Idle", "What\n");
    divider();

    for (i=0; i<s; i++) {
        string field;
	mixed val;

	field = (string) list[i] -> link_data("name");
	if (!field)
	    field = "(null)";
	else
	    field = capitalize(field);
	if(list[i]->query("invisible"))  field = "(" + field + ")";
 
	if ((int)list[i]->query("npc"))  field += " [M]";
 
	if (!list[i]->query("inactive") && 
	    (in_edit(list[i]) || in_input(list[i])))
		field = "*" + field;
	line = sprintf("%-14s", field);
        link = (object) list[i]->query_link();
	val = query_idle(list[i]);
	if (list[i]->query("inactive"))   field = "Inact";
	else if ( val <= 0 ) field = "";
	else if( val >= 3600 ) field = val/3600 + "h";
	else if( val >= 60 ) field = val/60 + "m";
	else field = "";
	line += sprintf("%-6s", field);
	field = adminp(geteuid(list[i])) ? "*" :
	      list[i]->query_last_command();
	if (!field)  field = "-";
	if (strlen(field) > 58) field = field[0..51] + " [...]";
	line += sprintf("%-58s\n", field);
	write( line );
    }
    divider();
    return 1;
}


string help() {
	return( @ENDHELP
Usage: what

This command lists the users currently logged on, their idle time, and
what their last command was.  Consider this a less intrusive method of
snooping for nosy admins.
ENDHELP
	);
}
