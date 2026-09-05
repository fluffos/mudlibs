#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIY "侠光剑" NOR, ({ "xiaguang jian","jian","sword" }) );
    	set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把金灿灿的长剑\n"
);
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N从剑鞘中拔出一把$n握在手中，眼前顿时一片金光。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }


     init_sword(150);
     setup();

}
