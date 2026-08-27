#include <command.h>

int
main(string arg)
{
  if(!arg)
    return notify_fail("usage: echoall <text>\n");

  shout(arg + "\n");
  write("Everybody just saw: " + arg + "\n");

  return 1;
}
