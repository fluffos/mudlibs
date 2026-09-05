// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("碎金刀", ({ "suijin dao","dao" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄碎金刀，只有用它才能削动星宿后山的千年古木。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
        init_blade(1);
        setup();
}

