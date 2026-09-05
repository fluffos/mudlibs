// tiangang-zhi.c -天罡指
// create bye cuer
inherit SKILL;
mapping *action = ({
([	"action" : "$N左指飘忽不定，用以诱敌，右指划了个圆圈，一式「浪起湖心」从圈中穿出击向$n的$l",
	"force" : 80,
        "dodge" : -5,
	"lvl" : 0,
	"skill_name" : "浪起湖心",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左掌虚托，一式「瀑落清潭」，右指穿腋疾出，指向$n的胸前",
	"force" : 100,
        "dodge" : -5,
	"lvl" : 10,
	"skill_name" : "瀑落清潭",
        "damage_type" : "刺伤"
]),
([	"action" : "$N俯身斜倚，一式「龟蛇竞渡」，左手半推，右手一指点出，向$n的$l刺去",
	"force" : 120,
        "dodge" : 5,
	"lvl" : 20,
	"skill_name" : "龟蛇竞渡",
        "damage_type" : "刺伤"
]),
([	"action" : "$N嫣然一笑，一式「倒索攀山」，一矮身，双手斜指，蓄势点向$n的$l",
	"force" : 150,
        "dodge" : 5,
	"damage": 15,
	"lvl" : 30,
	"skill_name" : "倒索攀山",
        "damage_type" : "刺伤"
]),
([	"action" : "$N娇喝一声，一式「闪现雷鸣」，双手幻化出漫天指影，夹杂着风雷之声，点向$n的全身",
	"force" : 200,
        "dodge" : 15,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "闪现雷鸣",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌平托胸前，十指叉开，一式「地动山摇」，指向$n的周身大穴",
	"force" : 240,
        "dodge" : 20,
	"damage": 25,
	"lvl" : 50,
	"skill_name" : "地动山摇",
        "damage_type" : "刺伤"
]),
([	"action" : "$N双掌翻飞，一式「水拍云崖」，指端迸出无数道劲气，射向$n的全身",
	"force" : 300,
        "dodge" : 25,
	"damage": 30,
	"lvl" : 60,
	"skill_name" : "水拍云崖",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「泰山压顶」，并指如刃，一束束锐利无俦的指风，凌虚向$n的头上砍去",
	"force" : 350,
        "dodge" : 30,
	"damage": 35,
	"lvl" : 70,
	"skill_name" : "泰山压顶",
        "damage_type" : "刺伤"
])
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jinding-mianzhang"; }
int valid_learn(object me)
{       
        if (me->query("class")!="bonze" 
        	&& me->query("chushi/last_family")!="峨嵋派" 
        	&& (int)me->query_skill("tiangang-zhi",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天罡指必须空手。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 10)
		return notify_fail("你的临济十二庄火候不够，无法学天罡指。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练天罡指。\n");
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
	level   = (int) me->query_skill("tiangang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{        
        if (me->query("class")!="bonze" 
        	&& me->query("chushi/last_family")!="峨嵋派" 
        	&& (int)me->query_skill("tiangang-zhi",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n"); 
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练天罡指。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"tiangang-zhi/" + action;
}
