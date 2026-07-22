inherit SKILL;
mapping *action = ({
    ([  "action":       "$N使一招「"+HIY+"拟把疏狂"+CYN+"图一醉"+NOR+"」，手中$w向$n的$l连斩七刀！",
        "damage":       200,
        "dodge":        200,
        "damage_type":  "割伤"
    ]),
    ([  "action":       "$N身随意转，$w随著一招「"+YEL+"衣带"+RED+"渐宽终不悔"+NOR+"」由下而上撩往$n的$l",
        "damage":       400,
        "damage_type":  "割伤"
    ]),
    ([  "action":       "$N身形一转，一招「"+WHT+"为伊消得人憔悴"+NOR+"」$w刀光不定，斩向$n的$l",
        "damage":       200,
        "damage_type":  "割伤"
    ]),
    ([  "action":       "$N舞动$w，一招「"+HIW+"伫倚危楼风细细"+NOR+"」迅捷无伦地劈向$n的$l",
        "damage":       200,
		"damage_type":  "割伤"
    ]),
    ([  "action":       "$N手中$w一晃，一招「"+HIB+"无言谁会凭栏意"+NOR+"」往$n的$l斜斜砍出一刀",
        "damage":       400,
        "damage_type":  "割伤"
    ]),
    ([  "action":       "$N提刀过肩，蓄劲发力，一招「"+HIG+"草色烟光残照里"+NOR+"」直劈$n$l",
        "damage":       400,
        "damage_type":  "割伤"
    ]),
    ([  "action":       "$N大喝一声，使天罡地煞刀法中最后一招「"+BLU+"天罡地煞"+NOR+"」$w有如一弯彩虹斩向$n的$l",
        "damage":       300,
        "damage_type":  "割伤"
    ]),
});
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("blade", 1) <=me->query_skill("tiangang-blade", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
int valid_enable(string usage)
{
    return (usage=="blade") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
    object weapon;
    if( !objectp(weapon = me->query_temp("weapon"))
    ||  (string)weapon->query("skill_type") != "blade" )
        return notify_fail("你必须先找一把刀，才能练刀法。\n");
    if( (int)me->query("qi") < 40 )
        return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
    me->receive_damage("qi", 40);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
    if( random(me->query_str()*2) > victim->query_str() ) {
        victim->receive_wound("qi", (damage_bonus - 100) / 2 );
        return HIR "你只觉的阵阵刀风，扑面而来，紧跟着是一声惨嚎!n" NOR;
    }
}

