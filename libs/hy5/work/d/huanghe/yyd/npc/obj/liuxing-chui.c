#include <weapon.h>

inherit HAMMER;

void create()
{
         set_name("流星锤", ({ "liuxing chui", "chui", "hammer" }) );
         init_hammer(24);
         set("unit", "把");
         set_weight(1200);
         if( clonep() )
         set_default_object(__FILE__);
         else {
         set("value", 130);
         set("material", "metal");
          }
         set("wield_msg","$N你从地上捧起一些沙子，把沙子灌入流星锤中，握在手里。\n");
         setup();
}

