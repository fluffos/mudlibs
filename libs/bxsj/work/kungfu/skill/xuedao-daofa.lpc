// /kungfu/skill/xue-dao.c
// by dubei
// xue-dao.c 血刀

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「磨牙吮血」，将$w衔在嘴里，等$n走近了，突然间左手抓住刀柄，顺手一挥，砍向$p$l",
        "skill_name" : "磨牙吮血",
        "force" : 100,
        "dodge" : -5,
        "lvl" : 0,
        "damage" : 50,
        "damage_type" : "割伤",
]),
([      "action" : "$N嘿嘿一笑，一式「批纸削腐」，一刀横削过去，$n只觉眼前红光闪动，$l上微微一凉",
        "skill_name" : "批纸削腐",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 20,
        "damage" : 75,
        "damage_type" : "割伤",
]),
([      "action" : "$N衔$w在口，空手在$n身旁穿来插去，蓦地里右手从口中抽出刀来，「血海茫茫」一挥之下，刀锋直劈$p$l",
        "skill_name" : "血海茫茫",
        "force" : 180,
        "dodge" : 10,
        "lvl" : 30,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N嘿嘿冷笑声中，一招「血洗天河」，突见那$w红影闪闪，迎头弯转，竟如一根软带一般曲了下来，刀头削向$n$l",
        "skill_name" : "血洗天河",
        "force" : 220,
        "dodge" : 5,
        "lvl" : 50,
        "damage" : 90,
        "damage_type" : "割伤",
]),
([      "action" : "$N身子向前一探，一招「血蛇逐电」，$w颤动，刀刃便如一条赤练蛇一般，迅速无伦地在$n身上爬行而过，随即收刀入鞘，哈哈大笑",
        "skill_name" : "血蛇逐电",
        "force" : 250,
        "dodge" : -5,
        "lvl" : 70,
        "damage" : 100,
        "damage_type" : "割伤",
]),
([      "action" : "$N低吼一声，凛然生威，将手中$w刀柄反拿，一式「血痕累累」，卷起片片刀风斩向$n的$l",
        "skill_name" : "血痕累累",
        "force" : 280,
        "dodge" : 10,
        "lvl" : 90,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N气透刀尖，卷起刺骨寒风，一招「血风刺骨」向前直劈而下，一道红光从上至下剖向$n的$l",
        "skill_name" : "血风刺骨",
        "force" : 300,
        "dodge" : 5,
        "lvl" : 100,
        "damage" : 80,
        "damage_type" : "割伤",
]),
([      "action" : "$N一式「血雨空鸣」，一口$w越使越快，一团团红影笼罩了全身，向$n连砍数刀，都是只攻不守，极其凌厉的招数",
        "skill_name" : "血雨空鸣",
        "force" : 320,
        "dodge" : 10,
        "lvl" : 120,
        "damage" : 120,
        "damage_type" : "割伤",
]),
});

string *parry_msg = ({
"$n反手一刺，$w象一条盘蛇，直扑$N的手腕.",
"$n向左侧进一步，手中的$w顺势滑下，急削$N握的手指。\n",
"$n刀法一变，将手中的$w向上一撩,将$N的攻势引偏出去.",
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力不够练习血刀。\n");
	if ((int)me->query_skill("longxiang-gong", 1) < 100)
		return notify_fail("需要有第五层以上龙象般若功火候,才能修炼血刀刀法。\n");
          return 1;
}

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
	level   = (int) me->query_skill("xuedao-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	
	if ((int)me->query("jingli") < 60)
		return notify_fail("你的精力不够练血刀刀法。\n");
	me->receive_damage("jingli", 50);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xuedao-daofa/" + action;
}
