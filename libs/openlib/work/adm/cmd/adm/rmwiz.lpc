/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main(string str)
{
  if( !str )
    return notify_fail("usage: rmwiz <wizard name>\n");

  if( SECURITY_D->delete_wizard(str) ) {
    object ob = find_player(str);

    if( ob )
      message("system", "You are no longer a wizard.  Sorry! :(\n", ob);
    write("Deleted wizard: " + str +".\n");
    return 1;
  }

  return 0;
}
