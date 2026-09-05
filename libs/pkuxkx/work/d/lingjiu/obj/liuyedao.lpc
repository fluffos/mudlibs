#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("柳叶刀", ({ "liuye dao", "blade", "dao" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                 set("value", 2000);
                set("long", "这是一柄精钢打炼的柳叶刀，它形如柳叶，又薄又细，虽非宝刀，但也锋利异常。\n");
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
        }
        init_blade(20);
        setup();
}
