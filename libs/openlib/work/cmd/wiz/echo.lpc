#include <command.h>

int
main(string arg)
{
  if(!arg)
    return notify_fail("usage:  echo <message>\n");

  tell_room(environment(this_player()), arg + "\n");

  return 1;
}
