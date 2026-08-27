#include <command.h>

int
main(string arg)
{
  if(arg == ""){
    return notify_fail("Usage:  title <new title>\n");
  }

  this_player()->set_title(arg);   // arg == 0 for list title

  return 1;
}
