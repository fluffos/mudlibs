// wuxian-bianfa.c 五仙鞭法 笑傲江湖中五毒教和铁手的功夫
//zine
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([	"action" : "$N向前轻上一步，一招“黄沙万里”，手中$w卷起无数鞭影，绕向$n的前胸",

	"force" : 150,
	"dodge" : 5,
	"damage" : 20,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N身形诡异，使出一式“软虹蛛索”，手中$w弯弯绕绕直如蛛丝缕缕，裹向$n",

	"force" : 180,
	"dodge" : 15,
	"damage" : 20,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招“蝎尾鞭”，手中$w倒抽，闪电般地劈向$n的头部",
	"force" : 200,
	"dodge" : 10,
	"damage" : 30,
        "lvl" : 29,
	"damage_type" : "割伤"
]),
([	"action" : "$N使出一式“含沙射影”，手中的$w变成碎碎小点，漫天刺向$n",

	"force" : 200,
	"dodge" : 10,
	"damage" : 50,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),	
([	"action" : "$N使出“金蛇狂舞”，只见$w化为一道金蛇，离开$N身体飘向划向$n",

	"force" : 250,
	"dodge" : 50,
	"damage" : 150,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),
([	"action" : "$N吐出真气，手中$w挥出，只见一道鞭光，由下而上向$n的颈部绕去，正是一式“盘蛇残影”",

	"force" : 240,
	"dodge" : 5,
	"damage" : 60,
        "lvl" : 49,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招“金蟾吐艳”，手中$w猛地变长变粗，击向$n的小腹",
	"force" : 260,
	"dodge" : 5,
	"damage" : 90,
        "lvl" : 79,
	"damage_type" : "刺伤"
]),
([	"action" : "$N面带不屑，一式“百足之虫”，手中$w如滔滔江水，绵绵不绝地涌向$n",
	"force" : 300,
	"dodge" : -5,
	"damage" : 100,
        "lvl" : 119,
	"damage_type" : "刺伤"
]),
});

mapping *action2 = ({
([	"action" : "$N"+HIY+"向前轻上一步，一招“黄沙万里”，手中"+NOR+"$w"+HIY+"卷起无数鞭影，绕向"+NOR+"$n"+HIY+"的前胸"+NOR,

	"force" : 250,
	"dodge" : 15,
	"damage" : 40,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N"+HIW+"身形诡异，使出一式“软虹蛛索”，手中"+NOR+"$w"+HIW+"弯弯绕绕直如蛛丝缕缕，裹向"+NOR+"$n",

	"force" : 280,
	"dodge" : 25,
	"damage" : 30,
        "lvl" : 9,
	"damage_type" : "刺伤"
]),
([	"action" : "$N"+HIR+"一招“蝎尾鞭”，手中"+NOR+"$w"+HIR+"倒抽，闪电般地劈向"+NOR+"$n"+HIR+"的头部"+NOR,
	"force" : 300,
	"dodge" : 30,
	"damage" : 50,
        "lvl" : 29,
	"damage_type" : "割伤"
]),
([	"action" : "$N"+YEL+"使出一式“含沙射影”，手中的"+NOR+"$w"+YEL+"变成碎碎小点，漫天刺向"+NOR+"$n",

	"force" : 340,
	"dodge" : 40,
	"damage" : 350,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),	
([	"action" : "$N"+HIY+"使出“金蛇狂舞”，只见"+NOR+"$w"+HIY+"化为一道金蛇，离开"+NOR+"$N"+HIY+"身体飘向划向$n"+NOR,

	"force" : 250,
	"dodge" : 80,
	"damage" : 60,
        "lvl" : 39,
	"damage_type" : "刺伤"
]),
([	"action" : "$N"+CYN+"吐出真气，手中$w挥出，只见一道鞭光，由下而上向"+NOR+"$n"+CYN+"的颈部绕去，正是一式“盘蛇残影”"+NOR,

	"force" : 340,
	"dodge" : 5,
	"damage" : 90,
        "lvl" : 49,
	"damage_type" : "刺伤"
]),
([	"action" : "$N"+HIY+"一招“金蟾吐艳”，手中"+NOR+"$w"+HIY+"猛地变长变粗，击向"+NOR+"$n"+HIY+"的小腹"+NOR,
	"force" : 360,
	"dodge" : 50,
	"damage" : 100,
        "lvl" : 79,
	"damage_type" : "刺伤"
]),
([	"action" : "$N"+BLU+"面带不屑，一式“百足之虫”，手中"+NOR+"$w"+BLU+"如滔滔江水，绵绵不绝地涌向"+NOR+"$n",
	"force" : 360,
	"dodge" : -5,
	"damage" : 200,
        "lvl" : 119,
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("你的内功火侯太浅。\n");
	
	return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("wuxian-bianfa",1);
        if (level>500)
        {
            return action2[random(sizeof(action2))];
        }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
        
}

int practice_skill(object me)
{
	object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练五仙鞭法。\n");
    if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练五仙鞭法。\n");
	me->receive_damage("qi", 30);
    me->add("neili", -5);
	return 1;
}
string perform_action_file(string action)
{
        if ( this_player()->query_skill("wuxian-bianfa", 1) >= 50 )
                return __DIR__"wuxian-bianfa/" + action;
}


string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}