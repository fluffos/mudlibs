// By Batman @ Freedom Studio 2001/6/6

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"乾坤剑"NOR, ({ "qiankun sword","sword","jian" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "这是一把由"HIC"「天清」"NOR"和"MAG"「地宁」"NOR"组合成的神兵利器。\n");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", HIW"$N把$n握在了手里，四周立时变得死寂。\n"NOR);
                set("unwield_msg", HIW"$N把$n缓缓地归入剑鞘。\n"NOR);
                set("宝物",1);

                set("no_pawn", 1);
                set("breakup_object1", "/u/tod/obj/skysword.c");
                 set("breakup_object2", "/u/tod/obj/groundsword.c");
                set("breakup_msg", "双臂握剑，突发奇劲，大声喝道：「分！」，");
        }
        init_sword(150);
        setup();
}

