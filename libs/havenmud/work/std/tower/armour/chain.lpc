#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit GEN_ARMOUR;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("chainmail");
  set_alias("chain");
  set_alt_name("mail");
  set_short("a red-hued suit of chainmail");
  set_long("\
A finely crafted suit of chainmail.\n");
  set_ac(30);
  set_warmth(10);
  set_material(MAT_STEEL);
  set_color("|RKB");
  set_new_type(TORSO);
  set_weight(3);
  set_resistance(DAM_EVIL);
  set_value(-1);
  replace_program(GEN_ARMOUR);
}
