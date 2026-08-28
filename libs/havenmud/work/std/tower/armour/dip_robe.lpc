#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit GEN_ARMOUR;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("robe");
  set_alias("drobe");
  set_short("light silk robes");
  set_long("\
These are the ornamental robes worn by Diplomats to the\n\
court of Rath-Khan.\n");
  set_ac(25);
  set_warmth(10);
  set_info("\
This robe seems to have been imbued with protection\n\
from Rath-Khan in an effort to keep Ambassadors alive.\n");
  set_resistance(DAM_EVIL);
  set_new_type(ARMOUR);
  set_material(MAT_CLOTH);
  set_value(-1);
  replace_program(GEN_ARMOUR);
}
