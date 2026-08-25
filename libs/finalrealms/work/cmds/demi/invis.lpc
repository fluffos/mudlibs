/* invis.c
 * Syll Mar'98
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit "/cmds/handlers/wiz_cmd_base";

void setup(){

    position = 1;
}

protected int cmd(string str, object me) {
  if (str == "2") {
      if (me->query_invis() == 2) {
        notify_fail("You are already truly invisible.\n");
        return 0;
      }
      write("You become truly invisible.\n");
      me->set_invis(2);
      return 1;
  }
} /* invis.c */
