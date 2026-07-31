// kuangfeng-jianfa 狂风剑法
// Updated by Lonely

#include <ansi.h>
inherit SKILL;

string *action_msg = ({
	"$N握紧手中$w一招[37m「大风起兮」[0m点向$n的$l",
	"$N一招[1;34m「天昏地暗」[0m，无数$w上下刺出，直向$n逼去",
	"$N向前跨上一步，手中$w使出[1;33m「剑气封喉」[0m直刺$n的喉部",
	"$N虚恍一步，使出[36m「虚中有实」[0m手中$w直刺$n的喉部",
	"只见$N抡起手中的$w，使出[31m「[1;33m光[1;35m芒[35m万[1;31m丈[31m」[0m万点金光直射$n",
	"$N抡起手中的$w，使出[1;35m「狂风乱剑」[0m无数剑光直射$n",
	"$N使出[37m「乱舞狂风」[0m，手中$w如刮起狂风一般闪烁不定，刺向$n",
	"$N使出狂风剑法之绝技[37m「狂风肆虐」[0m，手中$w如刮起狂风一般铺天盖地的刺向$n",
	HIY "$N使出狂风剑法之最终绝技「人剑合一」，整个人化作一把金剑飞向$n" NOR,
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
    	if ((int)me->query("max_neili") < 300)
        	return notify_fail("你的内力不够。\n");
    	if ((int)me->query_skill("force", 1) < 60)
        	return notify_fail("你的内功心法火候太浅。\n");
    	if ((int)me->query_skill("dodge", 1) < 60)
        	return notify_fail("你的轻功火候太浅。\n");
    	if ((int)me->query_dex() < 25)
        	return notify_fail("你的身法还不够灵活。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	return ([
		"action": action_msg[random(sizeof(action_msg))],
		"damage": 120 + random(50),
		"attack": 70 + random(10),
		"dodge" : 70 + random(10),
		"parry" : 70 + random(10),
		"damage_type" : random(2)?"刺伤":"割伤",
	]);
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练「狂风剑法」。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练「狂风剑法」。\n");
        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuangfeng-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
	mixed result; 

        if (damage < 100) return 0;

        if (random(damage / 2) > 30) 
        {
        	result = ([ "damage": damage / 2 ]);                 
                result += (["msg" : HIR "你听到「唰」一声轻响好像凉一阵风吹过，忽然间$n血冒三丈，被$N" HIR "剑气所伤！\n" NOR]);
                return result;
        }
}


