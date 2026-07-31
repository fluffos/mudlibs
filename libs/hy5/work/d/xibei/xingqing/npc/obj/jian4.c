//jian4.c.太阿剑
//date:1997.8.27
//by dan 

#include <weapon.h> 
#include <ansi.h>
inherit SWORD;   

void create()
{
        set_name(HIG"太阿剑"NOR, ({ "tai a jian", "jian" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"这把剑通体清澈透亮，微微透出寒光，是一把上古利刃。\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", 
"只听见「飕」地一声，$N的手中已经多了一把寒光四射的宝剑——$n。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(58);
        setup();
}
 

