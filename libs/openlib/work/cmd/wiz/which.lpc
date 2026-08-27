/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

int
main(string verb)
{
  string cmd;

  if(!verb)
    return notify_fail("which <command verb>\n");

  cmd = CMD_D->find_cmd(verb, 1);

  if(cmd)
    write(cmd + "\n");
  else
    return notify_fail(sprintf("which: %s: no such command.\n", verb));

  return 1;
}
