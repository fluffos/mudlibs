//	_typo.c
//	originally came with the TMI mudlib
//	logging to creator report files added by Descartes of Borg 201092

#include <std.h>

inherit DAEMON;

int cmd_typo(string text);
int help();


int
cmd_typo(string text)
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
	log_file("typos", "Typo reported by "+capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");
	if(who) {
	    log_file("reports/"+who, "Typo reported by "+capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");
	}
	log_file("typos", file+": "+text+"\n");
	if(who) log_file("reports/"+who, file+": "+text+"\n");
        write("Typo reported, thank you!\n");
	return 1;
}

int
help()
{
	write(
	"Syntax: <typo [(object)] [message]>\n"+
	"\n"+
	"Logs a typo to the creator of a room or object.\n"+
	"When no object is specified, the room is assumed to have the typo.\n"+
	"\nSee also: bug, idea, praise, mudidea\n");
	return 1;
}
