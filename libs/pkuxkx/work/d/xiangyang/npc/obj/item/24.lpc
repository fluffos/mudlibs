#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "玄铁剑" NOR, ({"xuantie sword"}) );
    set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把黑幽幽的长剑\n"
);
                set("value", 21500);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

     init_sword(150);
        setup();

}

