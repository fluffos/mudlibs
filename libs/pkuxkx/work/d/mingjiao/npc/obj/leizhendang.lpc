// leizhendang.c by binlang
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("雷震挡", ({ "leizhendang", "hammer" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄特别重的雷震挡。\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拎起一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放下。\n");
        }
        init_hammer(30);
        setup();
}
