// luohua-jian.c 红花十三剑
// cleansword 2/15/96
// Marz 5/21/96

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }


mapping *action = ({
([	"action" : "$N凌空飞起，挽了一个剑花,一招「水面风回聚落花」，剑
光四射就如同千万点寒星，向$n当头洒下",
	"force" : 50,
	"dodge" : 5,
	"parry" : 10,
        "damage" : 250,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N蓦的向前一纵身，左手单掌护胸，右手手腕一沉，$w向
上反撩，一式「闲敲棋子落灯花」划向$n的$l",
	"force" : 70,
	"dodge" : 2,
	"parry" : 30,
        "damage" : 260,
        "lvl" : 8,
	"damage_type" : "割伤"
]),
([	"action" : "$N口中轻叱一声，手中$w向下一点,身形向上拨起丈余，一招
「骏马行桥踏落花」$w居高临下如闪电般刺向$n的$l",
	"force" : 90,
	"dodge" : 10,
	"parry" : 40,
        "damage" : 270,
        "lvl" : 12,
	"damage_type" : "刺伤"
]),
([	"action" : "$N双脚不丁不八，身形稳如泰山，左手微屈捏成剑决，
右手$w轻颤，一式「江城五月落梅花」，只见满天银
光纷纷点点罩向$n的$l"
,
        "force" : 100,
	"dodge" : 0,
	"parry" : 40,
        "damage" : 280,
        "lvl" : 15,
	"damage_type" : "刺伤"
]),
([	"action" : "$N长吸一口真气，一招「银烛光摇半夜花」,右手$w摇
曳不定,似有似无的刺向$n,",
	"force" : 100,
	"dodge" : 10,
	"parry" : 50,
        "damage" : 290,
	"lvl" : 20,
	"damage_type" : "刺伤"
]),
([	"action" : "$N双目直视$n，左手疾伸，与右手同时握住$w，剑随意
动，一招「犹为离人照落花」，$w大开大阖，向$n的$l
直劈过去",
	"force" : 100,
	"dodge" : 10,
	"parry" : 50,
        "damage" : 300,
        "lvl" : 35,
	"damage_type" : "割伤"
]),
([	"action" : "只见$N左穿右插，剑光闪烁不定,一招「更持红烛赏残花」,$w
极快的划出一个光圈，“呜.呜..”作响，奔向$n的$l",
	"force" : 100,
	"dodge" : 5,
	"parry" : 55,
        "damage" : 310,
	"lvl" : 45,
	"damage_type" : "刺伤"
]),
([	"action" : "$N身形稍挫，一招「春城无处不飞花」反手击出,只听
“嗤”的一声，一道青光射向$n的$l",
	"force" : 100,
	"dodge" : 0,
	"parry" : 55,
        "damage" : 320,
	"lvl" : 50,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一声清叱，剑光暴长，一招「光摇银海眩生花」,攻势突
发，手中$w有如长江大河，滚滚而上，涌向$n的$l",
	"force" : 180,
	"dodge" : 15,
	"parry" : 55,
        "damage" : 330,
	"lvl" : 70,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一声长啸，右臂一振，一招「长日临池看落花」，手中$w
作龙呤之声脱手而出，$n只觉一道凌厉的剑气扑面而来",
	"force" : 200,
	"dodge" : 5,
	"parry" : 60,
        "damage" : 340,
        "lvl" : 85,
	"damage_type" : "刺伤"
]),
([
	"action" : "$N身躯一转，一招「月明残雪映梅花」,内力急吐，$w
上突的吐出尺余长的剑芒呼呼作响,划向$n的$l",
	"force" : 200,
	"dodge" : 5,
	"parry" : 60,
        "damage" : 350,
	"lvl" : 100,
	"damage_type" : "刺伤"
]), 
([      "action" : "$N双眉一扬，眼中杀气大盛，一招「化着春泥更护花」，
左脚脚尖点地，右脚迅速向前踏出一步，只见$N
与手中$w合而为一，直奔$n而去",     
        "force" : 200,
        "dodge" : 10,
        "parry" : 60,
        "damage" : 360,
        "lvl" : 120,
        "damage_type" : "刺伤"
]),
([	"action" : "$N抱元守一，运力于臂，一招「人间处处有红花」,只
见剑光闪闪，四下里剑气纵横，$n几乎要透不过气来",
	"force" : 250,
	"dodge" : -1,
	"parry" : 70,
        "damage" : 380,
	"lvl" : 150,
	"damage_type" : "刺伤"

]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("luohua-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

	return 1;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{       
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("honghua-shengong",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");
if (level >= 100)
{
        if( random(12)==1 || random(level) > 180)
        {
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) ); 
        return RED "「落花追魂!!」！$N和身下扑，手中$w下指，疾刺$n的下三路!\n" NOR;
        }
if (damage_bonus < 60) damage_bonus=60;
        if( random(12)==1 || random(level) > 90  )
        {
        victim->receive_wound("qi", damage_bonus );     
        return RED "落花追魂剑！一股鲜血从$n的身子喷出!\n" NOR;
  }
}
}


string perform_action_file(string action)
{
	return __DIR__"luohua-jian/" + action;
}
