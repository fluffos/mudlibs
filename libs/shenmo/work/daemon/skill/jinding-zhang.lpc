
// jinding-zhang.c 金顶绵掌
// Oct. 9 1997 by That
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "skill_name" : "三阳开泰" ,
	"action" : "$N身形微晃，一招"+BLINK""+HIY"「三阳开泰」"NOR"，掌起风生，$n只觉得一股暖气袭向$l",
	"force" : 10,
	"dodge" : 10,
	"damage_type" : "内伤",
	"lvl"   : 0,
]),
([	  "skill_name" : "五气呈祥" ,
	"action" : "$N双手变幻，五指轻弹，一招"+BLINK""+HIG"「五气呈祥」"NOR"，力分五路，招罩十方，抓向$n的$l",
	"force" : 30,
	"dodge" : -10,
	"damage_type" : "内伤",
	"lvl"   : 11,
]),
([	  "skill_name" : "罡风推云" ,
	"action" : "$N左手前引，右手倏出，抢在头里，一招"+BLINK""+HIM"「罡风推云」"NOR"，疾抓向$n的$l",
	"force" : 40,
	"dodge" : -20,
	"damage_type" : "内伤",
	"lvl"   : 22,
]),
([	  "skill_name" : "逆流捧沙" ,
	"action" : "$N左手圈转，轻拂$n的左手，反向推出，右手连续磕击，一招"+BLINK""+HIW"「逆流捧沙」"NOR"，猛地击向$n的下巴",
	"force" : 50,
	"dodge" : 10,
	"damage_type" : "内伤",
	"lvl"   : 33,
]),
([	  "skill_name" : "雷洞霹雳" ,
	"action" : "$N舌绽春雷，一声娇喝，在$n一愣间，右手一招"+BLINK""+HIR"「雷洞霹雳」"NOR"，直捣$n的$l",
	"force" : 60,
	"dodge" : 10,
	"damage_type" : "内伤",
	"lvl"   : 44,
]),
([	  "skill_name" : "金顶佛光" ,
	"action" : "$N双手平举握拳，脸露微笑，$n恍惚间看到$N分身为二，便见$N四掌齐出，一招"+BLINK""+HIY"「金顶佛光」"NOR"不知哪两掌是实？掌风已经袭面",
	"force" : 70,
	"dodge" : -10,
	"damage_type" : "内伤",
	"lvl"   : 55,
]),
([	  "skill_name" : "梵心降魔" ,
	"action" : "$N一幅宝像庄严，使出"+BLINK""+HIM"「梵心降魔」"NOR"，掌势如虹，绕着$n漂移不定",
	"force" : 80,
	"parry" : 10,
	"dodge" : 10,
	"damage_type" : "内伤",
	"lvl"   : 66,
]),
([	  "skill_name" : "法尊八荒" ,
	"action" : "$N全场游走，双臂疾舞，化为点点掌影，一招"+BLINK""+HIC"「法尊八荒」"NOR"铺天盖地袭向$n全身各处大穴",
	"force" : 90,
	"parry" : -20,
	"dodge" : -30,
	"damage_type" : "内伤",
	"lvl"   : 77,
]),

});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练金顶绵掌必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
if ( me->query("class")!="human" )
        return notify_fail("你不是人界的人，还是作罢。\n");
if ( me->query("family/family_name")!="峨嵋派" 
  && me->query_skill("jinding-zhang",1)<350 )
	return notify_fail("你的金顶绵掌火候还不到家。\n");
if( (int)me->query("sen") < 30)
	return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
if( (int)me->query("kee") < 30 )
	return notify_fail("你现在手足酸软，休息一下再练吧。\n");
if( (int)me->query("force") < 10 )
	return notify_fail("你的内力不够了。\n");
me->receive_damage("kee", 20);
me->add("force", -5);
return 1;
}

string perform_action_file(string action)
{
return CLASS_D("emei") +"/jinding-zhang/" + action;
}


