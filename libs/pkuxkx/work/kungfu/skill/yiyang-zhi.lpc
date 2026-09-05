// yiyang-zhi 一阳指
// Made by ysg (1997.10.19)

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N侧身抬臂，右手食指划圈，缓缓推出，一式「普渡众生」摁向$n的$l",
	"force"  : 260,
        "dodge"  : 5,
	"parry"  : 10,
	"damage" : 100,
     "lvl":0,
	"skill_name" : "普渡众生",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「童子拜佛」，双手合十，一股锐利无俦的内力，凌虚向$n的$l涌去",
	"force"  : 240,
        "dodge"  : 30,
	"parry"  : 20,
	"damage" : 140,
	"lvl" : 45,
	"skill_name" : "童子拜佛",
        "damage_type" : "内伤"
]),
([	"action" : "$N一式「无我无相」，左手食指指尖向天，指端射出一缕罡气，穿过$n的$l",
	"force"  : 220,
        "dodge"  : 35,
	"parry"  : 35,
	"damage" : 325,
	"lvl" : 65,
	"skill_name" : "无我无相",
        "damage_type" : "刺伤"
]),
([	"action" : "$N满眼慈悲，一式「四大皆空」，右手食指对着对着$n的眉心遥遥摁去，$n不知\n"
			"为何，只觉万般皆空，竟然忘了躲开。",
	"force"  : 300,
        "dodge"  : 40,
	"parry"  : 40,
	"damage" : 320,
	"lvl" : 82,
	"skill_name" : "四大皆空",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
	string family;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if (me->query("yiyang_zhi/quanzhen")&&!me->query("yiyang_zhi/tianlong")&&(int)me->query_skill("xiantian-gong", 1) < 50)
		return notify_fail("你的先天功火候不够，无法学一阳指。\n");
	if ((int)me->query("max_neili") < 400)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
	if (!me->query("yiyang_zhi/quanzhen")&&!me->query("yiyang_zhi/tianlong"))
	{
		family=me->query("family/family_name");
		if (family=="天龙寺")
		{
			me->set("yiyang_zhi/tianlong",1);
		}
		else
		{
			me->set("yiyang_zhi/quanzhen",1);
		}
	}
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
	level   = (int) me->query_skill("yiyang-zhi",1);
        for( i = sizeof(action) - 1; i >= 0; i-- )
                if( level >= action[i]["lvl"] )
                        return action[random(i+1)];
        return action[0];
}

int practice_skill(object me)
{
	string family;
	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");
	if (me->query("yiyang_zhi/quanzhen")&&me->query("yiyang_zhi/tianlong")&&(int)me->query("qi") < 200)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练一阳指。\n");
	if (me->query("yiyang_zhi/quanzhen")&&me->query("yiyang_zhi/tianlong")&&(int)me->query("neili") < 80)
		return notify_fail("你的内力不够练一阳指。\n");
	me->receive_damage("qi", 90);
	me->add("neili", -30);
	if (me->query("yiyang_zhi/quanzhen")&&me->query("yiyang_zhi/tianlong"))//2种一阳指都会，练习两种技能变成了练一种技能，让额外消耗增加50%
	{
		me->receive_damage("qi", 45);
		me->add("neili", -15);
	}
	family=me->query("family/family_name");
	if (family=="天龙寺")
	me->set("yiyang_zhi/tianlong",1);
	else
	me->set("yiyang_zhi/quanzhen",1);
	
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yiyang-zhi/" + action;
}

