// By Batman @ Freedom Studio 2001/6/6

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(MAG"地宁"NOR, ({ "groundsword","sword","jian" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "这是一把古剑，剑鞘上的花纹成飞岩状，剑把上赫然刻着"MAG"「地宁」"NOR"。\n这是一把阴剑，和"HIC"「天清」"NOR"是一对。\n");
                set("value", 7000);
                set("material", "steel");
                set("wield_msg", MAG"突然间，四周都寂静了下来，$N腰间的「地宁」已然出鞘。\n剑身发散出的雾气令你觉得有些飘然。\n"NOR);
                set("unwield_msg", MAG"$N比了个剑势，将手中的「地宁」缓缓地归入剑鞘。\n"NOR);
                set("宝物",1);

                set("no_pawn", 1);
                set("combine_id", "skysword");
                set("combine_name", HIC"天清"NOR);
                set("combine_object", "/u/tod/obj/qksword.c");
                set("combine_msg", "合在一起，突然天地变色，一阵电光过后，双剑变成了");
        }
        init_sword(80);
        setup();
}

