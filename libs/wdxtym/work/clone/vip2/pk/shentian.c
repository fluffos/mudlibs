#include <ansi.h>

inherit ITEM;

int is_reform_ob() { return 1; }
void create()
{
        set_name(HIW "永恒之恋" NOR, ({"yong heng", "zhi", "lian"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "仙级材料。\n"
                            "传说永恒之恋是天地间最纯洁的爱情象征，\n"
                              "传说其拥有强大的力量。\n" NOR);
                set("unit", "块");
                set("yuanbao", 2000);
				set("value", 8000000);
                set("item_origin", 1);
                set("element", "water");
                set("material_attrib", "zhi lian");
                set("material_name", HIW "永恒之恋" NOR);
                set("can_make", "all");
                set("power_point", 1000);
        }
}
