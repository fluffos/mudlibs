//	/bin/user/_describe.c
//	from the Nightmare mudlib
//	User command for adding a description
//	created by Descartes of Borg 25 Nov 1992

#include <std.h>

inherit DAEMON;

int cmd_describe(string str) {
    if(!str) {
	this_player()->set_description(0);
	write("You remove your description.\n");
    }
    else {
	this_player()->set_description(str);
	write("Your description now reads: "+this_player()->query_cap_name()+" "+str+"\n");
    }
    return 1;
}

void help() {
    write("Syntax: <describe [(text)]>\n\n"+
	"Adds a description that people will see when they look at you.\n"+
	"The description is shown in the form of \"your name + text\".\n"+
	"For example, if I type <describe is a Borg.>, then my description\n"+
	"will read \"Descartes is a Borg.\".  If no argument is given, then\n"+
 "your description disappears.\n"
 "See also: look, chfn, passwd, timezone\n"
);
}
