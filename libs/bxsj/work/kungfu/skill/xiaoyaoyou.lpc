// xiaoyaoyou.c
// rebuild by Lklv

inherit SKILL;

string *dodge_msg = ({
"$n身形跃起，一个「蜻蜓点水」，有惊无险地躲过了$N这一招。\n",
"$n向后一纵，使出一招「细胸巧翻云」，刚好避过了$N的攻击。\n",
"$n施展开逍遥游身法，使出「虚怀若谷」，恰好躲过了$N的攻势。\n",
"$n默念逍遥游要诀，使出「鹏徙南冥」纵身跃起，闪过$N的攻势。\n",
"$n一式「怒而飞」，身形如大鹏般高高拔起，轻轻落在$N的身后。\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge");
}

int valid_learn(object me)
{
	if ( me->query_skill("huntian-qigong", 1) < 10)
		return notify_fail("你的混天气功等级太低了。\n");
	if (me->query_skill("dodge", 1) < 10)
		return notify_fail("你的基本轻功不够，还无法学习逍遥游。\n");
	return 1;
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练逍遥游。\n");
	me->receive_damage("jingli", 25);
	return 1;
}
