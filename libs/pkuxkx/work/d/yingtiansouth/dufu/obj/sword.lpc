
#include <weapon.h>
#include "MengWeapon.h"
inherit SWORD;

void create()
{
         set_name("钢剑", ({"gang jian","jian", "sword" }) );
         set_weight(3000);
         if( clonep() )
                 set_default_object(__FILE__);
         else {
                 set("unit", "柄");
                 set("value", 0);
                 set("material", "iron");
         }
         init_sword(15);
         setup();
		 call_out("Consume",2);
}

