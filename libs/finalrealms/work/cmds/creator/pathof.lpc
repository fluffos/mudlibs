/* pathof.c
 * Externalized by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup()
  {
  position = 1;
}

int cmd(string str, object me) {
    object *ov;
    int i;

    notify_fail("Pathof what?\n");
    ov = wiz_present(str, me);
    if (!sizeof(ov)) return 0;

    for (i = 0; i < sizeof(ov); i++) {
	if (!ov[i]) continue;
	/*
	      if (sizeof(ov) > 1) {
	 */
	write("Path of " + desc_object(ov[i]) + " in " +
	  desc_object(environment(ov[i])) + ":\n");
	/*
	      }
	 */
	write(file_name(ov[i])+ "\n");
    }
    me->set_trivial_action();
    return 1;
} /* get_pathof() */

