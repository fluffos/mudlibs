
#include <weapon.h>

inherit SWORD;

void create()
{
   set_name("钢剑", ({ "sword" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 1500);
     set("material", "iron");
     set("long", "这是一寻常的钢剑，份量大约六、七斤重。\n");
     set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
   }
   init_sword(35);
   setup();
}
