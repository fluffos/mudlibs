// yuxue-dunxing.c 御雪遁形
// by iceland

inherit SKILL;

string *dodge_msg = ({
"$n一招「雁独行」，双臂平伸，借势一个空心筋斗向后倒翻出去。\n",
"$n见状曲膝俯身以手撑地，使出一招「鱼潜」，双足一点，箭一般从$N腋下蹿了过去。\n",
"$n平地带起一阵旋风，一招「狸翻」，跃起在空中几个横滚，$N的招数被化于无形。\n",
"$n斜斜的倒退几步，突然探手在$N肩上一按，使出一招「鹰千里」，已经从$N头顶越过。\n",
"$n使出一招「蛇游」，身体左摇右摆，飘忽不定，脚下毫无章法，$N的招数却差之毫厘，一一落空。\n",
"$n纵声清啸，双掌在地下一拍，气流激动之下，一招「龙巡」冲天而起。\n",
});

int valid_enable(string usage) { return usage == "dodge"; }

int valid_learn(object me)
{
	if ( me->query_skill("longxiang-boruo", 1) < 10 )
		return notify_fail("你的龙象般若功等级还不够。\n");
	return 1;
}

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if ( me->query("jingli") < 30 )
		return notify_fail("你的体力太差了，不能练习御雪遁形。\n");
	me->receive_damage("jingli", 25);
	return 1;
}
