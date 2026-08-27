// gangjian.c

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("鋼劍", ({ "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "這是一柄精工制成的鋼劍，這種劍在將領之間非常流行。\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回劍鞘。\n");
        }
        init_sword(30);
        setup();
}
