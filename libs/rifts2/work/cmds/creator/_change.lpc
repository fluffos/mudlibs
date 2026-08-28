//	/cmds/creator/_change.c

//	from the Darkemud mudlib

//	created by Shadowraith the Damned 26 Sep 96



#include <std.h>

#include <security.h>

#include <daemons.h>



inherit DAEMON;



int cmd_change(string text);

int help();





int

cmd_change(string text)

{

    string fn, changed;



	if( !text )

	{

		help();

		return 1;

	}

	if( (sscanf(text, "%s %s", fn, changed) != 2) &&

	    (text != "list" ) ) {

	    write("Could you please be a little more descriptive?\n");

	    return 1;

        }

   seteuid(UID_LOG);

   if(text == "list") {

      this_player()->more("/log/change","info");

      seteuid(getuid());

      return 1;

   }

	log_file("change", capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");

	log_file("change", fn+" modified due to: "+changed+"\n");

	INFORM_D->do_inform("typos,_bugs,_etc.","Change ("+(string)

	this_player()->query_cap_name()+"): "+text);

        seteuid(getuid());

        write("Change reported, thank you!\n");

	return 1;

}



int

help()

{

	write(

	"Syntax: <change [filename] [reason]>\n"+

	"\n"+

	"Logs a change to [filename] and the reason for the change.\n"+

	"\nSee also: bug, typo, praise, mudidea\n");

	return 1;

}

