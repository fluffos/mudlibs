#include <armor.h>
#include <ansi.h>
inherit SHIELD;


void create()
{
  set_name(HIM"乾坤盾"NOR, ({ "dun" }) );
//  set_name(names[i], ({ids[i], "dun", "shield"}));
set_level(20);
  set_weight(1000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 0);
   set("no_put",1);
                set("fz_get",1);
   set("no_zm",1);
//   set("no_give",1);
   set("material", "skin");
   set("armor_prop/armor", 100);
   set("armor_prop/dodge", -10);
  }
  set("no_sell",1);
  setup();
}
