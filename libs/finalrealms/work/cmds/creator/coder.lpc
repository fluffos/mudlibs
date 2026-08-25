/* 
 * Externalized by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup(){

position = 1;
}

protected int cmd(string str, object me) {
    object *ov;
    int i;

    notify_fail("Creator of what?\n");
    ov = wiz_present(str, me);
    if (!sizeof(ov)) return 0;

    for (i = 0; i < sizeof(ov); i++) {
	write("Creator of " + desc_object(ov[i]) + ": " +
	  "secure/master"->creator_file (file_name(ov[i])) + ", uid: " +
	  getuid(ov[i]) + ", euid: "+geteuid(ov[i])+"\n");
    }
    me->set_trivial_action();
    return 1;
} /* get_creator() */

