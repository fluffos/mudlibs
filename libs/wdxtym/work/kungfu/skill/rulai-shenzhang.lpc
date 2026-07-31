#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
        HIY "$n双掌合十，脸现庄严之色，$N立刻匍匐在地，虔诚膜拜。"NOR"\n" ,
});

mapping *action = ({
([      "action": HIW "$N微笑而立，左掌合十，右掌往$n缓缓印去" NOR ,
        "attack" : 500,
        "force" : 500,
        "parry" : 500,
        "dodge" : 500,
        "damage": 500,
        "lvl" : 0,
        "skill_name" : "如来神掌",
        "damage_type":   "瘀伤"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "unarmed" || usage == "parry" 
           || usage == "strike" ;
}

string query_skill_name(int level)
{
        return action[0]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        return action[0];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[0];
}

int valid_learn(object me)
{	
	if ( ! wizardp(me))
        return notify_fail("［如来神掌］神功只能由巫师学习。\n");
}


string perform_action_file(string action)
{
	return __DIR__"rulai-shenzhang/" + action;
}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if ( ! userp (victim)) 
	if ( living (victim)) victim -> unconcious () ;
}

*/

/*
int ob_hit(object me, object victim, int damage)
{
	int skill = me->query_skill("force");
	int skill2= victim->query_skill("force");
	int neili = me->query("neili");
	int neili2= victim->query("neili");
	int i = 1;
	string msg;

	if ( random(skill) > skill2/100 ) {

		if( random(3000)>1 ) {
			msg = HIW"$N"+HIW+"挥挥手，化去了$n"HIW;
			if(neili > neili2/10) {
				msg += "大部分的伤害！"NOR"\n";
				i = -(damage/2 + random(damage/2));
			}

			else {
				if(neili < neili2/2) {
					msg += "很少的一点伤害！"NOR"\n";
					i = -random(damage/4);
				}
				else {
					msg += "一部分的伤害！"NOR"\n";
					i = -random(damage/2);
				}
			     }

			if( objectp(me) && objectp(victim) )
				message_vision(msg, me, victim);	
		}
             }

	return i;

}
*/