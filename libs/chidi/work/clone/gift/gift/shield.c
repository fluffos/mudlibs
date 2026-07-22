#include <armor.h>
#include <ansi.h>

//inherit F_UNIQUE;
inherit SHIELD;
void create()
{
  set_name(HIY"战神之守护"NOR, ({"zhanshen shouhu","shield", "dun"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 1000);
   set("long", "这是传说中的战神所化成的盾。\n");
   set("material", "crimsonsteel");
   set("no_zm",1);
     set("12gong",1);
 
   set("no_sell", 1);
   set("no_drop", 1);
   set("no_put", 1);
   set("armor_prop/armor", 13800);
   set("armor_prop/dodge", 1800000);
  }
  setup();
}
