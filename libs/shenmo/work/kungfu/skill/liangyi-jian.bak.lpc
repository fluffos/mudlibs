// liangyi-jian.c (kunlun) 昆仑派正两仪剑法
//update by cool 981104
#include <ansi.h>
inherit SKILL;

mapping *man = ({ // 12 招
([	"action":"$N一式「顺水推舟」，$N手中$w指向自己左胸口，剑柄斜斜向右外，缓缓划向$n的$l",
	"force" : 180,
   "dodge" : 5,
   "parry" : 5,
	"damage": 50,
	"lvl" : 10,
	"skill_name" : "顺水推舟",
	"damage_type":"刺伤"
]),
([	"action":"$N身形微侧，左手后摆，右手$w一招「横扫千军」，直向$n的腰间挥去",
	"force" : 190,
		  "dodge" : 5,
		  "parry" : 10,
	"damage": 60,
	"lvl" : 20,
	"skill_name" : "横扫千军",
	"damage_type":"刺伤"
]),
([	"action":"$N纵身近前，$w斗然弯弯弹出，剑光爆长，一招「峭壁断云」，猛地刺向$n的胸口",
	"force" : 200,
		  "dodge" : 10,
		  "parry" : 5,
	"damage": 70,
	"lvl" : 28,
	"skill_name" : "峭壁断云",
	"damage_type":"刺伤"
]),
([	"action":"$N左手捏个剑决，平推而出，决指上仰，右手剑朝天不动，一招「仙人指路」，刺向$n",
	"force" : 210,
		  "dodge" : 10,
		  "parry" : 10,
	"damage": 80,
	"lvl" : 37,
	"skill_name" : "仙人指路",
	"damage_type":"刺伤"
]),
([	"action":"$N剑招忽变，使出一招「雨打飞花」，全走斜势，但七八招斜势中偶尔又挟着一招正势，教人极难捉摸",
	"force" : 220,
		  "dodge" : 15,
		  "parry" : 20,
	"damage": 90,
	"lvl" : 45,
	"skill_name" : "雨打飞花",
	"damage_type":"刺伤"
]),
([	"action":"$N手中$w剑刃竖起，锋口向下，一招「大漠平沙」，剑走刀势，劈向$n的$l",
	"force" : 230,
		  "dodge" : 20,
		  "parry" : 20,
	"damage": 100,
	"lvl" : 53,
	"skill_name" : "大漠平沙",
	"damage_type":"劈伤"
]),
([	"action":"$N一招「木叶萧萧」，$N横提$w，剑尖斜指向天，由上而下，劈向$n的$l",
	"force" : 240,
		  "dodge" : 25,
		  "parry" : 30,
	"damage": 105,
	"lvl" : 60,
	"skill_name" : "木叶萧萧",
	"damage_type":"劈伤"
]),
([	"action":"$N抢前一步，$w微微抖动，剑光点点，一招「江河不竭」，终而复始，绵绵不绝刺向$n",
	"force" : 250,
		  "dodge" : 20,
		  "parry" : 30,
	"damage": 110,
	"lvl" : 70,
	"skill_name" : "江河不竭",
	"damage_type":"刺伤"
]),
([	"action":"$N左手剑鞘一举，快逾电光石光，一招「高塔挂云」，用剑鞘套住$n手中兵器，$w直指$n的咽喉",
	"force" : 260,
		  "dodge" : 30,
		  "parry" : 30,
	"damage": 120,
	"lvl" : 78,
	"skill_name" : "高塔挂云",
	"damage_type":"刺伤"
]),
([	"action":"$N翻身回剑，剑诀斜引，一招「百丈飞瀑」，剑锋从半空中直泻下来，罩住$n上方",
	"force" : 270,
		  "dodge" : 25,
		  "parry" : 35,
	"damage": 130,
	"lvl" : 86,
	"skill_name" : "百丈飞瀑",
	"damage_type":"刺伤"
]),
([	"action":"$N一式「雪拥蓝桥」，$N手中剑花团团，一条白练疾风般向卷向$n",
	"force" : 280,
		  "dodge" : 20,
		  "parry" : 35,
	"damage": 140,
	"lvl" : 100,
	"skill_name" : "雪拥蓝桥",
	"damage_type":"刺伤"
]),
([	"action":"$N腾空而起，突然使出一招「无声无色」，悄无声息地疾向$n的背部刺去",
	"force" : 300,
    "dodge" : 40,
    "parry" : 25,
	"damage": 155,
	"lvl" : 130,
	"skill_name" : "无声无色",
	"damage_type":"刺伤"
]),
});
mapping *woman = ({ // 12 招
([	"action":"$N一式「顺水推舟」，$N手中$w由胸口划出，剑尖向内，缓缓刺向$n的$l",
	"force" : 180,
   "dodge" : 15,
   "parry" : 5,
	"damage": 40,
	"lvl" : 10,
	"skill_name" : "顺水推舟",
	"damage_type":"刺伤"
]),
([	"action":"$N身形前冲，左手后摆，右手$w一招「横扫千军」，直向$n的胸口刺去",
	"force" : 190,
		  "dodge" : 5,
		  "parry" : 5,
	"damage": 50,
	"lvl" : 20,
	"skill_name" : "横扫千军",
	"damage_type":"刺伤"
]),
([	"action":"$N纵身近前，剑尖晃动，剑光爆长，一招「峭壁断云」，猛地刺向$n的头部",
	"force" : 200,
		  "dodge" : 15,
		  "parry" : 10,
	"damage": 60,
	"lvl" : 28,
	"skill_name" : "峭壁断云",
	"damage_type":"刺伤"
]),
([	"action":"$N左手捏个剑决，平推而出，右手剑前指不动，一招「仙人指路」，刺向$n",
	"force" : 210,
		  "dodge" : 15,
		  "parry" : 5,
	"damage": 70,
	"lvl" : 37,
	"skill_name" : "仙人指路",
	"damage_type":"刺伤"
]),
([	"action":"$N剑招忽变，使出一招「雨打飞花」，全走斜势，但七八招斜势中偶尔又挟着一招正势，教人极难捉摸",
	"force" : 220,
		  "dodge" : 20,
		  "parry" : 15,
	"damage": 80,
	"lvl" : 45,
	"skill_name" : "雨打飞花",
	"damage_type":"刺伤"
]),
([	"action":"$N手中$w剑刃平刺，锋口向着左右，一招「大漠平沙」，刺向$n",
	"force" : 230,
		  "dodge" : 25,
		  "parry" : 10,
	"damage": 90,
	"lvl" : 53,
	"skill_name" : "大漠平沙",
	"damage_type":"刺伤"
]),
([	"action":"$N一招「木叶萧萧」，$N横提$w，剑尖斜指向地，由下而上，撩向$n的$l",
	"force" : 240,
		  "dodge" : 30,
		  "parry" : 20,
	"damage": 95,
	"lvl" : 60,
	"skill_name" : "木叶萧萧",
	"damage_type":"刺伤"
]),
([	"action":"$N稍稍退后，$w微微抖动，剑光点点，一招「江河不竭」，终而复始，绵绵不绝刺向$n",
	"force" : 250,
		  "dodge" : 25,
		  "parry" : 25,
	"damage": 105,
	"lvl" : 70,
	"skill_name" : "江河不竭",
	"damage_type":"刺伤"
]),
([	"action":"$N左手剑鞘一举，快逾电光石光，一招「高塔挂云」，用剑鞘挡住$n手中兵器，$w直指$n的咽喉",
	"force" : 260,
		  "dodge" : 30,
		  "parry" : 25,
	"damage": 110,
	"lvl" : 78,
	"skill_name" : "高塔挂云",
	"damage_type":"刺伤"
]),
([	"action":"$N侧身前趋，剑诀斜引，一招「百丈飞瀑」，剑锋从半空中直泻下来，罩住$n上方",
	"force" : 270,
		  "dodge" : 15,
		  "parry" : 10,
	"damage": 120,
	"lvl" : 86,
	"skill_name" : "百丈飞瀑",
	"damage_type":"刺伤"
]),
([	"action":"$N一式「雪拥蓝桥」，$N手中剑花团团，一条白练疾风般向卷向$n",
	"force" : 280,
		  "dodge" : 25,
		  "parry" : 30,
	"damage": 135,
	"lvl" : 100,
	"skill_name" : "雪拥蓝桥",
	"damage_type":"刺伤"
]),
([	"action":"$N腾空而起，突然使出一招「无声无色」，悄无声息地疾向$n的背部刺去",
	"force" : 300,
    "dodge" : 35,
    "parry" : 30,
	"damage": 150,
	"lvl" : 130,
	"skill_name" : "无声无色",
	"damage_type":"刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 100)
		return notify_fail("你的玄天无极功火候太浅。\n");
	if ((int)me->query_skill("xunlei-jian", 1) < 80)
		return notify_fail("你的迅雷十六剑火候太浅。\n");
	return 1;
}

string query_skill_name(int level,object me)
{
		  int i;level;
		level   = (int) me->query_skill("liangyi-jian",1);
               if (me->query("gender")!="女性") {
		  for(i = sizeof(man)-1; i >= 0; i--)
					 if(level < man[i]["lvl"])
							return man[i]["skill_name"];
                     } else {
 for(i = sizeof(woman)-1; i >= 0; i--)
					 if(level >= woman[i]["lvl"])
								return woman[i]["skill_name"];
                             }
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("liangyi-jian",1);
	if (me->query("gender")!="女性") {
	for(i = sizeof(man); i > 0; i--) {
		if(level > man[i-1]["lvl"]) 
/* {
		if(me->query_temp("shuangjian_hebi")){
                return ([
                "action":HIB+man[NewRandom(i, 20, level/5)]["action"]+NOR,
                "damage":man[NewRandom(i, 20, level/5)]["damage"]+level/3,
                "damage_type": man[NewRandom(i, 20, level/5)]["damage_type"],
		  "skill_name": man[NewRandom(i, 20, level/5)]["skill_name"],
                "dodge": man[NewRandom(i, 20, level/5)]["dodge"]*3/2,
	         "parry": man[NewRandom(i, 20, level/5)]["parry"],
                "force": man[NewRandom(i, 20, level/5)]["force"]+level/3,
                ]);
        } else {
*/
			return man[NewRandom(i,20,level/5)];
//}
//}
}
} else {
for(i = sizeof(woman); i > 0; i--) {
		if(level > woman[i-1]["lvl"]) 
/* {
		if(me->query_temp("shuangjian_hebi"))
	{
                return ([
                "action":MAG+woman[NewRandom(i, 20, level/5)]["action"]+NOR,
                "damage":woman[NewRandom(i, 20, level/5)]["damage"]+level/3,
                "damage_type": woman[NewRandom(i, 20, level/5)]["damage_type"],
		  "skill_name": woman[NewRandom(i, 20, level/5)]["skill_name"],
                "dodge": woman[NewRandom(i, 20, level/5)]["dodge"],
	         "parry": woman[NewRandom(i, 20, level/5)]["parry"]*3/2,
                "force": woman[NewRandom(i, 20, level/5)]["force"]+level/3,
                ]);
        } else {
*/
			return woman[NewRandom(i, 20, level/5)];

//}
//}
}
}
}


int practice_skill(object me)
{
	object weapon;
	int lvl = me->query_skill("liangyi-jian", 1);

	int i = sizeof(man);
	while (i--) if (lvl == man[i]["lvl"]) return 0;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的体力不够练两仪剑法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liangyi-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
  int i;

  i=me->query_skill("liangyi-jian",1)/3;
 if(me->query_temp("ly_hebi")&& !me->query_temp("hebi_hit") 
&& me->query_skill_mapped("parry") == "liangyi-jian") {
 me->set_temp("hebi_hit", 1);
  me->add_temp("apply/attack", i);
  COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);  
  me->add_temp("apply/attack", -i);
   me->delete_temp("hebi_hit");
       }
}
