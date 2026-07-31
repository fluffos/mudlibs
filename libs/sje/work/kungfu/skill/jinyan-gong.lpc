// jinyan-gong.c 金雁功

inherit SKILL;

mapping *action = ({
([	"action" : "$n微一侧身，轻轻向前一纵，一式「北雁南飞」，轻描淡写地躲过$N的一击。\n",
	"lvl" : 0,
 	"skill_name" : "北雁南飞",
	"dodge"  : 15
]),
([	"action" : "$n一式「雁去无痕」，长身而起飘然后退，$N一击不中，$n已落在丈许之外。\n",
	"lvl" : 5,
	"skill_name" : "雁去无痕",
	"dodge"  : 25
]),
([	"action" : "$n虚步前跨，脚踩七星方位，由天玑至玉衡，一招「斗转星移」已然绕到$N身后。\n",
	"lvl" : 10,
	"skill_name" : "斗转星移",
	"dodge"  : 35
]),
([	"action" : "$n微微一笑，足不动，身不摆，一式「神游太虚」如清烟般冉冉而起，滑向$N左侧。\n",
	"lvl" : 20,
	"skill_name" : "神游太虚",
	"dodge"  : 45
]),
([	"action" : "$n身形突变，使出「群星灿烂」，围绕$N四处游走顿时幻化出无数人影，$N目瞪眼呆不知击向何处。\n",
	"lvl" : 30,
	"skill_name" : "群星灿烂",
	"dodge"  : 55
]),
([	"action" : "$n一式「轻如鸿毛」，身形飘忽浑不着力，如一片鸿毛随风而动，堪堪躲过$N狂风暴雨般的攻势。\n",
	"lvl" : 40,
	"skill_name" : "轻如鸿毛",
	"dodge"  : 65
]),
([	"action" : "$n身子如陀螺般急速旋转起来，一招「横空出世」将$N的攻势统统化解。\n",
	"lvl" : 55,
 	"skill_name" : "横空出世",
	"dodge"  : 75
]),
([	"action" : "$n一式「如影随行」，衣袂飘飘，随着$N的走势而动，在$N大惊之下$n已飘然滑开！\n",
	"lvl" : 80,
	"skill_name" : "如影随行",
	"dodge"  : 85
]),
([	"action" : "$n使出「上天梯」身体斗然拔起，越升越高，空中微一转折落在数丈之外，将$N的攻势尽数化于无形！\n",
	"lvl" : 99,
	"skill_name" : "上天梯",
	"dodge"  : 99
])

});


string query_skill_name(int level)
{
	int i;

	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level   = (int) me->query_skill("jinyan-gong",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) 
			return action[NewRandom(i, 20, level/5)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(object me)
{
	int i, level;

	level   = (int) me->query_skill("jinyan-gong",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"]) 
			return action[NewRandom(i, 20, level/5)]["action"];
}

int practice_skill(object me)
{
	int lvl = me->query_skill("jinyan-gong", 1);
	int i = sizeof(action);
	mapping learned = me->query_learned();

	if (!mapp(learned)) learned = ([]);
	if (!learned["jinyan-gong"])
		while (i--) 
			if (lvl == action[i]["lvl"])
				return notify_fail("你将已经学会的所有招式练习了一遍，发现如果不去找师父学新的招式就无法获得进步了。\n");;

	if( (int)me->query("jingli") < 40 )
		return notify_fail("你的精力太差了，不能练随金雁功身法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}
