// yuenv-jian.c 越女剑法
// 取材：《射雕英雄传》韩小莹 + 《越女剑》阿青
// by Lonely

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
        "$N施展小巧腾挪之技，一招「白露横江」，招数轻灵翔动，$w横削$n$l",
        "$N忽发一招「电照长空」，便如电光急闪，青光闪闪，$w在$n身边刺来划去，招招不离要害",
        "$N左足一点，剑走轻灵，一招「凤点头」，身子微侧，$w疾刺$n$l，剑尖光芒闪动，又狠又准，的是精微招数",
        "$N展开轻灵身法，绕着$n滴溜溜地转动，$w递出，一招「枝击白猿」，跃身半空连挽两个平花，倏然回剑下削",
        "$N身子拗转，一个「翻身探果」，下盘不动，上盘不避，将腰向左一挪，斗然移开半尺，右手$w直撩向$n",
        "$N左手捏个剑诀，剑随身走，右足绕前，$w「探海斩蛟」，回锋下插，径攻$n下盘，剑法极为精奇",
        "$N左膝一低，曲肘竖肱，一招「起凤腾蛟」，刷的一声，$w猛撩上来",
        "$N圈转$w，右足曲为前弓，左手捏着剑诀，右手平膀顺肘，横剑向$n急推，于锋锐之中另蕴复杂变化，正是「十万横磨」之势",
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{

        if (me->query("gender") != "女性")
                return notify_fail("你练来练去觉得这个剑法还是适合女性练习！\n");

        if ((int)me->query_skill("dodge", 1) < 200)
                return notify_fail("你的轻功火候不到，无法运用越女剑术。\n");

        if ((int)me->query_skill("sword", 1) < 200)
                return notify_fail("你的剑术功底不行，难以领会越女剑术。\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力太差，无法学习越女剑术。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("yuenv-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的越女剑术。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 150 + random(50),
                "attack": 80 + random(10),
                "dodge" : 80 + random(10),
                "parry" : 80 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 90)
                return notify_fail("你的体力不够练越女剑术。\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("你的内力不足以练越女剑术。\n");

        me->receive_damage("qi", 74);
        me->add("neili", -75);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yuenv-jian/" + action;
}

int query_effect_parry(object attacker, object me) 
{
        int lvl;
        if (! objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("yuenv-jian", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

mixed hit_ob(object me, object victim, int damage_bonus, int i, int attack_time)
{
        object weapon;
        string name;
        int ap, dp;

        weapon = me->query_temp("weapon");

        attack_time = (int)(me->query_skill("yuenv-jian", 1) / 40);

        if (attack_time > 3)
                attack_time = 3;

        ap = me->query_skill("sword"); 
        dp = victim->query_skill("dodge");

        if (me->is_busy()
           || ! living(victim)
           || me->query("neili") < 200
           || ap * 3 / 5 + random(ap) < dp
           || me->query_temp("is_attacking")
           || me->query_skill_mapped("sword") != "yuenv-jian"
           || me->query_skill("yuenv-jian", 1) < 120)
                return 0;
        
        message_vision(HIW "\n霎那间，只见$N" HIW "手中" + weapon->name() + HIW "轻盈灵动"
                       "，优美华丽，不带一丝尘俗之气，却将$n" HIW "攻得无暇反击！\n"
                       NOR, me, victim);

        me->set_temp("is_attacking", 1);
        me->start_busy(1 + random(attack_time / 2));
        me->add("neili", -attack_time * 20);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(victim))
                        break;

                if (! victim->is_busy() && random(2))
                        victim->start_busy(1);

                COMBAT_D->do_attack(me, victim, weapon, 0);
        }

        me->delete_temp("is_attacking");
        return 1;
}

