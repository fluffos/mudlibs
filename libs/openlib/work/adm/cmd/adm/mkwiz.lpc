/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main(string str)
{
  if( !str )
    return notify_fail("usage: mkwiz <wizard name>\n");

  if( str = SECURITY_D->create_wizard(str) ) {
    object ob = find_player(str);

    if( ob )
      message("system", "You are now a wizard.  Congratulations!!\n", ob);
    write("Created new wizard: " + str +".\n");
    return 1;
  }

  return 0;
}
