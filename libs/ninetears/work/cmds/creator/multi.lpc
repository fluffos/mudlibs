#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
#define PEOPLER "/obj/handlers/peopler"

void setup()
{
position = 1;
}

int cmd(string str, object me) {
  string multi = PEOPLER->do_multi();
  write(multi+"\n");
  return 1;
} /* do_people() */

