#include <cmdline.h>
// By Tim 22 Apr 96

int
main(string* argv, string* argv2)
{
  string info;

  if( !flag("malloc") ) {
    if( flag("l") )
      info = mud_status(1);
    else
      info = mud_status(0);
  } else
    info = malloc_status();

  this_player()->more(explode(info, "\n"));
  return 1;
}
