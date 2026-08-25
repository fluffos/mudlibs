/* Whereis.c
 * Externalized by Baldrick jun '97
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;


void setup(){

position = 1;
}

protected int cmd(string str, object me) {
    object *ov,e;
    int i;

    notify_fail("Where is what?\n");
    ov = wiz_present(str, me);
    if (!sizeof(ov)) return 0; 

    for (i = 0; i < sizeof(ov); i++) {
	if (ov[i]->query_invis() > 1) continue;
	write(desc_object(ov[i]) + " is : \n");
	e = ov[i];
	while (e = environment(e))
	    write("  in " + desc_f_object(e) + "\n");
    }
   me->set_trivial_action();
    return 1;
} /* whereis() */

