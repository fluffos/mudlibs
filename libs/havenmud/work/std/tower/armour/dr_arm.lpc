#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit GEN_ARMOUR;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_name("banded mail");
  set_alias("mail");
  set_alt_name("banded");
  set_weight(2);
  set_warmth(15);
  set_short("a suit of banded mail");
  set_long("\
This is a suit of banded mail which bears the dents \n\
and scars of combat.  It has odd scratches on it as if \n\
it's owner had claws.\n");
  set_ac(20);
  set_new_type(TORSO);
  set_material(MAT_STEEL);
  set_weakness(DAM_LIGHTNING);
  set_value(-1);
}
