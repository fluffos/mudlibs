#include <command.h>

int
main(string arg)
{
  if( !arg ) {
    write("Done snooping.\n");
    snoop(this_player());
  } else {
    object ob;

    if( !(ob = find_player(arg)) )
      return notify_fail("Could not find that player\n");

    snoop(this_player(), ob);
    write("Snooping "+ arg +"\n");
  }
  return 1;
}
