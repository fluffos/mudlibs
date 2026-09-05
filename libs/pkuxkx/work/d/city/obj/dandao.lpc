#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("单刀", ({ "dan dao","dao","blade" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄亮晃晃的单刀，是江湖上常见的武器。\n");
                set("value", 500);
                set("material", "steel");
                set("of_killer",1);
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
        init_blade(40);
        setup();
}
