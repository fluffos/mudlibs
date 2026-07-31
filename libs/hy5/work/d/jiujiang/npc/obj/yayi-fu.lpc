
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
   set_name("衙役服", ({ "cloth"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是衙门衙役所穿的衣服。\n");
     set("material", "粗布");
     set("unit", "件");
     set("value",90);
     set("armor_prop/armor",2);
     
   }
   setup();
}
