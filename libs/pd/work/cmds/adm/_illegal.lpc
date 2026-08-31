//      /bin/user/_illegal.c
//      handles all illegal name substring commands
//     created 940411 by Peter Svensson

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int add_sub(string str);
int rem_sub(string str);
int list();
void help();

int cmd_illegal(string str) {
    string com, extra;

    if(!admp(this_player())) return 0;
    if(!str) {
	help();
	return 1;
    }
    if(sscanf(str, "%s %s", com, extra) == 2) {
	switch(com) {
	    case "add": return add_sub(extra); break;
	    case "remove": return rem_sub(extra); break;
	    case "list": return list(); break;
	    default: help(); return 1; break;
	}
    }
    else {
	if(str == "list") return list();
	else {
	    help();
	    return 1;
	}
    }
}

int add_sub(string str) {
    
    seteuid(UID_BANISH);
    BANISH_D->set_illegal_substring(str);
    seteuid(getuid());
    write("The string '"+str+"' is now prohibited.");
    list();
    return 1;
}

int rem_sub(string str) {

    seteuid(UID_BANISH);
    BANISH_D->remove_illegal_substring(str);
    seteuid(getuid());
    write("The string '"+str+"' is no longer prohibited.");
    list();
    return 1;
}

int list() {
    string *ill_names;
    int i;

    seteuid(UID_BANISH);
    ill_names = BANISH_D->query_illegal_substrings();
    seteuid(getuid());
    if(!ill_names) {
	notify_fail("Unable to comply. Report this.\n");
	return 0;
    }
    if (!sizeof(ill_names))
	{
	write("No substrings are forbidden.");
	return 1;
	}
    write("The following substrings can not appear in new characters' names:");
    for(i=0; i<sizeof(ill_names); i++) {
	write("  "+ill_names[i]);
    }
    return 1;
}
 
void help() {
    write("Command: illegal\n"+
	"Syntax: <illegal list>\n"+
	"        <illegal add [string]>\n"+
	"        <illegal remove [string]>\n\n"+
	"<illegal list> shows all currently active prohibations. <illegal add>\n"+
	"ensures that no further charaters can be created containing that name.\n"+
	"<illegal remove> allows that string to be used again.\n\n"+

 "See also: banish, unbanish\n"
  );
}
