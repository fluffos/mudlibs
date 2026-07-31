
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIY"官服"NOR, ({ "cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "cloth");
	 set("long","这是当官的人所穿的衣服\n");
     set("unit", "件");
     set("value", 40);
     set("armor_prop/armor", 10);
   }
   setup();
}
