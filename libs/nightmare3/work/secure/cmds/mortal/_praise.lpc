//	/bin/user/_praise.c
//	from the Nightmare mudlib
//	praise command
//	created by descartes of Borg 20 october 1992

#include <std.h>
#include <dirs.h>
#include <security.h>

inherit DAEMON;

int cmd_praise(string text);
int help();


int
cmd_praise(string text)
{
    string str, new_text;
    string file, who;
    string *elements;
    object ob;

	if( !text )
	{
		help();
		return 1;
	}
	if(sscanf(text, "%s %s", str, new_text) != 2) {
	    write("Could you please be a little more descriptive?\n");
	    return 1;
	}
	ob = present(str, environment(this_player()));
	if(!ob) ob = present(str, this_player());
	if(ob) text = new_text;
	else ob = environment(this_player());
	file = file_name(ob);
	elements = explode(file, "/");
	if(elements[0] == "realms") who = elements[1];
	else if(elements[0] == "domains") who = elements[1];
	else who = 0;
	log_file("praise", "Praise given by "+capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");
	if(who) {
	    log_file("reports/"+who, "Praise given by "+capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");
	}
	log_file("praise", file+": "+text+"\n");
	if(who) log_file("reports/"+who, file+": "+text+"\n");
        write("Praise given, thank you!\n");
	return 1;
}

int
help()
{
	write(
	"Syntax: <praise [(object)] [message]>\n"+
	"\n"+
	"Logs \"message\" of praise to the creator of the room or object\n"+
	"and to the main mud log so that the arches and the creator of the\n"+
	"object are aware that the room or object is appreciated.\n");
 write("\nSee also: bug, idea, typo, mudidea\n");
	return 1;
}
