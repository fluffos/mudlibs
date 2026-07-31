#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG "神农锏" NOR,({ "shennong jian", "shennong", "jian", "staff" }) );
        set_weight(3800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "一柄看似普通的药锄，柄上刻着“神农”二字。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "拔出神农锏握在手里，四周空气中"
                                 "顿时充满浓厚的草药香味。\n" NOR);
                set("unwield_msg", HIG "$N" HIG "哈哈一笑，将神农锏收回。\n" NOR);
                set("stable", 100);
        }
        init_staff(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        switch (random(8))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("staff") / 12 + 2);
                return HIG "$N" HIG "将手中神农锏急速挥舞转动，一股刺鼻的气味"
                       "顿时扑面而来，$n" HIG "见状连忙后退！\n" NOR;

        case 1:
                n = me->query_skill("staff");
                victim->receive_damage("qi", n * 2 / 3);
                victim->receive_wound("qi", n * 2 / 3);
                return HIG "$N" HIG "身形如鬼魅般飘出，手中神农锏一阵乱舞，犹"
                       "如千百根相似，$n" HIG "见状不由心生畏惧，只能够勉强作"
                       "出抵挡！\n" NOR;
        }
        return damage_bonus;
}


