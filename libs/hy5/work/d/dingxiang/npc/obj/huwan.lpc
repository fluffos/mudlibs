
#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
   set_name(BLU"护腕"NOR, ({ "hu wan","hu","wan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "铁");
     set("unit", "副");
     set("value",100);
     set("armor_prop/armor",4);
   }
   setup();
}
