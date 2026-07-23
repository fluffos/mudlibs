// shenzhao-jing.c 神照经
#include <ansi.h>
inherit FORCE;

void create() { seteuid(getuid()); }

//string type() { return "knowledge"; }

int valid_learn(object me)
{
	int lev;

	lev = (int)me->query_skill("shenzhao-jing", 1);

	if (!me->query("szj/passed"))
		return notify_fail("你试图学习神照经，但似乎毫无进展。\n");
	if (!me->query("szj/over200") && lev > 200)
		return notify_fail("由于你任督二脉未通，无法修习更高深的神照经心法。\n");
	if ((int)me->query_skill("force", 1) < 150)
		return notify_fail("你的基本内功火候不够，无法学习神照经心法。\n");
	if (lev > (int)me->query_skill("force", 1))
		return notify_fail("你的基本内功火候不够，无法学习神照经心法。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("神照经只能靠学习来提高。\n");
}


void skill_improved(object me)
{
	tell_object(me, HIW"\n随着神照经的提高，你突然发现丹田里的内息更加充沛！\n\n"NOR);
	me->add("max_neili", 1 + random(2));
}
mapping *action = ({
([      "action" : "$N倏然跃近，击出一拳，这一拳无声无影，去势快极，向$n的胸口打去",
        "dodge"  : 81,
        "force"  : 323,
        "attack" : 119,
        "parry"  : 94,
        "damage" : 268,
        "lvl"    : 0,
        "damage_type": "内伤" 
]), 
([      "action" : "$N丝毫不动声色，右掌平伸，左掌运起神照经神功的劲力，呼的一声拍向$n",
        "dodge"  : 73,
        "force"  : 362,
        "attack" : 138,
        "parry"  : 51,
        "damage" : 273,
        "lvl"    : 200,
        "damage_type": "内伤"
]), 
([      "action" : "$N身形微微一展，已然游走至$n跟前，陡然间双掌齐施，向$n猛拍而去",
        "dodge"  : 78,
        "force"  : 389,
        "attack" : 152,
        "parry"  : 53,
        "damage" : 87,
        "lvl"    : 220,
        "damage_type": "内伤"
]),
([      "action" : "$N退后一步，双掌回收，凌空划出一个圆圈，顿时一股澎湃的气劲直涌$n而出",
        "dodge"  : 75,
        "force"  : 410,
        "attack" : 163,
        "parry"  : 67,
        "damage" : 293,
        "lvl"    : 250,
        "damage_type": "内伤"
]), 
});

int valid_enable(string usage)
{ 
        int lvl;
        lvl = (int)this_player()->query_skill("shenzhao-jing", 1);

        if(lvl >= 180)    
                return usage == "force" || usage == "unarmed" || usage == "parry";
        else
                return usage == "force";
       
}mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("shenzhao-jing", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 50, level)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("shenzhao-jing", 1);

        if (damage_bonus < 60
           || lvl < 180
           || me->query("neili") < 300
           || me->query_temp("weapon")
           || me->query_temp("secondary_weapon")
           || me->query_skill_mapped("force") != "shenzhao-jing"
           || me->query_skill_mapped("unarmed") != "shenzhao-jing"
           || me->query_skill_prepared("unarmed") != "shenzhao-jing")
                return 0;

        // 神照经神功所具有的既添设额外伤害又使对手中
        // 毒的max_hit 在所有武功中是绝无仅有的，但是
        // 它出现的几率以及伤害值又及毒性伤害相对于其
        // 他武功大大减弱。
        if (damage_bonus / 6 > victim->query_con() || random(10)==0)
        {
               	victim->receive_wound("qi", (damage_bonus - 60) / 3+10, me);
                victim->receive_damage("qi", (damage_bonus - 60) / 3+10, me);
                victim->apply_condition("shenzhao",20);
               	return HIR "$n" HIR "一声惨嚎，全身骨骼格格格格爆声不"
                       "绝，肋骨、臂骨、腿骨同时断折。\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"shenzhao-jing/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"shenzhao-jing/exert/" + action;
}
