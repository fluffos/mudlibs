
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name(HIY"龙袍"NOR, ({ "long pao","pao","cloth"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
	 set("long","这是一见皇帝穿的龙袍，上面绣着真龙，栩栩如生。\n");
     set("material", "cloth");
     set("unit", "件");
     set("value", 1000);
     set("armor_prop/armor", 60);
   }
   setup();
}
