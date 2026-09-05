// bingcan-zhang.c based on xianglong-zhang.c
// by henry
inherit SKILL;
mapping *action = ({
([      "action": "$N似是猝不及防，一个踉跄，胸口被$n击中,$N的一腔寒气迸涌而出",
        "dodge": 30,
        "force": 180,
//      "poison": 80,
        "damage_type": "冻伤"
]),
([      "action": "$N双掌漫无目的的拍出，顿时天地间弥漫一翻彻骨寒气，$n身形凝住，无法递招",
        "dodge": 10,
        "force": 190,
//      "poison": 60,
        "damage_type": "冻伤"
]),
([      "action": "$N运起「易筋经」所载奇妙内功，气凝肩头，飞身撞向$n的$l",
        "dodge": -20,
        "force": 300,
        "damage": 20,
//      "poison": 100,
        "damage_type": "内伤"
]),
([      "action": "$N双掌挟着一股寒气拍向$n的$l",
        "dodge": 10,
        "force": 190,
//      "poison": 80
        "damage_type": "瘀伤"
]),
});
   
   int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练冰蚕掌必须空手。\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("你的化功大法火候不够，无法练冰蚕掌。\n");
        if ((int)me->query("max_neili") < 60)
                return notify_fail("你的内力太弱，无法练冰蚕掌");
        return 1;
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练冰蚕掌。\n");
        if (me->query_skill("bingcan-zhang", 1) < 50)
                me->receive_damage("qi", 20);
        else
                me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("beiming-shengong")) > 5) {

			F_POISON->poison_attack(me,victim,"bc_poison", random(2) + 2 +
                        victim->query_condition("bc_poison"));
        }
}
string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});
string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
