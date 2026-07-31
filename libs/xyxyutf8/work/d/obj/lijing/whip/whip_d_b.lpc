#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name(HIC"电闪雷鸣鞭"NOR, ({"whip","bian"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("no_put",1);
                set("value", 500000);
                set("no_zm",1);
                set("material", "iron");      
                set("weapon_prop/strength", 20);          
                set("long","这是一件传说中的神器。\n");
		set("wield_msg", "只听「啪」的一声响，$N的手中闪出一条$n。\n");
		set("unwield_msg", "$N把手中$n缠回腰间．\n");
        }
        init_whip(170+random(20));
        setup();
}

