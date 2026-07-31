// zileidao.c 地狱雷刀

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIC"地狱雷刀"NOR, ({"diyu leidao", "dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把紫色的大刀，刀锋锐利，吹毛而过。\n");
                set("value", 250);
                set("material", "gold");
                    set("no_sell", 1);
                set("wield_msg", MAG"$N「唰」地一声抽出一把$n"NOR+MAG"握在手中，紫雷暴鸣！\n"NOR);
                set("unwield_msg", MAG"$N将手中的$n"NOR+MAG"放下。\n"NOR);
        	set("weapon_prop/courage", 150);
        	set("replace_file", "/d/xiyou/sanjie/obj/jindao");

        }
        init_blade(800);
        setup();
}

