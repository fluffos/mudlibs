/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main(string str)
{
  if( !str )
    return notify_fail("usage: rmpriv <priv name>\n");

  if( SECURITY_D->delete_priv(str) ) {
    write("Deleted priv: " + str +".\n");
    return 1;
  }

  return 0;
}
