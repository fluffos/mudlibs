/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main(string str)
{
  if( !str )
    return notify_fail("usage: mkpriv <priv name>\n");

  if( str = SECURITY_D->create_priv(str) ) {
    write("Created new priv: " + str +".\n");
    return 1;
  }

  return 0;
}
