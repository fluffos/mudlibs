/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main(string str)
{
  if( !str )
    return notify_fail("usage: mkdom <domain name>\n");

  if( str = SECURITY_D->create_domain(str) ) {
    write("Created new domain: " + str +".\n");
    return 1;
  }

  return 0;
}
