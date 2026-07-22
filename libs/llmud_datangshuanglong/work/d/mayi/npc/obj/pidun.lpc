
#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
   set_name(HIB"皮盾"NOR, ({ "pi dun","dun","shield"}) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "兽皮");
     set("unit", "个");
     set("value",500);
     set("armor_prop/armor",6);
   }
   setup();
}
