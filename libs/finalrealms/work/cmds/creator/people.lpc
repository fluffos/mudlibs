#include <standard.h>
#include <cmd.h>
#define PEOPLER "/obj/handlers/peopler"
inherit CMD_BASE;

void setup()
{
position = 1;
}

protected int cmd(string str, object me) {
  me->set_trivial_action();
  return (int)PEOPLER->do_people(str);
} /* do_people() */


