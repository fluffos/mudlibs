// shigu-bifa.c
inherit SKILL;

mapping *action = ({
([      "action":"$N一招「指点江山」，手中$w疾点向$n的期门穴!",
	"force" : 70,
	"dodge" : 20,
	"damage" : 25,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([      "action":"$N吐气开声一招「银钩铁划」，$w如灵蛇吞吐，向$n白海穴戳去!",
	"force" : 90,
	"dodge" : 15,
	"damage" : 30,
	"lvl" : 9,
	"damage_type":  "刺伤"
]),
([      "action":"$N向前跨上一步，混身充满战意，手中$w使出「银瓶乍破」，疾点$n的地仓穴!",
	"force" : 100,
	"dodge" : 10,
	"damage" : 35,
	"lvl" : 19,
	"damage_type" : "刺伤"
]),
([      "action":"$N手中的$w自左而右地一晃，使出「铁骑突出」带着呼呼风声横打$n的章门穴!",
	"force" : 120,
	"dodge" : 10,
	"damage" : 40,
	"lvl" : 29,
	"damage_type":  "刺伤"

]),
([      "action":"$N飞身跃起，一式「龙耀九霄」，卷起漫天笔影，$w向$n电射而去",
	"force" : 150,
	"dodge" : 5,
	"damage" : 45,
	"lvl" : 39,
	"damage_type":  "刺伤"
]),
([      "action":"$N凝气守中，$w逼出尺许雪亮笔锋，挥出「灵台观景」，一笔快似一笔地攻向$n",
	"force" : 180,
	"dodge" : 5,
	"damage" : 48,
	"lvl" : 59,
	"damage_type":  "刺伤"
]),
([      "action":"$N使出一招「遥拜玉虚」挺笔中宫直进，笔尖颤动，中途忽然转而向上变幻无方",
	"force" : 210,
	"dodge" : -5,
	"damage" : 50,
	"lvl" : 79,
	"damage_type":  "刺伤"
]),
([      "action":"$N侧身斜刺一笔，一招「天音萧煞」卷带着呼呼笔风，将$n包围紧裹",
	"force" : 230,
	"dodge" : -5,
	"damage" : 60,
	"lvl" : 99,
	"damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "dagger") || (usage == "parry"); }

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 450 )
		return notify_fail("你的内力不够，没有办法练石鼓打穴笔法。\n");

	if( (int)me->query_skill("force") < 60 )
		return notify_fail("你的内功火候不够，还不能学习石鼓打穴笔法!\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
       int i, level;
       level   = (int) me->query_skill("shigu-bifa",1);
       for(i = sizeof(action); i > 0; i--)
	       if(level > action[i-1]["lvl"])
		       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{       object ob;
	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "bi" )
		return notify_fail("你必须先找一对判官笔才能学习石鼓打穴笔法。\n");

	if( (int)me->query("qi") < 50)
		return notify_fail("你的气不够，没有办法练习石鼓打穴笔法。\n");

	if( (int)me->query("neili") < 45)
		return notify_fail("你的内力不够，没有办法练习石鼓打穴笔法。\n");

	me->receive_damage("qi", 35);
	me->add("neili", -35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__ "shigu-bifa/" + action;
}
