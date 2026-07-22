#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(MAG"青索剑"NOR,({ "qingsuo jian", "sword", "jian", "qingsuo" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 10000000000);
                set("rigidity", 3);
                set("sharpness", 3);
                set("unique", 1);
                set("material", "steel");
                set("wield_neili", 200);
                set("wield_maxneili", 1000);
                set("wield_str", 22);                
                set("long", "此剑名为青索，蛟皮鞘，金吞口，玉为柄，珠作饰，乃是先朝帝王宫藏利器之一，为剑之上品！\n"); 
                set("wield_msg", "$N伸指轻轻在$n一弹，竟然发出一阵龙吟，剑身来回不停地抖动，如有生命一般！\n");
                set("unwield_msg", "$N挽了一个剑花，右手轻摆，已将$n插回腰间剑鞘。\n");
        }
        init_sword(150);
        setup();
}
