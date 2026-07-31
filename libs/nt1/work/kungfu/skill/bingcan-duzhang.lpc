// bingcan-duzhang.c  冰蚕毒掌
// by Lonely

#include <ansi.h>
inherit SKILL;

string *action_msg = ({ 
        "$N脸上露出诡异的笑容，双掌携满寒霜，横扫$n",
        "$N仰天一声长啸，聚集全身的力量击向$n",
        "$N诡异的一笑，双掌带着凌厉的寒气拍向$n的$l",
        "$N脸色变的煞白，看似平常的向$n$l推了一掌",
        "$N使出全力双掌向$n齐推，架式平常无齐，破窄百出.",
        "$N将冰蚕寒毒运转周身，掌力无招无式但却威猛无比地向$n的$l袭去",
        HIW "$N" + HIW "将体内所有" + HIR "冰蚕" + HIC "寒毒" + HIW"运象双掌掌心，\n只听" + 
        HIC "嗤" + HIW "的一声，一阵白色烟雾自你掌心暴射而出！攻向$n"+NOR"",
        "$N将冰蚕寒毒运至右手，阴毒无比地拍向$n的$l",
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }   

int valid_combine(string combo) { return combo == "bingcan-shenzhao"; }

mapping query_action(object me)
{
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "force": 320 + random(90), 
                "attack": 70 + random(10), 
                "dodge" : 70 + random(10), 
                "parry" : 70 + random(10), 
                "damage_type" : random(2) ? "瘀伤" : "内伤", 
        ]);
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练冰蚕神掌必须空手。\n");
        if ((int)me->query_skill("freezing-force", 1) < 10)
                return notify_fail("你的冰蚕寒功火候不够，无法练冰蚕神掌。\n");
        if ((int)me->query("max_neili") < 60)
                return notify_fail("你的内力太弱，无法练冰蚕神掌。");
        return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练冰蚕神掌。\n");
        if (me->query_skill("bingcan-duzhang", 1) < 50)
                me->receive_damage("qi", 60);
        else
                me->receive_damage("qi", 70);
                
        me->add("neili", -70);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("bingcan-duzhang", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("bingcan_duzhang",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 100 + random(lvl / 10) ])))
        {
                return HIW "$n" HIW "只感一阵极寒从心底升起，看来是中了$N" HIW "掌上的冰蚕寒毒。\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"bingcan-duzhang/" + action;
}

