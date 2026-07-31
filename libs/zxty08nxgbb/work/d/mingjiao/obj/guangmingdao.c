// guangmingdao.c 

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("光明刀", ({ "guangming dao", "dao" }));
        set_weight(6000);
        set("unique", 1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄明教弟子的精钢练成的钢刀！刀面明晃晃的似乎有一重血色。\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
        init_blade(40);
        setup();
}
