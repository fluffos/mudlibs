
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name("尖头履", ({ "boot"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一双女人穿的尖头履。\n");
     set("material", "布");
     set("unit", "双");
     set("value",10);
     set("armor_prop/armor",3);
     set("female_only",1);
     
   }
   setup();
}
