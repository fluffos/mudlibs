// huashan-ken.c 华山拳法
// Modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
    ([  "action": "$N使一招「云里乾坤」左拳击出，不等招式使老，"
		  "右拳已从左拳之底穿出，对准$n的$l「呼」地一拳",
	"dodge": 10,
	"parry": 20,
	"force": 40,
	"damage_type":  "瘀伤"
    ]),
    ([  "action": "$N左拳突然张开，拳开变掌，直击化为横扫，"
		  "一招「雾里看花」便往$n的$l招呼过去",
	"dodge": -5,
	"parry": 15,
	"force": 45,
	"damage_type":  "瘀伤"
    ]),
    ([  "action": "$N两手虎口相对，往内一圈，一招「金鼓齐鸣」"
		  "往$n的$l击出",
	"dodge": 15,
	"parry": 20,
	"force": 35,
	"damage_type":  "瘀伤"
    ]),
    ([  "action": "$N步履一沉，左拳虚晃一招，右拳使出「梅花"
		  "弄影」击向$n$l",
	"dodge": -10,
	"parry": -10,
	"force": 50,
	"damage_type":  "瘀伤"
    ]),
});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
	return notify_fail("练华山拳法必须空手。\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="unarmed" || usage=="parry";
}

int valid_combine(string combo) { return combo=="huashan-zhangfa"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 40 )
	return notify_fail("你的体力不够了，休息一下再练吧。\n");

    me->receive_damage("qi", 35);
    return 1;
}
