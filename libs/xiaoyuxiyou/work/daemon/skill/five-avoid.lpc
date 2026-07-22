// Five-avoid.c 五行遁
// Cracked by 凌惊雪 4-22-2003

inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
	"可是$n微微一笑，$N眼前水雾弥漫，$n已使出"+HIC"『水遁』"NOR+"借水而逝。\n",
	"却见$n抛下手中兵刃，扑向路边的一棵大树，转眼和枝叶混为一体，\n$N茫然四顾，不知$n已经靠"+HIG"『木遁』"NOR+"躲开攻击。\n"
	"$n原地一转，立时钻入土中。$N这一招落到了空处，惊道"+HIY"『土遁』"NOR+"！\n",
	"$n随手打出一团火球，喝道"+HIR"『火遁』"NOR+"！ 整个人消失在火球中。\n",
	"$n哈哈一笑，把手中的兵刃交错一击，喝道“看我"+HIY"『金遁』"NOR+"”，突然精光耀眼，\n$N眼前一花，这一招不知落到了何处。\n",

});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	int i = (int)me->query_skill("five-avoid", 1);
	int j = (int)me->query_skill("wuzheng-force", 1);
	int k = (int)me->query_skill("bolomiduo", 1);
	if (j<k) j=k; 
	if ( me->query("family/family_name") != "散仙派")
		return notify_fail("你不是散仙派门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的无争心法或者婆罗蜜多心经不够高深，强学小心走火入魔。\n");
	return 1;
}


string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	int i = (int)me->query_skill("five-avoid", 1);
	int j = (int)me->query_skill("wuzheng-force", 1);
	int k = (int)me->query_skill("bolomiduo", 1);
	if (j<k) j=k; 
	if ( me->query("family/family_name") != "散仙派")
		return notify_fail("你不是散仙派门下，难以领会这门功夫的精髓。\n");
	if ( i >= j)
		return notify_fail("你的无争心法或者婆罗蜜多心经不够高深，强学小心走火入魔。\n");
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能练五行遁。\n");
        if( me->query_spi() < 35 )
		return notify_fail("你的灵性不足，无法自己修习五行遁。\n");
	me->receive_damage("sen", 30);
	return 1;
}
string perform_action_file(string func)
{
        return CLASS_D("sanxian") + "/five-avoid/" + func;
}
