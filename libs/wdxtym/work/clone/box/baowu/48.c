#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY "腾龙剑" NOR, ({ "tenglong jian", "tenglong", "jian", "sword" }) );
        set_weight(5800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "一柄锋利的长剑，剑身宛如流水，隐隐漾着青光。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "唰的抽出一柄利剑握在手中，剑"
                                 "身青光荡漾，寒气逼人。\n" NOR);
                set("unwield_msg", HIY "$N" HIY "空舞了数个剑花，将腾龙宝剑"
                                 "插回腰间。\n" NOR);
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 16 + 2);
                return HIY "$N" HIY "手中腾龙剑一颤，漾起层层剑光，顿时将$n"
                       HIY "逼退数步！\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIY "只听得破空声骤响，$N" HIY "手中腾龙剑岚转不定，向"
                       "$n" HIY "连刺数剑！\n" NOR;
        }
        return damage_bonus;
}
