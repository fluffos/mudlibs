// murong-daofa.c 慕容刀法
// by xuanyuan 2002.2

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N大喝一声「看招」，一招「劈天盖地满壮志」，刀锋自上而下向$n的$l挥去",
        "force" : 160,
        "dodge" : 10,
        "damage": 30,
        "lvl" : 0,
        "skill_name" : "劈天盖地满壮志",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「弯刀逆转倒乾坤」，手中$w在空中急速转动数圈，划向$n的$l",
        "force" : 200,
        "dodge" : 10,
        "damage": 60,
        "lvl" : 10,
        "skill_name" : "弯刀逆转倒乾坤",
        "damage_type" : "割伤"
]),
([      "action" : "$N猛一挫身，一招「遥看万疆千里雪」,$w直向$n的颈中斩去",
        "force" : 260,
        "dodge" : 5,
        "damage": 100,
        "lvl" : 30,
        "skill_name" : "遥看万疆千里雪",
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「壮志豪气满江湖」，无数刀尖化作点点繁星，向$n的$l挑去",
        "force" : 300,
        "dodge" : 5,
        "damage": 160,
        "lvl" : 50,
        "skill_name" : "壮志豪气满江湖",
        "damage_type" : "割伤"
]),
});
mapping *baijia_action = ({

		([      "action" : "突然之间，白光闪动，$N东砍一刀，竟是少林寺的降魔刀法",
		        "skill_name" : "降魔刀法",
		        "force" : 200,
		        "dodge" : 35,
		        "lvl" : 60,
		        "damage" : 50,
		        "damage_type" : "割伤",
		]),
		([      "action" : "$N西劈一刀，刀法诡异，居然是广西黎山洞黎老汉的柴刀十八路",
		        "skill_name" : "柴刀十八路",
		        "force" : 320,
		        "dodge" : 40,
		        "lvl" : 70,
		        "damage" : 60,
		        "damage_type" : "割伤",
		]),
		([      "action" : "$N手持$w回转而削，又变作了江南史家的‘回风拂柳刀’",
		        "skill_name" : "回风拂柳刀",
		        "force" : 440,
		        "dodge" : 45,
		        "lvl" : 80,
		        "damage" : 70,
		        "damage_type" : "割伤",
		]),
		([      "action" : "$N反转刀背，砍向$n的$l，俨然是宁波天童寺心观老和尚所创的‘慈悲刀",
		        "skill_name" : "慈悲刀",
		        "force" : 460,
	        	"dodge" : 50,
		        "lvl" : 90,
		        "damage" : 80,
	        	"damage_type" : "割伤",
		]),
		([      "action" : "$N立时乘势直上，$w的刃锋已及$n的$l，乃是金刀杨老令公上阵擒敌的招数‘后山三绝招’",
	        	"skill_name" : "后山三绝招",
		        "force" : 520,
		        "dodge" : 55,
	        	"lvl" : 100,
		        "damage" : 100,
		        "damage_type" : "割伤",
		]),
		([      "action" : "$N使出青海玉树派挪一招‘大漠飞沙’，接着又是乙派的‘羽衣刀’第十七招，刀锋未老，又使出了灵飞派的‘清风徐来’",
		        "skill_name" : "百家刀法",
	        	"force" : 500,
		        "dodge" : 60,
		        "lvl" : 110,
	        	"damage" : 120,
		        "damage_type" : "割伤",
		]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }


int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 25)
                return notify_fail("你的斗转星移火候不够，无法学慕容刀法。\n");
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

        level = (int)me->query_skill("murong-daofa", 1);

        if( me->query_temp("murong/baijia") )
				return baijia_action[random(sizeof(baijia_action))];
		else {
			for(i = sizeof(action); i > 0; i--)
				if(level > action[i-1]["lvl"])
					return action[NewRandom(i, 20, level/5)];
	}
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 40)
                return notify_fail("你的精力不够练慕容刀法。\n");
		if ((int)me->query("neili") < 15)
                return notify_fail("你的内力不够练慕容刀法。\n");
        me->receive_damage("jingli", 25);
		me->add("neili",-10);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"murong-daofa/" + action;
}
