//Cracked by Kafei
// shiba-pan.c 泰山派剑法“泰山十八盘”
// maco 1999.1.22
// testing..........

#include <ansi.h>
#include <combat.h>
inherit SKILL;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int ruhe(object me, object victim, object weapon, int damage);

mapping *action = ({
([      "action":"$N展开剑势，身随剑走，$w左边一拐，右边一弯，回旋曲折，剑路厚重沉稳，乃是「缓十八」的招数",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage": 215,
        "lvl" : 0,
        "skill_name" : "缓十八",
	"post_action": (: ruhe :),	
        "damage_type":  "割伤"
]),
([      "action":"$N五步一转，十步一回，$w剑路越转越加狠辣，将「紧十八」剑招使得险峻无比",
        "force" : 200,
        "dodge" : 5,
        "parry" : 5,
        "damage": 225,
        "lvl" : 10,
        "skill_name" : "紧十八",
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N展开剑路，刷的一声，一招「石关回马」，$w反手砍向$n$l",
        "force" : 240,
        "dodge" : 10,
        "parry" : 10,
        "damage": 225,
        "lvl" : 20,
        "skill_name" : "石关回马",
	"post_action": (: ruhe :),	
        "damage_type":  "割伤"
]),
([      "action":"$N$w一晃，向右滑出三步，一招「朗月无云」，转过身来，身子微矮，$w斜刺$n$l",
        "force" : 260,
        "dodge" : 8,
        "parry" : 8,
        "damage": 230,
        "lvl" : 20,
        "skill_name" : "朗月无云",
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N脚下连变方位，窜高伏低，忽地圈转$w，一招「峻岭横空」，$w直刺$n$l，去势奇疾",
        "force" : 260,
        "dodge" : 8,
        "parry" : 8,
        "damage": 230,
        "lvl" : 20,
        "skill_name" : "峻岭横空",
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"
]),
([      "action":"$N突然一弯腰，挺剑向$n刺到，一招「来鹤清泉」，一剑既出，二剑随至，剑招迅疾无伦",
        "force" : 330,
        "dodge" : 10,
        "parry" : 15,
        "damage": 240,
        "lvl" : 30,
        "skill_name" : "来鹤清泉",
	"post_action": (: ruhe :),	
        "damage_type":  "割伤"
]),

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        return 1;
}

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


	if(me->query_temp("ruhe_count") > 15 || me->query_temp("ruhe_hit")){
        me->add("jing", -30);	
        me->add("neili", -100);	
	me->set_temp("ruhe_finish");	
	me->delete_temp("ruhe_count");	
	me->delete_temp("ruhe_hit");	
        return ([
	"action":HIY"$N左手计算已毕，$w"+HIY"出招，正是泰山派剑法中最高深的绝艺「岱宗如何」，这一剑算准了$n的一切应变後着，实是威力无俦，博大精深"NOR,
        "force" : 450+random(20),
        "dodge" : 70,
        "parry" : 70,
        "damage": 520,
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"]);
        }
	else if((int)me->query_skill("sword",1)> random(300)+100
 	&& me->query("neili") > 200 
	&& me->query_temp("ruhe")){
        me->add("neili", -20);
        return ([
	"action":YEL"$N$w"+YEL"倏地向$n刺出，连连出剑，每一剑的剑招皆苍然有古意，招数古朴，内藏奇变，正是「五大夫剑」"NOR,
        "force" : 400+random(55),
        "dodge" : 10,
        "parry" : 15,
        "damage": 500+random(55),
        "skill_name" : "五大夫剑",
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"]);
        }

        else if((int)me->query_skill("sword",1) > random(280)+80
	&& me->query("neili") > 100
	&& me->query_temp("ruhe")){
        me->add("neili", -10);
        return ([
	"action":HIC"$N陡然向$n连环三剑，$w"+HIC"使得犹似行云流水，大有善御者驾轻车而行熟路之意，将「快活三」剑招发挥得淋漓尽致"NOR,
        "force" : 333 + random(33),
        "dodge" : 10,
        "parry" : 15,
        "damage": 500+random(33),
        "skill_name" : "快活三",
	"post_action": (: ruhe :),	
        "damage_type":  "刺伤"]);
        }


        level   = (int) me->query_skill("shiba-pan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if (me->query_skill("shiba-pan",1) < 199)
           return notify_fail("此项技能只能大于二百级时能学习。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

        return 1;
}


int ruhe(object me, object victim, object weapon, int damage)
{
        string *msg;
        msg = ({
		CYN"不料$N左手屈指连算，已算准了$n的腾挪方位，又即挺剑出招！\n"NOR,
		CYN"但是$n的武功门路已被$N算得清清楚楚，眼见已避开$N的招数，"+weapon->name()+CYN"竟又直逼而至！\n"NOR,
        });
if (!victim) return 0;
if (!me) return 0;
if (!weapon) return 0;
if (!damage) return 0;
        if(damage==RESULT_DODGE && (int)me->query_skill("sword",1) 
> random(150)+100 && me->query_temp("ruhe")) {
                message_vision(msg[random(sizeof(msg))], me,victim);
if (!victim) return 0;
if (!me) return 0;
victim->start_busy(2);
//if (victim=me) return 0;
if (victim && me
&& !me->query_temp("dsauto")
&& !me->is_busy())
{
me->set_temp("dsauto",1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
me->delete_temp("dsauto");
}
                return 1;
	   }
}


string perform_action_file(string action)
{
        return __DIR__"shiba-pan/" + action;
}
