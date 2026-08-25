#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{
position = 1;
}



protected int cmd(string str, object me) {
  tell_object(me,dump_file_descriptors());
  me->set_trivial_action();
  return 1;
} /* do_fds() */
 
