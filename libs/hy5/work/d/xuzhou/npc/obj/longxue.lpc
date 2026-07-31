
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
   set_name(HIY"龙靴"NOR, ({ "long xue","xue","shoe"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
	 set("long","这是一双皇帝穿的龙靴。\n");
     set("material", "cloth");
     set("unit", "双");
     set("value", 10000);
     set("armor_prop/armor", 60);
	 set("armor_prop/dodge", 30);
   }
   setup();
}
