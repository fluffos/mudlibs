// zhongyuefeng.c 中岳神风

inherit SKILL;

string *dodge_msg = ({
"$n一式「风行中岳」，不退反进，全身忽地向前一纵，身行若风，恰好掠过$N的攻势。\n",
"$n忽然全身在空中一扭、一转，两腿一个平飞，一式「山舞狂风」，把$N的攻击卷入满天身影之中。\n",
"$n身形向上一飘，一只脚忽然轻踩在$N的身上，好一式「风在峻极」，遁在$N的身后。\n",
"$n换变身形，整个身躯向上一抬一落，一招「风起云落」，虚实之间化去了$N的招式。\n",
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me)
{
	if ( me->query_skill("hanbing-zhenqi", 1) < 10)
		return notify_fail("你的寒冰真气等级太低了。\n");
	return 1; 
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练习中岳神风。\n");
	me->receive_damage("jingli", 25);
	return 1;
}
