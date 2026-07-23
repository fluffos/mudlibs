
inherit SKILL;

mapping *action = ({
	([	"action":		"$N一招看似平淡无奇的「空山灵雨」，$w变的如一团雨丝向$n落去！",
		"damage":		70,
		"dodge":		70,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N天人合一，内外交融，手中$w象幽灵般刺向$n的$l！",
		"damage":		40,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w幻出一片刀花，分刺$n的身法中的数处破绽。",
		"damage":		20,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N飞身而起，手中的$w幻出一片刀光，，忽然反手一刀横斩$n的$l！",
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中的$w光芒暴长，使出「谁是英雄」，如雷霆万钧砍向$n的$l！",
		"damage":		70,
		"damage_type":	"割伤"
	]),
	
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力不够，没有办法练蝙蝠刀法\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能练刀法。\n");
        return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀，才能练刀法。\n");

	if( (int)me->query("jing") < 40 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("jing", 40);
	return 1;
}
int effective_level() { return 20;}

string *parry_msg = ({
       "$n刀法又是一变，$v发出阴冷的寒气逼得$N连退数步。\n",
	"$n刀势陡然有了几分魔意，令$N的攻势顿时慢了下来。\n",
});

string *unarmed_parry_msg = ({
       "$n刀法又是一变，$v发出阴冷的寒气逼得$N连退数步。\n",
	"$n刀势陡然有了几分魔意，令$N的攻势顿时慢了下来。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return -100;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 30;
}

string perform_action_file(string action)
{
        return __DIR__"bat-blade/" + action;
}


