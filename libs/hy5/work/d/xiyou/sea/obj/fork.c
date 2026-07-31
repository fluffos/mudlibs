
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("龙角叉", ({ "dragon fork", "fork" }) );
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 300);
    set("material", "bone");
    set("long", "一柄以龙角制造的长叉。\n");
    set("wield_msg", "$N抄起一柄$n举过头顶。\n");
  }
  init_staff(35);
  setup();
}

