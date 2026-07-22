// zhaixingshu.c 摘星术

inherit SKILL;

string *dodge_msg = ({
"$n一招「飞天摘星」，身体腾空，避过了$N的攻击。\n",
"$n纵身一跃，飞过$N的头顶，躲过了$N的攻势，正是一招「飘然出尘」。\n",
"$n使出「天狼食日」，一个翻滚，恰好躲过了$N的攻击。\n",
"$n一声狂啸，使出「河东狮吼」，在$N神色慌张时远远纵身退开。\n",
"$n一招「紫衣黯然」，低呼一声，突然间身形一幌，避过了$N的攻势。\n",
});

int valid_enable(string usage) 
{ 
	return usage == "dodge"; 
}

int valid_learn(object me)
{
	if ( me->query_skill("huagong-dafa", 1) < 10)
		return notify_fail("你的化功大法等级太低了。\n");
	return 1; 
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练摘星术。\n");
	me->receive_damage("jingli", 25);
	return 1;
}
