// yanling-shenfa.c 燕灵身法

inherit SKILL;

string *dodge_msg = ({
"$n一式「单燕南飞」，左脚脚尖垫起，右脚凌空发力，身体如行云流水般滑出丈余。\n",
"$n一式「一叶障目」，身行旋转，双脚跋地而起，顿时闪过了$N的凌厉攻势。\n",
"$n一式「双燕分飞」，左右双足凌空踢出数脚，顿时落到$N的上空。\n",
"$n一式「燕子出巢」，突然间身行前扑，象利箭般的冲向$N，令$N手无足措。\n",
"$n一式「余音绕梁」，真气布满全身，围着$N急速旋转，令$N手忙脚乱，$n已落到几丈远的地方。\n",
"$n一式「走马看花」，双足凌空点地，在剌剌风声中，从$N头顶横跃而过。\n",
"$n一式「燕子回头」，双手力发劈空掌，借力身行上飘，霎时间躲过$N的凌厉攻势。\n",
"$n一式「燕南归巢」，身体如陀螺般急转，气流形成一个个漩涡，令$N陷身其间。\n",
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me)
{
	if ( me->query_skill("shenyuan-gong", 1) < 10)
		return notify_fail("你的神元功等级太低了。\n");
	return 1;
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练燕灵身法。\n");
	me->receive_damage("jingli", 25);
	return 1;
}
