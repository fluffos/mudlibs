// Yinyang-zhang.c 阴阳回旋掌
// Cracked by 凌惊雪 4-22-2003

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([     "action" : "$N两手外伸，双掌运出八成刚劲由外向内一合，漫天气劲将空气一压一放，立即带出了隐隐雷声，气劲随着$N的手，霎时往$n前方三公尺内集中。"NOR,
        "force" : 80,
       "dodge" : 10,
        "parry" : 10,
        "damage_type" : "内伤"
]),
([      "action" : "$N两掌一扬，一掌刚、一掌柔，阴阳两股力道向着$n直放了出去。。"NOR,
        "force" : 100,
       "dodge" : 10,
        "parry"    :   5,
        "damage_type" : "内伤"
]),
([      "action" : "$N两掌一出，阴阳两劲随掌向外而冲，两种劲力居然未能融合为一，正巧让敌人由劲力中间的缝隙穿入，却见$n在半空中急旋了起来。"NOR,
        "force" : 120,
        "dodge" : -5,
        "parry"    :   10,
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌一圈，刚柔分流，阴阳两劲由左右双掌奔腾而出；$n懵然不知，双掌聚力迎了过来，与阴阳两劲一接，当场一掌击空，不受控制的旋转起来。"NOR,
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌一凝，全力向上一送，四阴六阳，两股掌力破空而上，这时两股气劲已经急旋了起来，轰然一声爆响，炸向$n。"NOR,
        "force" : 160,
        "dodge" : 10,
        "parry" : 10,
        "damage_type" : "内伤"
]),
([      "action" : "$N体内阴阳劲力忽然分流，各循一掌奔腾而出，同时将双手往内一折，两劲一接触，随即开始交缠起来，攻向$n"NOR,
        "force" : 180,
        "dodge" : 15,
        "parry" : 15,
        "damage_type" : "内伤"
]),
([      "action" : "$N心念电转，一面抽身往后飞退，一面两掌全力推出劲力，光影散发成罩，牢牢的罩住$n。"NOR,
        "force" : 200,
        "dodge" : 5,
        "parry" : 15,
        "damage_type" : "内伤"
]),
});


int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练阴阳回旋掌必须空手。\n");
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
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("sen", 20);
	me->receive_damage("kee", 20);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("sanxian") + "/yinyang-zhang/" + func;
}
