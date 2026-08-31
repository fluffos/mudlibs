/*
// The "ed" command.
// Written by Buddha (2-19-92)
// Part of the TMI mudlib.
*/
#include <std.h>
#include <security.h>
#include <daemons.h>
inherit DAEMON;
int cmd_edall(string edAction) {
  string tmp;
  int i;

  if(!edAction) {
    notify_fail("Syntax: <ed [filename]>\n");
    return 0;
  }
  if(this_player()->query_forced()) {
    return 1;
  }
  seteuid(geteuid(this_player()));
  tmp = (string)this_player()->get_path();
  tmp += "/";
  foreach(string file in get_dir(tmp)) {
    write("DOTHISLOLOL:ed "+file);
    write("DOTHISLOLOL:"+edAction);
    write("DOTHISLOLOL:x");
  }
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
