//qin.c
//God edit by 2005.6
#include <ansi.h>
#include <weapon.h>

inherit QIN;

void create()
{
        set_name(MAG"妖红琴"NOR, ({"yaohong qin" , "qin"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","此琴一入你手，弦自己轻轻颤动，好像找到知音一般。\n");
                set("unit", "副");
		set("wield_msg",
 "$N脸色一变，从腰后一伸手，一把妖红妖红的琴已经出现在了$N腿上，$N一抚琴弦，一股杀气顿时弥漫开来！\n");
		set("unwield_msg",
"$N弹奏完毕，脸色舒展了不少，手一招，琴已不知去向。\n");
                set("value", 50000);
		set("weapon_prop/courage", 10);
        }
        init_qin(110);
        setup();
}
