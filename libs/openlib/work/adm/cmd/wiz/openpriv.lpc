// openpriv.c:  open one privilege to another
// created by Tim 16 Jun 1996

#include <cmdline.h>
#include <daemons.h>

int
main(string* argv, string* argv2)
{
  string guest, house;
  int optc = flag("c");

  if( sizeof(argv2) != 2 )
    return notify_fail("usage: openpriv [-c] <house-priv> <guest-priv>\n");

  house = argv2[0];
  guest = argv2[1];

  if( !optc )
  {
    if( SECURITY_D->open_priv(house, guest) )
    {
      printf("Priv '%s' is now open to '%s'.\n", house, guest);
      return 1;
    }
  }
  else
  {
    if( SECURITY_D->close_priv(house, guest) )
    {
      printf("Priv '%s' is now closed to '%s'.\n", house, guest);
      return 1;
    }
  }
  return 0;
}
