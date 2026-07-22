
#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("绸衣", ({ "cloth","yi","chou"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","这是一件名贵的稠衣\n");
     set("unit", "件");
     set("value", 60);
     set("armor_prop/armor", 8);
   }
   setup();
}
