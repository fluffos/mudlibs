
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(WHT"狗熊皮"NOR, ({ "xiong pi","pi"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "熊皮");
     set("unit", "张");
     set("value",500);
     set("armor_prop/armor",30);
   }
   setup();
}
