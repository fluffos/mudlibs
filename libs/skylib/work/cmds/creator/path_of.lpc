/* pathof command, trial out by Turrican for a commands daemon. */

#include <creator.h>

inherit COMMAND_BASE;

mixed cmd(string str) {
  object *ov, ob;

  notify_fail("Pathof what?\n");
  ov = WIZ_PRESENT->wiz_present(str, this_player());
  if (!sizeof(ov)) return 0;

  foreach (ob in ov) {
    if (!objectp(ob)) continue;
    write("Path of " + WIZ_PRESENT->desc_object(ob) + " in " +
        WIZ_PRESENT->desc_object(environment(ob)) + ":\n");
    write(file_name(ob)+ "\n");
  }
  return 1;
}
