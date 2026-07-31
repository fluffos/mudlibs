// xuantie jian 玄铁重剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"精钢重剑"NOR,({ "jinggang jian", "jinggang", "jian", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 10);
                set("unique", 1);
                set("rigidity", 10);
                set("sharpness", 1);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -12);
                set("wield_neili", 1500);
                set("wield_maxneili", 2100);
                set("wield_str", 32);
                set("long", "这是一柄亮晃晃的精钢重剑。\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");       
        }
        init_sword(600);
        setup();
}
