#include <weapon.h>

inherit BLADE;

void create()
{
   set_name("砍竹刀", ({"bamboo blade","dao","blade"}) );
   set_weight(600);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 100);
     set("material", "iron");
     set("long", "一把长柄砍竹刀。\n");
     set("wield_msg", "$N从后腰带抽出一把$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插入腰间。\n");
   }
   init_blade(35);
   setup();
}
