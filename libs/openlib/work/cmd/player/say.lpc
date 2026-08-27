/*  -*- LPC -*-  */
#include <command.h>

int
main(string arg)
{
  if(!arg)
    return notify_fail("usage:  say <text>\n");

  say(sprintf("%s says: %s\n",
	      this_player()->query_cap_name(),
	      capitalize(arg)));

  printf("You say: %s\n", arg);

  return 1;
}
