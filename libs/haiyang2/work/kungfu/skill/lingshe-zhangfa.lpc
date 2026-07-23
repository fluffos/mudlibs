//lingshe_zhangfa.c 灵蛇杖法

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action": "$N使出一招"+(order[random(13)])+"「灵蛇出洞」"NOR"，手中$w大开大阖扫向$n的$l",
	"force" : 150,
	"dodge": 50,
	"damage": 150,
	"lvl" : 1,
	"skill_name" : "灵蛇出洞",
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w阵阵风响，一招"+(order[random(13)])+"「摇头摆尾」"NOR"向$n的$l攻去",
	"force" : 200,
	"dodge": 50,
	"damage": 200,
	"lvl" : 20,
	"skill_name" : "摇头摆尾",
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招"+(order[random(13)])+"「灵蛇下涧」"NOR"砸向$n的$l",
	"force" : 220,
	"dodge": 50,
	"damage": 230,
	"lvl" : 30,
	"skill_name" : "灵蛇下涧",
	"damage_type": "挫伤"
]),
([	"action": "$N一招"+(order[random(13)])+"「灵蛇挺身」"NOR"，手中$w猛烈扫向$n的$l",
	"force" : 280,
	"dodge": 50,
	"damage": 236,
	"lvl" : 40,
	"skill_name" : "灵蛇挺身",
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招"+(order[random(13)])+"「蛇游蟒走」"NOR"，$w左右迂回向$n的$l扫去",
	"force" : 300,
	"dodge": 50,
	"damage": 300,
	"lvl" : 50,
	"skill_name" : "蛇游蟒走",
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w一挥，使出一招"+(order[random(13)])+"「蛇缠左右」"NOR"，忽左忽右扫向$n的$l",
	"force" : 350,
	"dodge": 50,
	"damage": 348,
	"lvl" : 60,
	"skill_name" : "蛇缠左右",
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招"+(order[random(13)])+"「巨蟒下山」"NOR"，高举手中$w，劈头砸向$n的$l",
	"force" : 440,
	"dodge":  50,
	"damage": 354,
	"lvl" : 80,
	"skill_name" : "巨蟒下山",
	"damage_type": "挫伤"
]),
([	"action": "$N使出一招"+(order[random(13)])+"「灵蛇出洞」"NOR"，手中$w猛一探，直扫$n的$l",
	"force" : 480,
	"dodge": 53,
	"damage": 400,
	"lvl" : 100,
	"skill_name" : "灵蛇出洞",
	"damage_type": "挫伤"
]),

});

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
	level   = (int) me->query_skill("lingshe-zhangfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
//	return action[random(sizeof(action))];
}

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 70)
		return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("lingshe-quan", 1) < 60)
                return notify_fail("你的灵蛇拳水平有限。\n");
        if ((int)me->query_skill("shexing-diaoshou", 1) < 60)
                return notify_fail("你的蛇形刁手水平有限。\n");
        if ((int)me->query_skill("hamagong", 1) < 50)
                return notify_fail("你的蛤蟆功不够娴熟。\n");

	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
        if ((int)me->query_skill("lingshe-quan", 1) < 60)
                return notify_fail("你的灵蛇拳水平有限。\n");
        if ((int)me->query_skill("shexing-diaoshou", 1) < 60)
                return notify_fail("你的蛇形刁手水平有限。\n");
        if ((int)me->query_skill("hamagong", 1) < 50)
                return notify_fail("你的蛤蟆功不够娴熟。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练灵蛇杖法。\n");
	me->receive_damage("qi", 20);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl,flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;
target=victim;
        level = (int) me->query_skill("hamagong",1);
        level2= (int) me->query_skill("hamagong",1);
        lvl = me->query_skill("lingshe-zhangfa",1);
        flvl = me->query_skill("lingshe-zhangfa",1);


       if (flvl * 2 + random(lvl) > victim->query_skill("force") && random(2)==0)
       {
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
	        return;
        if (!me->query_temp("weapon") )
       	        return; 
              victim->apply_condition("snake_poison",20);
              victim->add("eff_qi",-random(lvl)+1);
                return HIR "只听$n痛呼了一声，却是被蛇杖顶端的小蛇咬了个正着！\n" NOR;
       }

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "hamagong")
{
	target->apply_condition("snake_poison",5);
	target->apply_condition("chanchu_poison",5);
	target->apply_condition("qx_snake_poison",3);
if (!target->is_busy()) target->start_busy(2);	
 return HIR "$N倒转经脉，身形一变，一口毒气对着$n吐出!$n头一昏，不知所措 ！\n";
}

        if( random(me->query_skill("hamagong",1)) > 10 ) 
	{
	victim->apply_condition("snake_poison", random(me->query_skill("hamagong",1)/10) + 1 +
	victim->query_condition("snake_poison"));
        tell_object(victim, HIG "你觉得被击中的地方一阵麻木！\n" NOR );
        tell_object(victim, HIG "原来是被杖头窜出的毒蛇咬了一口！\n" NOR );
	}
if (me->query_temp("hmg_dzjm") && random(4)>2 )
{
        victim->receive_damage("qi", damage_bonus/2);
        victim->receive_wound("qi", damage_bonus/2);
 return HIR "$N倒转经脉对着$n张口一咬!$n伤口一凉，鲜血喷出！\n";
}

}

string perform_action_file(string action)
{
    return __DIR__"lingshe-zhangfa/" + action;
}
