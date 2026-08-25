/* 
 * Externalize by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup(){

position = 1;
}

protected int cmd(string str, object me) {
    object *obs;

    if(!str) {
	notify_fail("Usage: " + query_verb() + " <object>\n");
	return 0;
    }
    if(!sizeof(obs = wiz_present(str, me))) {
	notify_fail("Object " + str + " not found.\n");
	return 0;
    }
    write(debug_info( 0, obs[0]));
    me->set_trivial_action();
    return 1;
} /* do_debug() */

