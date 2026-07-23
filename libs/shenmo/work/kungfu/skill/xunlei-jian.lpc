//xunlei-jian by cool
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N剑尖向右，绕身一周，一式「仙人指路」，$w突然向$n的$l刺去，",
	"force" : 110,
	"dodge" : 20,
	"damage" : 215,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N使出一式「鹞子翻身」，身体凌空侧翻，一剑从身下刺出",
	"force" : 120,
	"dodge" : 15,
	"damage" : 120,
        "lvl" : 5,
	"damage_type" : "刺伤"
]),
([	"action" : "$N左手剑指血指，右手$w使出一招「海底寻针」，由上至下猛向$n的$l劈刺",
	"force" : 130,
	"dodge" : 15,
	"damage" : 130,
        "lvl" : 10,
	"damage_type" : "刺伤"
]),
([	"action" : "$N撤步缩身，$w按藏于臂下，一招「灵猿探洞」，快如闪电般刺向$n的$l",
	"force" : 140,
	"dodge" : 10,
	"damage" : 140,
        "lvl" : 15,
	"damage_type" : "刺伤"
]),
([	"action" : "$N踏步向前，一式「拨草寻蛇」，手中长剑摆动，剑尖刺向$n的$l",
	"force" : 150,
	"dodge" : 10,
	"damage" : 150,
        "lvl" : 20,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「斜插神枝」，身体背转，手中$w由右肩上方反手向下刺出",
	"force" : 160,
	"dodge" : 5,
	"damage" : 155,
        "lvl" : 25,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「电闪雷动」，剑走中锋，气势威严，将$n笼罩于重重剑气之中",
	"force" : 170,
	"dodge" : 0,
	"damage" : 160,
        "lvl" : 30,
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前弯身，一招「夫子揖手」，$w忽然从身下刺出，快如流星闪电",
	"force" : 180,
	"dodge" : 20,
	"damage" : 165,
        "lvl" : 35,
	"damage_type" : "刺伤"
]),
([	"action" : "$N横握$w，左右晃动，一招「玉带缠腰」，剑气直逼$n的腰部要害",
	"force" : 190,
	"dodge" : 5,
	"damage" : 170,
        "lvl" : 45,
	"damage_type" : "刺伤"
]),
([	"action" : "$N双手持剑，将$w当做刀使，一招「举火烧天」，由身后向$n的前上方劈去",
	"force" : 200,
	"dodge" : 5,
	"damage" : 175,
        "lvl" : 55,
	"damage_type" : "劈伤"
]),
([	"action" : "$N侧身向$n，使出一招「败马斩蹄」，挥动手中$w，直劈$n的下三路",
	"force" : 210,
	"dodge" : 10,
	"damage" : 180,
        "lvl" : 65,
	"damage_type" : "劈伤"
]),
([	"action" : "$N手中$w由右自左，一招「玉女穿针」，$w突然反手刺向$n的$l",
	"force" : 220,
	"dodge" : 0,
	"damage" : 190,
        "lvl" : 75,
	"damage_type" : "刺伤"
]),
([	"action" : "$N跳步向前，剑尖上指，一招「灵猿登枝」，$w挑向$n的头部要害",
	"force" : 230,
	"dodge" : 20,
	"damage" : 205,
        "lvl" : 85,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「苏武挥鞭」，$w随身走，犹如一条白龙，将$n全身上下笼罩",
	"force" : 240,
	"dodge" : 15,
	"damage" : 215,
        "lvl" : 95,
	"damage_type" : "刺伤"
]),
([	"action" : "$N剑尖向下，一招「挑灯看剑」，$w忽然急转直上，剑气将$n的上身要害团团围住",
	"force" : 250,
	"dodge" : 15,
	"damage" : 235,
        "lvl" : 100,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 30)
		return notify_fail("你的玄天无极功火候太浅。\n");
	if ((int)me->query_skill("sword", 1) < 20)
		return notify_fail("你的基本剑法火候太浅。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("xunlei-jian",1);
	
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
		if(random(level) >= 120){
                return ([
                "action":HIB+action[NewRandom(i, 20, level/5)]["action"]+NOR,
                "damage":level*2,
                "damage_type": "刺伤",
                "dodge": level/2+random(50),
                "force": level+80+random(50),
                ]);
        } else {
			return action[NewRandom(i, 20, level/5)];
}
}
}
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jing") < 30)
		return notify_fail("你的体力不够练迅雷剑法。\n");
	me->receive_damage("jing", 25);
	return 1;
}
string perform_action_file(string action)
{
       return __DIR__"xunlei-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xuantian-wuji",1);
        level2= (int) me->query_skill("xuantian-wuji",1);


if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "xuantian-wuji")
{
        victim->receive_damage("qi",level*2+300);
        victim->receive_wound("qi",level*3+300);
	return HIB"$N脚踏八卦步,手捏太乙决,$N一声长啸，$n双眼一黑，吐出一口鲜血!\n"NOR;
}
}