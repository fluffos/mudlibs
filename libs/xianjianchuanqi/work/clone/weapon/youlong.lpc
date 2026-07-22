// youlong.c

#include <weapon.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name("游龙剑", ({ "youlong sword", "youlong", "sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("long",
"这是把看起来很普通的长剑，但仔细一看，剑身上有几条细纹闪烁不定。\n");
                set("value", 10000);
                set("material", "blacksteel");
                set("wield_msg", 
"只听见「飕」地一声，$N的手中已经多了一把寒光四射的宝剑——$n。\n");
                set("treasure", 1);
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(50);
        setup();
}
