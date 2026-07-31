
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
   set_name(HIG"Âêè§°âÖ¸"NOR, ({ "ban zhi","zhi"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "Âêè§");
     set("unit", "Ã¶");
     set("value",200);
     set("armor_prop/armor",10);
     set("armor_prop/dodge",1);
   }
   setup();
}
