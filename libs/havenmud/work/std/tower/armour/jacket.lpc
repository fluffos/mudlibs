#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit GEN_ARMOUR;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("jacket");
  set_alias("leather");
  set_short("a leather jacket");
  set_long("\
This is an old leather jacket.  There seems to be something\n\
scrawled on the back.\n");
  set_read("VERY METAL\n");
  set_ac(10);
  set_new_type(TORSO);
  set_material(MAT_LEATHER);
  set_warmth(15);
  set_value(-1);
  replace_program(GEN_ARMOUR);
}
