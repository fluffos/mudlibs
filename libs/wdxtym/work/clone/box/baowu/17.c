#include <weapon.h>
#include <ansi.h>

inherit HAMMER;


void create()
{
        set_name(NOR + YEL "黄金斧" NOR, ({"huangjin fu", "huangjin", "fu"}));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "这是一柄纯金黄铸造的大斧，斧柄末端似乎有些松动。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "gold");
                set("wield_msg", YEL "$N" YEL "举起一柄纯黄所铸的大斧，随手挥舞了两下。\n" NOR);
                set("unwield_msg", YEL "$N" YEL "哈哈一笑，将手中的黄金斧收回背后。\n" NOR);
                set("stable", 100);
        }
        init_hammer(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;



        switch (random(6))
        {
        case 0:
                n = me->query_skill("hammer");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return YEL "$N" YEL "一声断喝，手中黄金斧霎时金芒暴涨，呼的一声朝$n"
                       YEL "猛劈而去！\n" NOR;
        }
        return damage_bonus;
}
