// pipa-shou 铁琵琶手 洛阳韩家武学 Zine Dec 9 2010

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N连续抢步，一式「手挥五弦」，左手不着痕迹地划向$n的$l",
	"force" : 180,
    "dodge" : 5,
	"lvl" : 0,
	"skill_name" : "手挥五弦",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左脚向后，全身倒转，一招「琵琶遮面」，似乎攻守失据，实则守中有攻",
	"force" : 200,
        "dodge" : 10,
	"lvl" : 8,
	"skill_name" : "琵琶遮面",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手大开大阖，使一招「刀枪齐鸣」，双手齐向$n的$l攻去",
	"force" : 220,
        "dodge" : 15,
	"lvl" : 15,
	"skill_name" : "刀枪齐鸣",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N空门大开，不管不顾，一手弹出，一招「铁骑突出」打向$n的$l",
	"force" : 260,
        "dodge" : 20,
	"lvl" : 24,
	"skill_name" : "铁骑突出",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「银瓶乍破」，双手划了几个圈圈，突然间大喝一声，击向$n的$l",
	"force" : 300,
        "dodge" : 25,
	"lvl" : 33,
	"skill_name" : "银瓶乍破",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手连抖，一记「流泉下山」，瞬时快如奔雷，一下子切到$n的手上",
	"force" : 360,
        "dodge" : 30,
	"lvl" : 42,
	"skill_name" : "流泉下山",
        "damage_type" : "瘀伤"
]),
});

mapping *action2 = ({
([	"action" : "$N"+YEL+"连续抢步，一式「手挥五弦」，左手不着痕迹地划向$n"+YEL+"的$l"+NOR,
	"force" : 360,
    "dodge" : 15,
	"lvl" : 600,
	"skill_name" : "手挥五弦",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N"+YEL+"左脚向后，全身倒转，一招「琵琶遮面」，似乎攻守失据，实则守中有攻"+NOR,
	"force" : 400,
        "dodge" : 20,
	"lvl" : 600,
	"skill_name" : "琵琶遮面",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N"+YEL+"双手大开大阖，使一招「刀枪齐鸣」，双手齐向$n"+YEL+"的$l攻去"+NOR,
	"force" : 420,
        "dodge" : 25,
	"lvl" : 600,
	"skill_name" : "刀枪齐鸣",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N"+YEL+"空门大开，不管不顾，一手弹出，一招「铁骑突出」打向$n"+YEL+"的$l"+NOR,
	"force" : 460,
        "dodge" : 30,
	"lvl" : 600,
	"skill_name" : "铁骑突出",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N"+YEL+"使一招「银瓶乍破」，双手划了几个圈圈，突然间大喝一声，击向$n"+YEL+"的$l"+NOR,
	"force" : 500,
        "dodge" : 35,
	"lvl" : 600,
	"skill_name" : "银瓶乍破",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N"+YEL+"双手连抖，一记「流泉下山」，瞬时快如奔雷，一下子切到$n"+YEL+"的手上"+NOR,
	"force" : 560,
        "dodge" : 50,
	"lvl" : 600,
	"skill_name" : "流泉下山",
        "damage_type" : "瘀伤"
]),
});


int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }


string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int level,i;
    if (me->query_skill("pipa-shou",1)>600)
    {
        return action2[random(sizeof(action2))];
    }
    else
    {
	    level   = (int) me->query_skill("pipa-shou");
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
    }
}



int practice_skill(object me)
{
    if ((int)me->query_skill("pipa-shou",1)>1000)
    {
        if ((int)me->query("qi") < 500)
		return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 200)
            return notify_fail("你的内力不够练铁琵琶手。\n");
        me->receive_damage("qi", 100);
        me->add("neili", -50);
        return 1;
    }
    if ((int)me->query("qi") < 200)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练铁琵琶手。\n");
	me->receive_damage("qi", 60);
	me->add("neili", -30);
	return 1;
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

string perform_action_file(string action)
{
        return __DIR__"pipa-shou/" + action;
}