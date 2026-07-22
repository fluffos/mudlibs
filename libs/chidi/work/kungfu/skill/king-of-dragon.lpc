#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
        HIY "$n端坐微笑，忽而脸现庄严之色，$N立刻匍匐在地，虔诚膜拜。\n" NOR ,
});
mapping *action = ({
([      "action": MAG "$N拈花微笑，周身涌起一片祥云罩向$n" NOR ,
        "force" : 0,
        "dodge" : 0,
        "damage": 0,
        "lvl" : 0,
        "skill_name" : "君临天下",
        "damage_type":   "圣光之沐"
]),
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "unarmed" || usage == "parry" 
           || usage == "blade" || usage == "whip" || usage == "force" ;
}
string query_skill_name(int level)
{
        int i;
        return action[0]["skill_name"];
}
/*
mapping query_action(object me, object weapon)
{
        int i, level;
        return action[0];
}
*/
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("king-of-dragon", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/2)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level*4;
    a_action["attack"]  = level/3;
    a_action["damage"] = level*4;
    return a_action;

}

string query_dodge_msg(string limb,object me) {
	if(me)	me->set_temp("fight/dodge",10*me->query_skill("king-of-dragon",1));
	return dodge_msg[0];
}

int valid_learn(object me) {
	return notify_fail("这项技能不能通过学习来提高。\n");
}
int invalid_yanjiu(object me) {
	return 1;
}
int invalid_closed(object me) {
	return 1;
}
int invalid_objadd(object me) {
	return 1;
}
string exert_function_file(string action) {
	return __DIR__"king-of-dragon/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus) {
	int kar_add;
	kar_add = (int)(me->query("kar") / 10000 * 0.03);
	if(damage_bonus < 100) return 0;
	if(me->query_skill("king-of-dragon",1)>100)	{    
		victim->receive_wound("qi", (int)((damage_bonus + 100)*200*(1+kar_add)) , me);
		victim->receive_wound("jing", (int)((damage_bonus + 100)*200*(1+kar_add)) , me);
	}
	return HIR "$N的"HIB"[君临天下]"HIR"摧毁了$n的真元和内力！\n" NOR;
}