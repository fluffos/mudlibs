
#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
   set_name(HIB"Æ¤¶Ü"NOR, ({ "pi dun","dun","shield"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "ÊÞÆ¤");
     set("unit", "¸ö");
     set("value",500);
     set("armor_prop/armor",16);
   }
   setup();
}
