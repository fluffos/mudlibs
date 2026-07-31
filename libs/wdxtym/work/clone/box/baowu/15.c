#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIR "鹤形笔" NOR,({ "hexing bi", "hexing", "bi" }) );
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "一支通体红色的毛笔，呈鹤形，看上去是件利器。\n" NOR);
                set("unit", "支");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIR "$N" HIR "从腰间取出一支鹤形笔拿在手中。\n" NOR);
                set("unwield_msg", HIR "$N" HIR "一声轻哼，将手中鹤形笔放回腰间。\n" NOR);
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIR "$N" HIR "手中鹤形笔急速转动，将$n" HIR "团团围住！\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 5);
                victim->receive_wound("qi", n * 3 / 5);
                return HIR "$N" HIR "一声怒喝，手中鹤形笔猛地连续刺向$n" HIR "！\n" NOR;
        }
        return damage_bonus;
}
