#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N一式宽衣解带，不是脱衣，胜似脱衣，双拳挥向$n的$l",
                "dodge":                -30,
                "parry":                50,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形一转，右拳自下而上撩向$n的$l",
                "dodge":                -40,
                "parry":                100,
                "force":                120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双足一顿，连人带拳扑至$n身前，以迅雷不及掩耳之势击向$n的$l",
                "dodge":                -30,
                "parry":                120,
                "force":                190,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N猛一转身，背对$n，右肘向$n的$l猛击",
                "dodge":                -50,
                "parry":                200,
                "force":                290,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练病维摩拳必须空手。\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }
int effective_level() { return 20;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("neili") < 5 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
 

string *parry_msg = ({
        "$n伸出一指，轻轻一拨$N的$w，$w调转头去，向$N反噬过去！\n",
	"$n一按$N的$w，整个人已经从$N的头顶飞越而过，轻轻巧巧落在$N身后！\n",
	"$n深吸一口气，就象粘在$N的$w上一样。\n",
        "$n身子微微一侧，已躲开$N的攻势。\n",
        "$N眼前一花，手中的$w好象击在了虚处，仔细一看，$n站在原地没有动过。\n",
});

string *unarmed_parry_msg = ({
        "$n身子微微一侧，已躲开$N的攻势。\n",
        "$n一招「围魏救赵」，不退反进，击向$N，逼得$N回招自保。\n",
	"$n双拳错落，护住全身要害。\n",
        "$N眼前一花，所有的招式好象击在了虚处，仔细一看，$n站在原地没有动过。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 30;
}
string perform_action_file(string action)
{
        return __DIR__"ill-quan/" + action;
}