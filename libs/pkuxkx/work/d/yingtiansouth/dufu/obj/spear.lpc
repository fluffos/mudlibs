
#include <weapon.h>
#include "MengWeapon.h"
inherit SPEAR;

void create()
{
         set_name("钢枪", ({"gang qiang","qiang", "sword" }) );
         set_weight(7000);
         if( clonep() )
                 set_default_object(__FILE__);
         else {
                 set("unit", "柄");
                 set("value", 0);
                 set("material", "iron");
         }
         init_spear(15);
         setup();
		 call_out("Consume",2);
}

