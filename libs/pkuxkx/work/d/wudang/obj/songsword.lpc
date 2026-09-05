// longsword.c 配剑/peijian.c
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("宋青书的佩剑", ({ "pei jian", "jian" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄锐气逼人的精钢宝剑，宋青书自小配这把宝剑，从不离身。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(45);
        setup();
}
