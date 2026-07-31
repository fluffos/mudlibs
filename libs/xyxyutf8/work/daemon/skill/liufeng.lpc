// Liufeng.c 流风回雪步
// Cracked by 凌惊雪 4-1-2003

inherit SKILL;

string *dodge_msg = ({
	"$n一招「秋风起兮白云飞」轻轻巧巧地避了开去。\n",
	"只见$n身影一晃，一式「草木黄落兮雁南归」早已避在七尺之外。\n",
	"$n使出「兰有秀兮菊有芳」，轻轻松松地闪过。\n",
	"$n左足一点，一招「怀佳人兮不能忘」腾空而起，避了开去。\n",
	"可是$n使一招「泛楼船兮济汾河」，身子轻轻飘了开去。\n",
	"$n身影微动，已经藉一招「横中流兮扬素波」轻轻闪过。\n",
	"但是$n一招「箫鼓鸣兮发棹歌」使出，早已绕到$N身後！\n",
        "但是$n身形飘忽，轻轻一纵，一招「欢乐极兮哀情多」，避开这一击。\n",
        "$n身形往上一拔，一招「少壮几时兮奈老何」，一个转折落在数尺之外。\n",

});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	int i = (int)me->query_skill("liufeng", 1);
	int j = (int)me->query_skill("brightjade-force", 1);
	if ( me->query("family/family_name") != "百花谷")
		return notify_fail("你不是百花谷门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的明玉神功不够高深，强学小心走火入魔。\n");
	return 1;
}


string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	int i = (int)me->query_skill("liufeng", 1);
	int j = (int)me->query_skill("brightjade-force", 1);
	if ( me->query("family/family_name") != "百花谷")
		return notify_fail("你不是百花谷门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的明玉神功不够高深，强学小心走火入魔。\n");
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能练流风回雪步。\n");
	if( me->query_spi() < 50 )
		return notify_fail("你的灵性不足，无法自己修习流风回雪步。\n");
	me->receive_damage("sen", 30);
	return 1;
}
string perform_action_file(string func)
{
        return CLASS_D("baihuagu") + "/liufeng/" + func;
}