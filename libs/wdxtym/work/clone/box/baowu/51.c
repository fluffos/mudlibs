#include <weapon.h>
#include <ansi.h>

inherit BLADE;



void create()
{
        set_name(GRN "绿波香露刀" NOR, ({ "xianglu dao", "lvbo", "xianglu", "dao" }));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", GRN "一柄碧绿色的鬼头刀，刀身散发出一阵腥臭，让"
                            "人闻了几欲作呕。\n" NOR);
                set("unit", "把");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("unwield_msg", GRN "$N" GRN "抹了抹汗，将手中所握的绿波"
                            "香露刀收回。\n" NOR);
                set("stable", 100);
        }
        init_blade(680);
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill("blade") < 150)
                return damage_bonus / 2;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 10 + 2);
                return GRN "$N" GRN "绿波香露刀连连挥斩，化作一道道绿芒，$n"
                       GRN "只觉一股香气扑鼻而来，不敢大意，当\n即凝神闭气，"
                       "招架顿时散乱。\n" NOR;
        case 1:
                n = me->query_skill("blade");
        victim->receive_damage("jing", me->query("str") );
        victim->receive_wound("jing", me->query("str") );
                return GRN "$N" GRN "绿波香露刀连连挥斩，化作一道道绿芒，$n"
                       GRN "只觉一股香气扑鼻而来，微一诧异，顿\n时已吸入数口"
                       "毒气。\n" NOR;
        }
        return damage_bonus;
}

