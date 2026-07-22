// guangmingjian.c 

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("光明剑", ({ "guangming jian", "jian" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄明教弟子的精钢剑，上面刻着“剑在人在，剑亡人亡”八个字。\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(40);
        setup();
}

