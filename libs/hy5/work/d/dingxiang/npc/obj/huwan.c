
#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
   set_name(BLU"»¤Íó"NOR, ({ "hu wan","hu","wan"}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Ìú");
     set("unit", "¸±");
     set("value",100);
     set("armor_prop/armor",4);
   }
   setup();
}
