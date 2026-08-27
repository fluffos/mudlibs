// lsprot.c:  list file protections
// created by Tim 16 Jun 1996

#include <cmdline.h>
#include <daemons.h>

int
main(string* argv, string* argv2)
{
  mapping info = SECURITY_D->get_protections(flag("r"));
  string* lines;

  if( flag("r") )
    lines = ({ "Read Protections:" });
  else
    lines = ({ "Write Protections:" });

  foreach(string key in sort_array(keys(info), 1))
    lines += ({ sprintf("%-20s -> %s", key, info[key]) });

  this_player()->more(lines);
  return 1;
}
