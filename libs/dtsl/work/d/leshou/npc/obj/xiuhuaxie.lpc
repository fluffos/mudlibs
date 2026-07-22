
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIR"绣花鞋"NOR, ({ "xiu hua xie","xie","shoe"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
	 set("long","这是一双女式的绣花鞋。\n");
     set("material", "cloth");
     set("unit", "双");
     set("value", 200);
     set("armor_prop/armor", 8);
	 set("armor_prop/dodge", 10);
   }
   setup();
}
