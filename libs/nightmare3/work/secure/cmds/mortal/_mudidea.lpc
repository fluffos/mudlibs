//	/bin/user/_mudidea.c
//	from the Nightmare mudlib
//	created by Descartes of Borg 20 october 1992
// Pallando (93-05-26) Changed environment(this_object()) to use this_player()

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_mudidea(string text);
void help();


int
cmd_mudidea(string text)
{
    string file;

	if( !text )
	{
		help();
		return 1;
	}
	file = file_name(environment(this_player()));
	log_file("mudideas", "Idea reported by "+capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");
	log_file("mudideas", file+": "+text+"\n");
        write("Idea reported, thank you!\n");
	return 1;
}

void help() {
	write(
      "Syntax: <mudidea [idea]>\n\n"
      "Logs an idea for the mud as a whole for the mudlib group to read.\n"
      "See also: bug, idea, praise, typo\n"
    );
}
