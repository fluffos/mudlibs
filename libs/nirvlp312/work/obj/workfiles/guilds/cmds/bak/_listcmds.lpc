#include "../guild_defs.h"

int cmd_listcmds(string arg)
{
  int    i, x;
  string *cmds;
  if(arg) return 0;

  cmds = (string*)MASTER->get_cmds();

  x = sizeof(cmds);
  for(i = 0; i < x; i ++)
    write("  " + cmds[i] + "\n");

  return 1;
}
