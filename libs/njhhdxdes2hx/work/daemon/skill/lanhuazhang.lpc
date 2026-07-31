
inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「春晖开禁苑」，对准$n的$l轻飘飘的扫去",
		"dodge":		-20,
		"parry":		20,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N扬起右手，一招「淑景媚兰场」便往$n的$l拍去",
		"dodge":		-10,
		"parry":		10,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左手虚晃，右手「映庭含浅色」往$n的$l击出",
		"dodge":		-20,
		"parry":		20,
		"damage_type":	"瘀伤"
	]),
        ([      "action":               "$N左手微分，右手一长使出一招「凝露玄浮光」，抓向$n的$l",
                "dodge":                -50,
                "parry":                -30,
                "force":                100,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               "$N倏地一个转身，双手一挑「日丽参差影」直掼$n$l",
                "dodge":                -10,
                "parry":                -60,
                "force":                110,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左手虚晃，右掌飘飘，一招「风传轻重香」击向$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               "$N右手在$n$l划过，随後一招「会须群子折」左爪又向同一方位抓到",
                "parry":                -50,
                "force":                60,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               "$N左手虚晃，右手握成拳，一招「佩里作芬芳」击向$n$l",
                "dodge":                -20,
                "parry":                -50,
                "force":                150,
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练兰花掌必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$n一招「幽香洁浅紫」，右手轻拂$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n右手虚幌，左手一招「来自孤云岭」，逼得$N后退三步。\n",
        "$n以守为攻，一招「骨香不自知」，轻拂$N握$w的手腕。\n",
        "$n一招「色浅意殊深」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n一招「诗里称名友」，逼得$N中途撤招。\n",
        "$n脚走阴阳，一招「花中占上游」，攻$N之必救。\n",
        "$n左手拂下，右手一招「风来香细细」，将$N封于尺外。\n",
        "$n双手齐出，使出一招「何独是嘉州」，$N的功势入泥牛入海，消失得无影无踪。\n",

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
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 30;
}

