#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("乌龙锏", ({"dragon mace", "mace", "ironmace"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("value", 500);
    set("material", "iron");
    set("long", "一柄黑色龙吞护手锏。\n");
    set("wield_msg", "$N操起一根$n，摆了个架式。\n");
    set("unwield_msg", "$N将$n别回腰间。\n");
  }
  init_staff(650);
  setup();
}

