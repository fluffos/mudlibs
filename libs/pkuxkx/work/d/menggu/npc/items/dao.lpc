// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("马刀", ({"ma dao", "blade","dao" }));
        set_weight(6500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄马刀，草原勇士的常用武器。\n");
                set("value", 3500);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
        init_blade(30);
        setup();
}
