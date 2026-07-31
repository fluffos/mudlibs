
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N翻腕一振$w，一招「"+HIY"狮子摇头"NOR+"」，枪上红缨抖动，挽出斗大一个枪花，往$n$l直搠过去",
	"force" :random(40)+ 125,
	"dodge" : -0,
	"damage": 25,
	"lvl" : 0,
	"skill_name" : "狮子摇头",
	"damage_type":  "刺伤"
]),
([      "action":"$N倒转$w，一招「"+HIY"白虹经天"NOR+"」，斜身移步，枪杆起处，圆圆一团红影，枪尖上一点寒光疾向$n刺来",
	"force" :random(40)+ 160,
	"dodge" : -0,
	"damage": 45,
	"lvl" : 10,
	"skill_name" : "白虹经天",
	"damage_type":  "割伤"
]),
([      "action":"$N催动身法急走如飞，手中$w一抖，使出一招「"+HIY"朝天一柱香"NOR+"」，$w挺得笔直，迅捷无伦地刺向$n的$l",
	"force" :random(40)+ 200,
	"dodge" : 10,
	"damage": 55,
	"lvl" : 20,
	"skill_name" : "朝天一柱香",
	"damage_type":  "割伤"
]),
([      "action":"$N挺起$w，一招「"+HIY"凤点头"NOR+"」，红缨抖动，$w幻出点点枪影，枪尖闪烁不定地往$n$l点到",
	"force" :random(40)+ 250,
	"dodge" : 10,
	"damage": 65,
	"lvl" : 30,
	"skill_name" : "凤点头",
	"damage_type":  "刺伤"
]),
([      "action":"$N一招「"+HIY"春雷震怒"NOR+"」，刷刷刷连环三枪，急刺而至，朱缨乱摆，$w嗤嗤声响，颤成一个大红圈子，罩住了$n上下各路",
	"force" :random(40)+ 300,
	"dodge" : 5,
	"damage": 75,
	"lvl" : 40,
	"skill_name" : "春雷震怒",
	"damage_type":  "割伤"
]),
([      "action":"$N突然大喝一声，双手抓住枪柄，劲力到处$w弯成弓形，突然一松手，电光一闪劈空刺向$n，好一招「"+HIY"灵蛇电闪"NOR+"」",
	"force" :random(40)+ 340,
	"dodge" : 5,
	"damage": 85,
	"lvl" : 50,
	"skill_name" : "灵蛇电闪",
	"damage_type":  "刺伤"
]),
([      "action":"$N突然踏上一步，$w挺得笔直，使出一招「"+HIY"孤雁出群"NOR+"」，$w来势如风，凌厉无匹地向$n的$l刺去",
	"force" :random(40)+ 380,
	"dodge" : 10,
	"damage": 95,
	"lvl" : 60,
	"skill_name" : "孤雁出群",
	"damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "spear" || usage == "parry"; }
int valid_learn(object me) { return 1; }

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
        level   = (int) me->query_skill("yangjia-qiangfa",1);

        if ( me->query_temp("yqjf/huimaqiang")){
			return ([
				"action": HIW"$N大喝一声，双手抓住枪柄，斗然间拧腰纵臂，回身出枪，直刺$n面门，这一枪正是杨家枪法的“回马枪”" NOR,
                "damage": 150,
                "dodge" : 100,
                "damage_type": "刺伤"]);
        }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练杨家枪。\n");
        me->receive_damage("jingli", 20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yangjia-qiangfa/" + action;
}




