// qingna-shou 大擒拿手 Zine Dec 9 2010

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N两眼圆睁，一式「降龙伏虎」，左手弹出，抓向$n的$l",
	"force" : 90,
    "dodge" : 5,
	"lvl" : 0,
	"skill_name" : "降龙伏虎",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N徒然跃起，一招「擒狮搏象」，双手扣向$n的$1",
	"force" : 100,
        "dodge" : 10,
	"lvl" : 8,
	"skill_name" : "擒狮搏象",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N招式突然变得无比细密，使一招「巧手八打」，双手交相地向$n的$l攻去",
	"force" : 120,
        "dodge" : 15,
	"lvl" : 20,
	"skill_name" : "巧手八打",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N佯装跌到，一招「跌倒金刚」撞向$n的$l",
	"force" : 120,
        "dodge" : 20,
	"lvl" : 40,
	"skill_name" : "跌倒金刚",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「金龙探爪」，五指如钩，划向$n的$l",
	"force" : 100,
        "dodge" : 25,
	"lvl" : 48,
	"skill_name" : "金龙探爪",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N平地弹起尺许，一记「白马翻蹄」，双手扭住$n的$1",
	"force" : 120,
        "dodge" : 20,
	"lvl" : 62,
	"skill_name" : "白马翻蹄",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手互抚，一记「鲤鱼托鳃」，抓向$n的面部",
	"force" : 125,
        "dodge" : 21,
	"lvl" : 88,
	"skill_name" : "鲤鱼托鳃",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N大开大阖，只攻不守，一记「七星聚会」，双手击向$n的$1",
	"force" : 250,
        "dodge" : 20,
	"lvl" : 90,
	"skill_name" : "七星聚会",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N闭紧双眼，一记「洛钟东应」，双手如有神助的扣向$n的$1",
	"force" : 150,
        "dodge" : 30,
	"lvl" : 100,
	"skill_name" : "洛钟东应",
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
    int i, level;
	level   = (int) me->query_skill("qinna-shou");
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
    
}



int practice_skill(object me)
{
    if ((int)me->query("qi") < 200)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练习大擒拿手。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
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

//分筋错骨的综合概率D级（从E+升级到D级）
mixed hit_ob(object me, object victim)
{
    if( F_KUNGFU->hit_rate( me->query_dex(), victim->query_dex(), 18, me, victim) ||
    	  random(10)>6 ||
    	  F_KUNGFU->hit_rate( me->query("combat_exp"), victim->query("combat_exp"), 18, me, victim) )
    {
        F_KUNGFU->hit_busy( "fenjin", 1+random(2), victim );
        return YEL "$n见$N招式虚虚实实，不由心中疑惑不定，刹那间已被$N抓住！\n" NOR;
    }
    if( F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 18, me, victim) )
    {
        F_KUNGFU->hit_busy( "fenjin", 2+random(2), victim );
        return HIR "$N见招破招，以刚治刚，瞬间扣住$n脉门！\n" NOR;
    }    
    me->add("neili", -100);
}
