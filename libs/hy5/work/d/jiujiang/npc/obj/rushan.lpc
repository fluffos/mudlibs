
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(HIG"紧袖糯衫"NOR, ({ "ru shan","shan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一双女人穿的紧袖糯衫。\n");
     set("material", "布");
     set("unit", "件");
     set("value",10);
     set("armor_prop/armor",3);
     set("female_only",1);
     
   }
   setup();
}
