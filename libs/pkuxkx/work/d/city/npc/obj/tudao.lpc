#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("屠刀", ({ "tu dao","dao","blade" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄亮晃晃的屠刀，是用杀畜生用的，比如猪、牛什么的。\n");
                set("value", 500);
                set("material", "steel");
                set("of_killer",1);
                set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放回了刀鞘。\n");
        }
        init_blade(30);
        setup();
}
