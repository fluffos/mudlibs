#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( MAG "紫月剑" NOR, ({ "ziyue sword", "sword" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "\n");
                set("value", 38000);
                set("material", "sapphire");
                set("wield_msg", "$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon_prop/courage", 15);
                set("weapon_prop/intelligence", 20);
                set("weapon_prop/personality", 10);
                set("rigidity", 40);
//                set("replica_ob", "/obj/longsword");
        }

        init_sword(650);
        setup();
}

