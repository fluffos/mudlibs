/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main(string str)
{
  if( !str )
    return notify_fail("usage: rmdom <domain name>\n");

  if( SECURITY_D->delete_domain(str) ) {
    write("Deleted domain: " + str +".\n");
    return 1;
  }

  return 0;
}
