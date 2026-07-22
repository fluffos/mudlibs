// xinyuegong.c 星月功

inherit SKILL;

string *dodge_msg = ({
"似乎$N每一招都能制$n的死命，可是$n总是或反打、或闪避，一一拆解开去。\n",
"却见$n一低头，从$N底下扑了上去，左臂随势格向$n的右臂。\n",
"那知$n身形一幌，轻轻巧巧地避过了$N的攻击。\n",
"$n飞起右足，踢向$N手腕，一招「叶底飞燕」反攻为守\n"
});

string  *msg = ({
"$N使上半招「星月争辉」，左手$w打向$n胸腹之交的「商曲穴」，出招准备无误",
"$N使下半招「星月争辉」，左手$w弯过来打向$n背心的「灵台穴」，出招准备无误",
"$N出招「星月争辉」，左右连打，虽只一招，但其中包含著手劲眼力、荡器认穴的各种法门",
"$N不管三七二十一，$w挥出，惶急之下，这一招「星月争辉」只使对了一半，倒还是准确打向$n胸口的「商曲穴」",
"$N又是一招『声东击西』，左手一扬，$n向右一闪，那知这一下却是虚招，$w跟著疾劈而下击向$n$l",
"$N突然抢到$n左首，左肘後挺，撞向$n的腰间",
"$N飞起右足，踢向$n的手腕，这一招「叶底飞燕」是华辉的绝招之一，厉害非凡",
"$N左臂一格$n的右臂，将他招数掠向外门，双手已抓住$w，一拔一送，打向$n$l"
});

int valid_enable(string usage)
{
	return usage == "hammer" || usage == "parry" 
	|| usage == "dodge" || usage == "staff" 
	|| usage == "stick" || usage == "club";
}

mapping query_action(object me, object weapon)
{
	return ([
		"action":	msg[random(sizeof(msg))],
		"damage":	60 +random(100),
		"damage_type":	random(2)?"砸伤":"瘀伤",
		"dodge":	random(30),
		"parry":	random(30),
		"force":	150+random(300)
        ]);
}

string query_dodge_msg(object weapon)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	return notify_fail("NPC武功，不对玩家开放。\n");
}
