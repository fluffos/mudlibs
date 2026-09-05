inherit SKILL;
mapping *action = ({
([      "action" : "$N提腰跃落，刀锋一卷，迅猛无比斩向$n的$l",
        "dodge" : 15,
        "damage" : 180,
        "skill_name" : "迅猛无比",
        "damage_type" : "割伤"
]),
([      "action" : "$N右脚跃步落地，$w顺势往前，劈向$n的$l",
        "dodge" : 35,
        "damage" : 200,
        "skill_name" : "顺式而劈",
        "damage_type" : "割伤"
]),
([      "action" : "$N反挥$w，刀锋倒卷劈向$n的$l",
        "dodge" : 35,
        "damage" : 160,
        "skill_name" : "弟弟大大",
        "damage_type" : "割伤"
]),
([      "action" : "$N一舞刀花，手中$w已向$n的全身涌去",
        "dodge" : 30,
        "damage" : 180,
        "skill_name" : "舞花涌身",
        "damage_type" : "割伤"
]),
});
int valid_enable(string usage) { return usage == "blade" ||usage=="dodge"|| usage == "parry"; }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        return 1;
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练快刀十三式。\n");
        me->receive_damage("qi", 25);
        return 1;
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
string *dodge_msg = ({
        "不料$n三晃两晃，晃到了$N的身后，躲开了这一招。\n",
        "却见$n纵身跃起数尺，躲开了$N的攻击。\n",
        "可是$n身随意转，倏地往一旁挪开，避过了这一击。\n",
        "情急之下$n身形微晃，有惊无险地避开了$N这一招。\n"
});
mapping query_action(object me)
{
        return action[random(sizeof(action))];
}
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string query_dodge_msg(object weapon)
{
                return dodge_msg[random(sizeof(dodge_msg))];
 }

string query_yinyang()
{
	return "少阳";
}