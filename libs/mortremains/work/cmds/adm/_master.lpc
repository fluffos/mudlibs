#include <mudlib.h>
inherit DAEMON;

int cmd_master() {
  if (!adminp(this_player())) {
    write("Only admin can update the master object.\n");
    return 1;
  }

  destruct(master());
  file_size("???");
  write("Ok.\n");
  return 1;
}

string help()
{
  return( ""+
"Syntax: master\n"+
"Effect: Updates the master object.\n"+
  "" );
}
