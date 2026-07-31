// sgzl

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);

string ori_long="一把淡蓝色的细剑，剑身几乎透明，剑锋处闪着点点寒光，
剑柄处似乎有个机关能装 (install) 些暗器进去。\n";


void create()
{
       set_name("凤凰琴", ({"fenghuang qin","qin","sword"}));
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",ori_long);
                set("orilong",ori_long);
                set("unit", "把");
                set("value", 30);
                set("material", "steel");
                set("wield_msg", "$N冷笑一声，从背后拔出了凤凰琴。\n");
                set("unwield_msg", "$N将手中的凤凰琴插回鞘中，嘴角多了一丝笑意。\n");

                set("anqi/allow", 1);
                set("anqi/max", 50);
                set("anqi/now", 0);
        }
        init_sword(660);
        setup();
}

