// jinqiang.c
// updated 5-30-97 pickle

#include <ansi.h>
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIG"新手长枪"NOR, ({ "qiang","spear" }));
  set_weight(14000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "杆");
    set("value", 10000);
    set("material", "gold");
    set("long", "此枪以黄金为头铜为杆。\n");
    set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
  }
  init_spear(70);
  setup();
}

