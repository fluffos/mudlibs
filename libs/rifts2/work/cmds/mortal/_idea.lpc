//	/bin/user/_idea.c
//	from the Nightmare mudlib
//	created by Descartes of Borg 20 october 1992

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_idea(string text);
int help();


int
cmd_idea(string text)
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
	if(elements[0] == "wizards") who = elements[1];
	else if(elements[0] == "d") who = elements[1];
	else who = 0;
        seteuid(UID_LOG);
	log_file("ideas", "Idea reported by "+capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");
	if(who) {
	    log_file("reports/"+who, "Idea reported by "+capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");
	}
	log_file("ideas", file+": "+text+"\n");
	if(who) log_file("reports/"+who, file+": "+text+"\n");
	INFORM_D->do_inform("typos,_bugs,_etc.","Idea ("+(string)
	this_player()->query_cap_name()+"): "+text);
        seteuid(getuid());
        write("Idea reported, thank you!\n");
	return 1;
}

int
help()
{
	write(
	"Syntax: <idea [(object)] [message]>\n"+
	"\n"+
	"Logs a idea to the creator of a room or object.\n"+
	"When no object is specified, the room is assumed to be the target of the idea.\n"+
	"\nSee also: bug, typo, praise, mudidea\n");
	return 1;
}
