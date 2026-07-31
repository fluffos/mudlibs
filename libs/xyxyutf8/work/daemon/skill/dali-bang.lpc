//【哭丧棒】kusang-bang.c

/*
大力棒    dodge  10    parry  -10    damage  30
棒号大力，力大势猛，急难招架
*/
#include <ansi.h>
#include <combat.h>
inherit SKILL;

mapping *action = ({
        ([      "name":                 "六丁开山",
                "action": "$N发出一声厉叫，手中$w以一招「六丁开山」，带着呼呼风声向$n的$l砸去。\n",
                "dodge":                10,
		"parry":		-10,
                "damage":               80,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "混沌初破",
                "action": "$N身形一转，一招「混沌初破」使出，周围丈内土石乱飞，霹雳间$w已砸向$n的$l，躲也躲不开了。\n",
                "dodge":                15,
		"parry":		-20,
                "damage":               85,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "翻江搅海",
                "action": "$N舞动$w，一式「翻江搅海」，劈头盖脸的向$n的$l砸去。\n",
                "dodge":                15,
		"parry":		0,
                "damage":               90,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "八方风雨",
                "action": "$N舞动$w，使出「八方风雨」，幻出了无数$w向$n砸去。\n",
                "dodge":                0,
		"parry":		-10,
                "damage":               95,
                "damage_type":  "砸伤"
        ]),
});

mapping *action2 = ({
        ([      "name":                 "无尽妖云",
                "action": HIB"$N"HIB"手中$w"HIB"卷起层层妖云，铺天盖地向$n"HIB"的$l砸去！\n"NOR,
                "dodge":                -10,
		"parry":		-20,
                "force":               120,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "混沌初破",
                "action": YEL"$N"YEL"身形一转，一招「混沌初破」使出，周围丈内土石乱飞，妖气弥漫，冷不丁$w"YEL"已砸向$n"YEL"的$l，真是神鬼莫测！\n"NOR,
                "dodge":                10,
		"parry":		-10,
                "force":               125,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "翻江搅海",
                "action": RED"$N"RED"舞动$w"RED"，一式「翻江搅海」，搅起无尽妖气，劈头盖脸的向$n"RED"的$l砸去！\n"NOR,
                "dodge":                5,
		"parry":		-20,
                "force":               130,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "八方妖云",
                "action": MAG"$N"MAG"双手舞动如风，幻出了无数$w"MAG"夹带着凄厉的啸声砸向$n"MAG"$l！\n"NOR,
                "dodge":                0,
		"parry":		-10,
                "force":               150,
                "damage_type":  "砸伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_maxforce() < 100 )
                return notify_fail("你的内力不够，没有办法练大力棒。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根大棒子。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	i = me->query_temp("WJ_perform");
	if( i>0 )
	{
		if( i>sizeof(action2) )
			i = sizeof(action2);
		return action2[i-1];
	}
	else	return action[random(sizeof(action))];
}

varargs int practice_skill(object me,int flag)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习大力棒。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
	if ( flag )        write("你按着所学练了一遍大力棒。\n");
        return 1;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("dali-bang", 1) > 30 
	 && (int)me->query_skill("dali-bang", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 50);
	}
}

string perform_action_file(string func)
{
return CLASS_D("kusong") + "/dali-bang/"+func;
}

string query_parry_msg(object me,object target)
{
	string *msg;
	if( !me || !target )
		return 0;
	if( !me->query_temp("weapon") )
		return 0;
	msg = ({
		"结果$n发出一声厉叫，手中$W「镗」的一声挡开了。\n",
                "结果$n身形一转，周围丈内土石乱飞，“轰”的一声给挡开了。\n",
                "结果被$n舞动$W给格开了。\n",
                "结果被$n幻出了无数$W格开了多远。\n",
	});
	return msg[random(sizeof(msg))];
}