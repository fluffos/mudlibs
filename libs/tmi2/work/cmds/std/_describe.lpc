// _describe.c -- Code to 'describe' yourself
// written by Truilkan@TMI - 92/04/26
// Changed by Pallando (93-04-17) in response to bug from Robocoder.
//

#include <mudlib.h>

inherit DAEMON ;

// cmd_describe(string) 

int cmd_describe(string str)
{
   int pid;
   string file;

   write("Editing description.\n");
   file = temp_file( "desc" );
   if ((string)this_player()->query("long"))
   write_file(file,(string)this_player()->query("long"));
   this_player()->edit(file, "postit", this_object());
   return 1;
}

void postit(string header)
{
   string filename, body;

   filename = (string)this_player()->query_edit_filename();
   body = read_file(filename);
   rm(filename);
   this_player()->set_edit_filename("");
   this_player()->set("long", body);
}

string help() {
	return(@HELP
Syntax: describe

Describe allows you yo alter your description, which people see when they
look at you. It doesn't take an argument; instead, typing describe will
put you into the editor where you can enter the test, complete with line
feeds if you desire. Try not to use more then 2 or 3 lines, thought; it's
more polite.

See also: undescribe, look
HELP
  );
}
