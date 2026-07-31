#include <weapon.h>
#include <ansi.h>

inherit SWORD;



void create()
{
        set_name(HIY "真武剑" NOR,({ "zhenwu jian", "jian", "sword", "zhenwu" }) );
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
这是一柄寒光闪闪的宝剑，昔年武当张真人持此剑荡妖除魔，扫尽群丑。
江湖宵小，见此剑无不心荡神摇。
LONG );
                set("unit", "把");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(4))
        {
        case 0:
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIC "$N" HIC "跨前一步，手中的" NOR + HIY "真武剑" NOR
                       + HIC "幻化成无数圆圈，向$n" HIC "逼去，剑法细密之极。"
                       "$n" HIC "大吃一\n惊，不知如何抵挡，只有连连后退！\n" NOR;

        case 1:
                n = me->query_skill("sowrd");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                n = victim->query("eff_jing");
                n /= 2;
                victim->receive_damage("jing", n);
                victim->receive_wound("jing", n / 2);
                return random(2) ? HIY "$N" HIY "一声长吟，手中的真武剑化作一"
                                   "到长虹，“唰”的扫过$n" HIY "而去！\n" NOR:
                                   HIY "$N" HIY "突然大声喝道：“邪魔外道，还"
                                   "不受死？”手中真武剑" HIY "忽的一抖，$n"
                                   HIY "登时觉得眼花缭乱！\n" NOR;
        }

        // double effect
        return damage_bonus;
}


