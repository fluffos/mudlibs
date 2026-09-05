// cuixin-zhang.c 摧心掌
//Made By:lianxing
inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N使一招[碎石掌]，左手虚恍，右手往$n的上身劈去。",
	"force" : 200,
	"dodge" : -5,
        "damage" : 5,
	"skill_name" : "碎石掌",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双掌齐出，一式「震山掌」，一左一右向$n的双肩劈去。",
	"force" : 250,
	"dodge" : -5,
        "damage" : 5,
	"skill_name" : "震山掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使出「辟地掌」双掌同时推出，左掌推向$n的下盘，右掌击向$n的前胸。",
	"force" : 300,
	"dodge" : -5,
        "damage" : 5,
	"skill_name" : "辟地掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N飞向空中，一记「开天掌」，由上而下猛的击向$n。",
	"force" : 350,
	"dodge" : 5,
	"skill_name" : "开天掌",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N施出「摧心掌」，身如鬼魅，簌地潜到$n的身前，双掌向$n的胸膛拍去。",
	"force" : 400,
	"dodge" : 10,
        "damage" : 5,
	"skill_name" : "摧心掌",
        "damage_type" : "瘀伤"
])
});

/*mapping query_action(object me)
{	int skill=me->query_skill("jiuyin-baiguzhao",1);
        if (random(me->query_skill("claw")) > 60 &&
            me->query_skill("force") > 60 &&
            me->query("neili") > 200 ) {
                me->add("neili", -100);
				
                return ([
                "action": "$N右手向前一升，从一个不可思议的角度向$n的天灵盖抓去。",
                "force": 500,
		"damage": 200,
                "damage_type": "瘀伤"]);
        }
	
		
        return action[random(sizeof(action))];
}
*/
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jiuyin-baiguzhao";}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练摧心掌必须空手。\n");
        if ((int)me->query_skill("bihai-shengong", 1) < 30&&(int)me->query_skill("jiuyin-shengong",1)<30)
		return notify_fail("你的内功火候不够，无法学摧心掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练摧心掌。\n");
	return 1;
}

//mapping query_action(object me, object weapon)
//{
//	return action[random(sizeof(action))];
//}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练摧心掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}


string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
	"$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打空了似的，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    int eff;
    if (me->query("jiuyin_4"))
    {
    
    eff=(int)me->query_str()*10+1;
    
    if (!random(3))
        {
            message_vision(HIM+"$N大喝一声，掌掌往$n要害地方招呼，$n一个不慎，终于被打中一招。\n"+NOR,me,victim);
            F_KUNGFU->hit_wound("qi", eff, eff, me, victim);
        }
    return 1;
    }
}