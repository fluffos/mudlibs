// cracked by vikee 2/09/2002   vikee@263.net
// 晓风残月剑，qingyu-sword.c
// created 5-13-97 pickle

/*
晓风残月剑    dodge  -10    parry  0    damage  20
此剑法用意高妙，轻巧潇洒，剑中颇含诗意，多为江湖
年少所喜。
*/

// 皓月当空，水银泄地，花明月暗，清雨朦胧
// 飞花似梦，丝雨如愁，潇湘夜雨，月白风清
// 金波低转

inherit SKILL;

mapping *action = ({
	([	"name":			"皓月当空",
		"action":
"$N轻飘飘地纵身跃起，手中$w划出一个白色光环，向$n的$l圈去",
		"dodge":		-15,
		"parry":		10,
		"damage":		20,
		"damage_type":		"割伤"
	]),
	([	"name":			"水银泄地",
		"action":
"$N双脚一顿，笔直跃起，手中$w不停地颤抖着，\n"
"笼罩住$n全身。这势「水银泄地」果然防不胜防",
		"dodge":		-5,
		"parry":		-10,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
	([	"name":			"花明月暗",
		"action":
"$N手中$w带起点点银光，指向$n前胸穴道。$n正专心致志地对付着剑招，\n"
"不料$N左手运力拍向$n的$l。这势「花明月暗」亦真亦幻，实是难防",
		"dodge":		-5,
		"parry":		-5,
		"damage":		25,
		"damage_type":		"震伤"
	]),
	([	"name":			"清雨朦胧",
		"action":
"$N在$n四周游走，手中$w去势飘忽不定，只看得$n眼花缭乱。\n"
"趁此良机，$N于朦朦胧胧中一抖$w，向$n的$l疾挑",
		"dodge":		-15,
		"parry":		5,
		"damage":		25,
		"damage_type":		"刺伤"
	]),
	([	"name":			"飞花似梦",
		"action":
"激战中，$N从$n面前斜斜跃过，手中$w划出五朵桃花，点向$n的$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
	([	"name":			"丝雨如愁",
		"action":
"$N展开身形，身随剑走，剑身绵绵不绝地缠向$n的$l。\n"
"诗云：无边丝雨细如愁。$N的这招剑果然深得诗中三味",
		"dodge":		-20,
		"parry":		10,
		"damage":		20,
		"damage_type":		"割伤"
	]),
	([	"name":			"潇湘夜雨",
		"action":
"$N仗起手中$w，剑尖带起点点白光，罩住$n的胸腹，只等$n的破绽。\n"
"这招「潇湘夜雨」果然象细雨般紧密，$n实在不知长剑将要指向自己身上何处",
		"dodge":		-5,
		"parry":		-10,
		"damage":		20,
		"damage_type":		"刺伤"
	]),
	([	"name":			"月白风清",
		"action":
"$N手中$w中宫直进，疾速刺向$n的前心。\n"
"这招「月白风清」令人耳目一新。$n只见白光一闪，剑尖已到心口",
		"dodge":		-15,
		"parry":		15,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
	([	"name":			"金波低转",
		"action":
"$N手中$w向$n的右手疾刺，但正当$n要招架时，\n"
"$N剑尖转向$n的左足！这招「金波低转」确实神鬼莫测",
		"dodge":		-5,
		"parry":		-15,
		"damage":		25,
		"damage_type":		"刺伤"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力修为不够深，不能学晓风残月剑。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄长剑才能练习剑法。\n");
//	if (me->query("family/family_name") != "将军府")
//		return notify_fail("你必须先入将军府门下才可学晓风残月剑。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("yanxing-steps");
	int swo=(int)me->query_skill("xiaofeng-sword");

//	if (me->query("family/family_name") != "将军府")
//		return notify_fail("你必须先入将军府！\n");
//	if ((string)me->query("gender") == "男性")
//		if (dod<swo)
//			return
notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练晓风残月风剑有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练晓风残月风剑有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍晓风残月剑。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}
string perform_action_file(string func) {
  return CLASS_D("zhenyuan") + "/xiaofeng-sword/" + func;
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
