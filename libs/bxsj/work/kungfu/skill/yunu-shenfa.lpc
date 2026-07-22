// yunu-shengfa.c 玉女身法
#include <ansi.h>;
inherit SKILL;

string *dodge_msg = ({
HIW"$n一招「洛神凌波」，长袖舞动，掩住身形去处，轻飘飘腾身丈外，躲过了$N这一招。\n"NOR,
HIR"$n嫣然一笑，风姿绝代，$n已借这「一笑倾国」之势，避开了$N的凌厉攻势。\n"NOR,
HIM"$n使出「贵妃醉酒」，满面红晕，脚步踉跄中已饶至$N的身后。\n"NOR,
HIC"$n左足点地，眼看$N杀招堪堪袭来，一招「红拂夜奔」，身躯已借势平移，闪过一旁。\n"NOR,
MAG"$n一式「绿珠坠楼」，身体贴地滑行，真叫人匪夷所思，令$N的攻击已然扑空。\n"NOR,
});

int valid_enable(string usage) { return (usage == "dodge"); }

int valid_learn(object me)
{
	if ( me->query_skill("yunu-xinjing", 1) < 10)
		return notify_fail("你的玉女心经等级不够，无法领悟玉女身法的要诀。\n");
	return 1;
}

string query_dodge_msg(object me)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if((int)me->query("jingli") < 30 )
		return notify_fail("你该休息一下了，等会再练玉女身法吧。\n");
	me->receive_damage("jingli", 25);
	return 1;
}

mapping query_action(object me, object weapon)
{
	int level,out;
	level   = (int) me->query_skill("yunu-shenfa",1);
	out = (stringp(environment(me)->query("outdoors"))?1:0);
	if(me->query("family/family_name")!="古墓派")
		return ([
			"action":dodge_msg[random(sizeof(dodge_msg))], 
			"dodge": -level/3,
		]);
	if(me->query("gender") == "男性")
		return ([
			"action":dodge_msg[random(sizeof(dodge_msg))],
			"dodge": level/3 + me->query_con() - out*level/5,
		]);
	else
		return ([
			"action":dodge_msg[random(sizeof(dodge_msg))],
			"dodge": level/2 + me->query_per()*4 - out*level/5,
		]);
}
