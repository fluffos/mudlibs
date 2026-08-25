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
    if (me->query_invis()) {
        notify_fail("You are already invisible.\n");
        return 0;
    }
    write("You become invisible.\n");
    say(me->query_cap_name()+" dissappears from view.\n", me);
    me->set_invis(1);
    return 1;
} /* invis.c */
