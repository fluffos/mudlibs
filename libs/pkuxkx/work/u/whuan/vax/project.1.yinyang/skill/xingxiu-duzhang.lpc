// xingxiu-duzhang.c, based on xianglong-zhang.c
// by yucao
// reedit by binlang
inherit SKILL;
mapping *action = ({
([      "action": "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
        "dodge": 30,
        "force": 180,
//      "poison": 80,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
        "dodge": 10,
        "force": 190,
//      "poison": 60,
        "damage_type": "瘀伤"
]),
([      "action": "$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l",
        "dodge": -20,
        "force": 200,
//      "poison": 100,
        "damage_type": "瘀伤"
]),
([      "action": "$N双掌挟着一股腥臭之气拍向$n的$l",
        "dodge": 10,
        "force": 190,
//      "poison": 80
        "damage_type": "瘀伤"
]),
});
   int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="zhaixing-shou"; }
mapping query_action(object me)
{
        if (random(me->query_skill("strike")) > 60 &&
            me->query_skill("force") > 50 &&
            me->query("neili") > 100 ) {
                me->add("neili", -100);
                return ([
                "action": "$N咬破舌尖，口中喷血，聚集全身的力量击向$n",
                "force": 330,
                "damage_type": "瘀伤"]);
        }
        return action[random(sizeof(action))];
}
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练星宿毒掌必须空手。\n");
        if ((int)me->query_skill("handu-xinfa", 1) < 10)
                return notify_fail("你的寒毒心法火候不够，无法练星宿毒掌。\n");
        if ((int)me->query("max_neili") < 60)
                return notify_fail("你的内力太弱，无法练星宿毒掌");
        return 1;
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练星宿毒掌。\n");
        if (me->query_skill("xingxiu-duzhang", 1) < 50)
                me->receive_damage("qi", 20);
        else
                me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("huagong-dafa")) > 5) {

             victim->apply_condition("xx_poison", random(2) + 2 +
                        victim->query_condition("xx_poison"));
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
string perform_action_file(string action)
{
         return __DIR__"xingxiu-duzhang/" + action;
}

string query_yinyang()
{
	return "太阴";
}