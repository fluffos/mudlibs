//lingshe_zhangfa.c 灵蛇杖法
#include "ansi.h"
inherit SKILL;
mapping *action = ({
([      "action": "$N使出一招「灵蛇出洞」，手中$w大开大阖扫向$n的$l",
        "force" : 100,
        "dodge": -3,
        "damage": 18,
        "lvl" : 1,
        "skill_name" : "灵蛇出洞",
        "damage_type": "挫伤"
]),
([      "action": "$N手中$w阵阵风响，一招「摇头摆尾」向$n的$l攻去",
        "force" : 140,
        "dodge": -5,
        "damage": 24,
        "lvl" : 20,
        "skill_name" : "摇头摆尾",
        "damage_type": "挫伤"
]),
([      "action": "$N举起$w，居高临下使一招「灵蛇下涧」砸向$n的$l",
        "force" : 180,
        "dodge": -10,
        "damage": 30,
        "lvl" : 30,
        "skill_name" : "灵蛇下涧",
        "damage_type": "挫伤"
]),
([      "action": "$N一招「灵蛇挺身」，手中$w猛烈扫向$n的$l",
        "force" : 220,
        "dodge": -5,
        "damage": 36,
        "lvl" : 40,
        "skill_name" : "灵蛇挺身",
        "damage_type": "挫伤"
]),
([      "action": "$N使出一招「蛇游蟒走」，$w左右迂回向$n的$l扫去",
        "force" : 260,
        "dodge": -3,
        "damage": 42,
        "lvl" : 50,
        "skill_name" : "蛇游蟒走",
        "damage_type": "挫伤"
]),
([      "action": "$N手中$w一挥，使出一招「蛇缠左右」，忽左忽右扫向$n的$l",
        "force" : 300,
        "dodge": -5,
        "damage": 48,
        "lvl" : 60,
        "skill_name" : "蛇缠左右",
        "damage_type": "挫伤"
]),
([      "action": "$N使出一招「巨蟒下山」，高举手中$w，劈头砸向$n的$l",
        "force" : 340,
        "dodge": -10,
        "damage": 54,
        "lvl" : 80,
        "skill_name" : "巨蟒下山",
        "damage_type": "挫伤"
]),
([      "action": "$N使出一招「灵蛇出洞」，手中$w猛一探，直扫$n的$l",
        "force" : 380,
        "dodge": -3,
        "damage": 60,
        "lvl" : 100,
        "skill_name" : "灵蛇出洞",
        "damage_type": "挫伤"
]),
});
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level, rstime;
        level   = (int) me->query_skill("lingshe-zhangfa",1);
		// 蛇阵给予的朱红蛇血攻击加成
		rstime = (int) me->query_temp("baituo_redsnake/time"); 
        if ( rstime && time() < rstime && me->query("neili") > 100 && random(2) ){
                me->add("neili", -50-random(50));
                return ([
                "action": HIR"$N"HIR"浑身冒出腾腾热气，大喝一声，手中$w"HIR"以摧枯拉朽之势，狠狠砸向$n的$l"NOR,
				"force" : 500,
                "dodge": 40,
                "damage": ((level>600)?level:600),
                "damage_type": "挫伤"]);
        }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
//      return action[random(sizeof(action))];
}
int valid_enable(string usage) 
{ 
    return (usage == "staff") || (usage == "parry") ;
}

int valid_learn(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query_skill("hamagong", 1) < 20)
                return notify_fail("你的蛤蟆功火候不够，无法练灵蛇杖法。\n");
        if ((int)me->query("max_neili") < 70)
                return notify_fail("你的内力不够。\n");
        return 1;
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练灵蛇杖法。\n");
        me->receive_damage("qi", 20);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object weapon;
		int poison,pflv,lv;
        weapon = me->query_temp("weapon"); 
		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "白驼山") 
			pflv=0;
		lv = me->query_skill("poison",1);
        if( (random(lv) > 50 ) && ( (string)weapon->query("id") == "she zhang" ) )
        {
            //victim->set_temp("death_cond_origin/snake_poison", me);
			F_POISON->poison_attack(me,victim,"snake_poison", random(lv/20) + 1 +
                                    victim->query_condition("snake_poison"));
            tell_object(victim, HIG "你觉得被击中的地方一阵麻木！\n" NOR );
            tell_object(victim, HIG "原来是被杖头窜出的毒蛇咬了一口！\n" NOR );
        }
        if( random(lv) > 80 && ( pflv>=3 || (string)weapon->query("id") == "guai shezhang" ) )
        {
			if (pflv>=3)
			{
				if ( F_KUNGFU->hit_rate( me->query_skill("staff","lingshe-zhangfa"), victim->query_skill("parry"), 10, me, victim) )
				{
					poison = random(lv/12) + 1 ;
					message_vision(HIM"只见"+weapon->query("name")+HIM"上突然蹿出一条怪蛇，在$N身上狠狠地咬了一口。\n"NOR, victim);
					tell_object(victim, HIR "你感觉被咬之处有些麻木，伸手用力一捏，竟然丝毫没有知觉！\n" NOR );
					F_POISON->poison_attack(me,victim,"btgs_poison", poison + victim->query_condition("btgs_poison") );
					victim->set_temp("btgs_poison/pflv", pflv);
					if (wizardp(me)) tell_object(me, "snake poison : btgs_poison " + poison +"\n");
				}
			}
			else if (weapon->query("snake") == 1)
			{
				poison = random(lv/20) + 1 ;
                //victim->set_temp("death_cond_origin/bt_poison", me);
				F_POISON->poison_attack(me,victim,"bt_poison", poison+ victim->query_condition("bt_poison"));
                tell_object(victim, HIC "只见"+weapon->query("name")+HIC"上突然蹿出一条毒蛇向你一口咬来。\n" NOR );
                tell_object(victim, HIC "结果你躲闪不及被杖头窜出的毒蛇咬了一口！\n" NOR );
                if (wizardp(me)) tell_object(me,"snake poison : bt_poison " + poison +"\n");
			}
			else if (weapon->query("snake") == 2)
            {
                poison = random(lv/12) + 1 ;
                //victim->set_temp("death_cond_origin/bt_poison", me);
				F_POISON->poison_attack(me,victim,"bt_poison", poison+ victim->query_condition("bt_poison") );
                tell_object(victim, HIC "只见"+weapon->query("name")+HIC"上突然蹿出两条毒蛇向你咬来。\n" NOR );
                tell_object(victim, HIC "结果你躲闪不及被杖头窜出的毒蛇咬了一口！\n" NOR );
                if (wizardp(me)) tell_object(me,"snake poison: bt_poison " + poison +"\n");
			}
		}
}
string  perform_action_file(string action)
{
        return __DIR__"lingshe-zhangfa/" + action;
}
int after_parry(object me, object target, string attack_skill)
{
	int ap, dp, poison, pflv, lv;
	object weapon;
	if (!objectp(me) || !objectp(target)) 
		return 0;
	weapon = me->query_temp("weapon"); 
	if (!weapon || weapon->query("skill_type") != "staff" ) 
		weapon = me->query_temp("secondary_weapon"); 
	if (!weapon || weapon->query("skill_type") != "staff" ) 
		return 0;
	pflv = (int)me->query("purefamily/level");
	if (pflv>=3 && me->query("purefamily/family_name") == "白驼山")// 入室弟子 特效
	{
		ap = (int)me->query_skill("parry", "lingshe-zhangfa");
		dp = (int)target->query_skill("dodge");
		if (F_KUNGFU->hit_rate(ap, dp, 12-pflv, me, target)) 
		{
			message_vision(HIM"只见"+weapon->query("name")+HIM"上突然蹿出一条怪蛇来，$n变招不及，被它探头狠狠地咬了一口。\n"NOR, me, target);
			tell_object(target, HIR "你感觉被咬之处有些麻木，伸手用力一捏，竟然丝毫没有知觉！\n" NOR );
			lv = me->query_skill("poison",1);
			poison = random(lv/12) + 1 ;
			F_POISON->poison_attack(me,target,"btgs_poison", poison + target->query_condition("btgs_poison") );
			target->set_temp("btgs_poison/pflv", pflv);
            if (wizardp(me)) tell_object(me,"snake poison: btgs_poison " + poison +"\n");
		}
	}
	return 1;
}
