/*
// The "ed" command.
// Written by Buddha (2-19-92)
// Part of the TMI mudlib.
*/

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_ed(string file) {
   string tmp;
   string wiznm;
   int i;
   
    if(!file) {
        notify_fail("Syntax: <ed [filename]>\n");
	return 0;
    }
    if(this_player()->query_forced()) {
        write("Someone tried to force you to ed "+file);
        return 1;
    }
   seteuid(geteuid(this_player()));
   tmp = (string)this_player()->get_path();
   file = resolv_path(tmp, file);
    if(file_size(file) == -2) {
	notify_fail("You cannot edit a directory!\n");
	return 0;
    }
   if(sscanf(file,"/wizards/%s/%s",wiznm,tmp) != 2 || wiznm !=
	(string)this_player()->query_name(1))
   if((string)this_player()->query_position() != "superuser")
	INFORM_D->do_inform("external_edits","Info: " + capitalize(
            (string)this_player()->query_name(1))+ " is editing "+
	    file + ".", ({ this_player() }) );
   if((i=file_size(file)) > -1)
      message("write", sprintf("%s , %d bytes:", file, i), this_player());
   ed(file);
   return 1;
}

int help()
{
  write( @EndText
Syntax: ed [filename]
Effect: edits the file named <filename>
See doc: /doc/immortals/ed
See man: ed
EndText
  );
  return 1;
}
