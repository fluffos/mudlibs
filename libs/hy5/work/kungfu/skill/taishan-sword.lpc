// taishan-sword.c 泰山剑法
// Last Modified by suncity may 31st,2002
// Modified by Java Sep.1998

#include <ansi.h>
inherit SKILL;
#include <combat.h>
string type() { return "martial"; }
string martialtype() { return "skill"; }
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
([	"skill_name" :"朗月无云",
	"action":  "$N手中$w一晃，向右滑出三步，一招"HIB"「朗月无云」"NOR"，转过身来，身子微矮，$w向$n斜斜刺去",
        "lvl" : 0
]),
([	"skill_name" :"峻岭横空",
	"action":  "$N手中$w圈转，一招"HIC"「峻岭横空」"NOR"去势奇疾，无数剑光刺向$n的$l",
	"lvl" : 10
]),
([	"skill_name" :"来鹤清泉",
	"action": "$N突然腰一弯，挺$w向$n刺去，这一剑力劲剑疾，正是一招"HIC"「来鹤清泉」"NOR"",
	"lvl" : 20
]),
([	"name":    "石关回马",
	"action":  "$N手中$w刷的一声，反手砍向$n，剑势圆润如意："HIY"「石关回马」"NOR"！",
	"lvl" : 30
]),
([	"skill_name" : "泰山十八盘",
	"action":  "$N展开剑势，身随剑走，左边一拐，右边一弯，越转越急。猛地$w剑光暴长，一招"HIM"「泰山十八盘」"NOR"往$n$l刺去",
	"lvl" : 40
]),
([	"skill_name" :"快活三里",
	"action": "$N手臂暴长，手中$w豁豁展开，刷刷两剑，指向$n，正是"GRN"「快活三里」"NOR"",
	"lvl" : 50
]),
([	"skill_name" :  "七星落长空",
	"action":  "$N一招"HIR"「七星落长空」"NOR"挺$w向$n当胸刺去，剑光闪烁，$w发出嗡嗡之声，罩住了$n胸口“膻中”、“神藏”、“灵墟”、“神封”、“步廊”、“幽门”、“通谷”七处大穴",
	"lvl" : 60
]),
([	"skill_name" :"五大夫剑",
	"action":  "$N手中$w倏地刺出，一连五剑，每一剑的剑招皆苍然有古意。招数古朴，内藏奇变，正是"HIW"「五大夫剑」"NOR"",
	"lvl" : 70
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 20 )
		return notify_fail("你的内力修为不够，没有办法练泰山剑法。\n");
	if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
		return notify_fail("泰山剑法必须配合磐石神功才能练。\n");
	if( me->query_skill("panshi-shengong", 1) < 20)
		return notify_fail("你的磐石神功修为不够。\n");
	if( me->query_skill("kuaihuo-strike", 1) < 20)
		return notify_fail("你的快活十三掌修为不够。\n");

	if( me->query_skill("fengshenjue", 1) < 20)
		return notify_fail("你的风神诀为不够。\n");

//	if( me->query("family/generation") > 12 &&
//		me->query_skill("taishan-sword",1) > 150)
//		return notify_fail("你要修习更高的泰山剑法，必须拜十二代长老为师。\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("qi") < 40 ||(int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，没法练习泰山剑法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 15;
	int d_e2 = 30;
	int p_e1 = 25;
	int p_e2 = 15;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 310;
	int m_e2 = 410;
	int i, lvl, seq, ttl = sizeof(action);

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

	lvl = (int) me->query_skill("taishan-sword", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }



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
victim->start_busy(2);
me->set_temp("dsauto",1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
me->delete_temp("dsauto");
}
                return 1;
	   }
}


int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"taishan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n泰山剑法："NOR"\n");
	write(@HELP

    泰山剑法为泰山本门剑法。

	学习要求：
		泰山基本武功20级
		磐石神功20级
		内力修为20
HELP
	);
	return 1;
}

