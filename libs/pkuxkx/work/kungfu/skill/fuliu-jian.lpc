// fuliu-jian.c 回风拂柳剑
//create bye cuer
//modified by iszt@pkuxkx, 2007-02-13

#include <ansi.h>

inherit SKILL;
mapping *action = ({
([	"action" : "$N轻歌曼舞，一招「清风袭月」，手中$w轻轻颤动，一剑剑点向$n的$l",
	"force" : 180,
	"dodge" : 20,
	"damage" : 40,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N抬首望天，右手$w使出一式「飘雪穿云」飘忽不定的刺向$n的$l",
	"force" : 100,
	"dodge" : 15,
	"damage" : 10,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「千峰竞秀」，手中$w轻颤，化出重重剑影，平平地向$n的$l刺去",
	"force" : 120,
	"dodge" : 15,
	"damage" : 30,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「万流归宗」，手中$w化出的重重剑影合而为一，一气呵成地攻向$n的$l",
	"force" : 130,
	"dodge" : 10,
	"damage" : 40,
        "lvl" : 29,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出「乌龙搅柱」，$w划出无数的光圈，随着身体的旋转划向$n的$l",
	"force" : 140,
	"dodge" : 5,
	"damage" : 60,
        "lvl" : 39,
	"damage_type" : "割伤"
]),
([	"action" : "$N左脚踏实，右脚虚点，一招「大雁啼沙」，右手$w带着一团剑花，逼向$n的$l",
	"force" : 150,
	"dodge" : 5,
	"damage" : 80,
        "lvl" : 59,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「进退游龙」，手中$w微颤，$w吞吐闪烁不定似退实进，刺向$n的$l",
	"force" : 200,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 79,
	"damage_type" : "刺伤"
]),
([	"action" : "$N右腿微一点地，跃入半空，一招「天地鹤翔」，俯冲而下，剑尖直指$n的$l",
	"force" : 200,
	"dodge" : -5,
	"damage" : 100,
        "lvl" : 99,
	"damage_type" : "刺伤"
])
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_combine(string combo) {return combo=="yanxing-dao";}
int valid_learn(object me)
{
	if (me->query("class")!="bonze" && me->query("chushi/last_family")!="峨嵋派" && (int)me->query_skill("fuliu-jian",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领悟回风拂柳剑的精妙之处。\n");
        if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候太浅。\n");
	if ((int)me->query_skill("jinding-mianzhang", 1) < 20)
		return notify_fail("你的金顶绵掌火候太浅。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	int i, level;
	mapping newaction=([]);
	level   = (int) me->query_skill("fuliu-jian",1);
	if(level >= 150 && me->query("qi")> 1000
		&& (int)me->query_skill("linji-zhuang",1) >= 150
		&& me->query("neili") > 1000 && random(10) > 7 )
	{
                me->add("neili",-50-random(50));
		newaction=([
		"action" : HIR"$N清喝一声，右手执剑猛向$n面门刺去，袍袖随之挥出，正好挡在$n眼前，\n"
                "左手突然从右袖下伸出，正对$n胸口狠狠的击去！"NOR,
		"damage" : 400,
		"damage_type" : "震伤"
		]);
		return newaction;
	}
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	object weapon;
        if (me->query("class")!="bonze" && me->query("chushi/last_family")!="峨嵋派" && (int)me->query_skill("fuliu-jian",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能练高深的佛门武功。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练回风拂柳剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"fuliu-jian/" + action;
}
