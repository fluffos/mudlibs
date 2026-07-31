#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("柔金锋", ({"roujing sword", "sword", "jian"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "iron");
                set("long", "一柄细长的剑,闪着暗黑的光。\n");
                set("wield_msg", "$N抽出一柄细长的$n握在手中。\n");
                set("unequip_msg", "$N一抖手将手中的$n收入长袖之中。\n");
        }
        init_sword(150);
        setup();
}

