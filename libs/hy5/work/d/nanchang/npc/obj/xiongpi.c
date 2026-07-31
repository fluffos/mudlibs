
#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
   set_name(WHT"π∑–‹∆§"NOR, ({ "xiong pi","pi"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "–‹∆§");
     set("unit", "’≈");
     set("value",500);
     set("armor_prop/armor",30);
   }
   setup();
}
