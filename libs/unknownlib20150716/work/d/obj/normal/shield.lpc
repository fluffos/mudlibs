#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
  set_name(HIG"盾牌"NOR, ({"dun", "shield"}));
  set_level(1);
  set_weight(6000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 200);
   set("material", "wood");
   set("armor_prop/armor", 32);
   set("armor_prop/dodge", -2);
  }
  set("no_sell",1);
  setup();
}
