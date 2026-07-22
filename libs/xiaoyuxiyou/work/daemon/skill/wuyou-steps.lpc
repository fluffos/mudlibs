// Wuyou-steps.c 无忧步法
// Cracked by 凌惊雪 4-1-2003

inherit SKILL;

string *dodge_msg = ({
	"$n身形陡地变得飘忽不定，令$N无法看清。\n",
	"$n双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
	"$n如一阵清风，舒缓地闪过了$N的凌厉攻势。\n",
	"$n便如闲庭信步，在弹指间已然退出丈外。\n",
	"可是$n左一转，右一绕，身影已消失不见。\n",

});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	int i = (int)me->query_skill("wuyou-steps", 1);
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
	int i = (int)me->query_skill("wuyou-steps", 1);
	int j = (int)me->query_skill("brightjade-force", 1);
	if ( me->query("family/family_name") != "百花谷")
		return notify_fail("你不是百花谷门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的明玉神功不够高深，强学小心走火入魔。\n");
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能练无忧步法。\n");
	if( me->query_int() < 45 )
		return notify_fail("你的悟性不足，无法自己修习无忧步法。\n");
	me->receive_damage("sen", 30);
	return 1;
}
string perform_action_file(string func)
{
        return CLASS_D("baihuagu") + "/wuyou-steps/" + func;
}