// pomo-jianfa 泼墨披麻剑法
#include <ansi.h>
inherit SKILL;

mapping *action = ({

([      "action" : "$N一招「春风杨柳」，似乎没见他脚步移动，$w已向$n劈砍下去",
        "force" : 140,
        "dodge": 10,
        "damage" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出「白虹贯日」直刺$n的$l",
        "damage" : 60,
        "force" : 160,
        "dodge" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，使出「腾蛟起凤」直刺$n的$l",
       "force" : 200,
        "dodge" : 10,
        "damage" : 80,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("riyue-shengong", 1) < 20 )
                return notify_fail("你的内功等级不够。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练泼墨披麻剑法。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够练泼墨披麻剑法。\n");
        me->receive_damage("qi", 20);
        me->add("neili", -20);
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
        return __DIR__"pomo-jianfa/" + action;
}

int draw_attack(object victim,object attacker,object weapon,int attack_type,string attack_msg)
{
	object the_enemy,*enemy;
	int num,buff_cnt;
	if (victim->query_temp("active_buffer/pomo-jianfa.luanpomo")==0)
	{
		return 0;
	}
	if (victim->is_busy()&&random(2)==0)
		return 0;
	buff_cnt = victim->query_temp("pomo-jianfa.luanpomo/buff_cnt");
	num=random(100);
	if (num > buff_cnt)
		return 0;
	enemy = victim->query_enemy();
	if (sizeof(enemy)<2)
	{
		message_vision(HIR"$N受$n泼墨披麻剑法武功影响，进攻全被乱归到别处。\n"NOR,attacker,victim);
		victim->add("neili",-50-random(buff_cnt*5));
		return 1;
	}
	enemy-=({attacker});
	the_enemy=enemy[random(sizeof(enemy))];
   if (living(the_enemy))
	{	
	   if (num > buff_cnt/3)
	   {
			message_vision(HIR"$N受$n泼墨披麻剑法武功影响，进攻全被乱泼到"+the_enemy->query("name")+"身上。\n"NOR,attacker,victim);
			the_enemy->set_temp("do_attack_from", victim);
			COMBAT_D->do_attack(attacker,the_enemy,weapon,attack_type,attack_msg);
		   the_enemy->delete_temp("do_attack_from");
			victim->add("neili",-100-random(buff_cnt*5));
	   }
	   else
		{
			message_vision(HIR"$N受$n泼墨披麻剑法武功影响，进攻全被乱归到别处。\n"NOR,attacker,victim);
			victim->add("neili",-50-random(buff_cnt*5));
		}
	return 1;
	}
	return 0;
	
}