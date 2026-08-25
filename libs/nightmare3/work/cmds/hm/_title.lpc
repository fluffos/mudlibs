//	/bin/high_mortal/title.c
//	from the Nightmare mudlib
//	a title changing command for high mortals
//	created by Descartes of Borg 06 december 1992

#include <std.h>

inherit DAEMON;

int cmd_title(string str) {
    if(!str) {
	notify_fail("Change your title to what?\n");
	return 0;
    }
    if(!creatorp(this_player())) {
	write("Your title is now: \"High mortal "+(string)this_player()->query_cap_name()+" "+str+"\"\n");
	this_player()->setenv("TITLE", "High mortal $N "+str);
    }
    else write("Use <setenv TITLE pretitle $N title>\n");
    return 1;
}

void help() {
    write("Syntax: <title [new title]>\n\n"+
	"Changes your title that comes after your name.\n");
}
