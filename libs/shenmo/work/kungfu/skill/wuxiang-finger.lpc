// Last Modified by winder on May. 29 2001
// wuxiang-finger.c 无相劫指 不能互备
// 取自佛法十二字“广大，智慧，真如，性海，颖悟，圆觉”。

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N将双手拢在衣袖之中，一招"HIW"「广大无相劫」"NOR"，暗劲自袖中悄悄涌出，刺向$n",
	"lvl"   : 0,
	"skill_name" : "广大无相劫" 
]),
([	"action" : "$N微微一笑，一招"HIW"「智慧无相劫」"NOR"，衣袖连摆，指劲随机弹出，叫人琢磨不透，无法躲避",
	"lvl"   : 10,
	"skill_name" : "智慧无相劫" 
]),
([	"action" : "$N垂手站立，丝毫不动，但闻$n身前哧的一声，闻声不见物，是那招"HIW"「真如无相劫」"NOR"",
	"lvl"   : 30,
	"skill_name" : "真如无相劫" 
]),
([	"action" : "$N抬头往天，一指"HIW"「性海无相劫」"NOR"暗袭$n$l，本人却见丝毫不动，仿若无事发生一样",
	"lvl"   : 60,
	"skill_name" : "性海无相劫" 
]),
([	"action" : "$N一招"HIW"「颖悟无相劫」"NOR"向$n点出，闻得一破空之声，却见$P微笑点头，却再无任何动静",
	"lvl"   : 100,
	"skill_name" : "颖悟无相劫" 
]),
([	"action" : "但闻哧哧两声，$n脸色突变，$N却悠闲自在，并无动过手的迹象，这好象是那招"HIW"「圆觉无相劫」"NOR"",
	"lvl"   : 150,
	"skill_name" : "圆觉无相劫" 
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry" || usage=="unarmed"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练无相劫指必须空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 170)
		return notify_fail("你的站桩功火候不够，无法学无相劫指。\n");
	if ((int)me->query("max_neili") < 2500)
		return notify_fail("你的内力太弱，无法练无相劫指。\n");
	if (me->query_skill("yizhi-chan", 1) < 50)
		return notify_fail("你的一指禅火候不够，无法学无相劫指。\n");
	if ((me->query_skill("shaolin-leg", 1) < 50) ||
		(me->query_skill("shaolin-cuff", 1) < 50))
		return notify_fail("你的少林弹腿和少林南拳火候不够。\n");
	if ((me->query_skill("yiwei-dujiang", 1) < 50))
		return notify_fail("你的一苇渡江火候不够。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的内力不够练无相劫指。\n");
	me->receive_damage("qi", 50);
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
	int d_e1 = 10;
	int d_e2 = 80;
	int p_e1 = 145;
	int p_e2 = 125;
	int f_e1 = 550;
	int f_e2 = 850;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuxiang-finger", 1);
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
		"damage_type" : random(2) ? "刺伤" : "瘀伤",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"wuxiang-finger/" + action;
}

int help(object me)
{
	write(HIC"\n无相劫指："NOR"\n");
	write(@HELP

    无相劫指是南少林高级指法，不能互备，取自佛法十二字“广大，智慧，
真如，性海，颖悟，圆觉”。

	学习要求：
		站桩功170级
		一指禅50级
		内力修为2500
HELP
	);
	return 1;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("ruying-leg",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        return HIB "「无相劫指!!」！$N突然连点$n几处大穴!! $n吐出一口鲜血!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 50)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "嘿!!无相劫指！一股鲜血从$n的身子喷出!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("ruying-leg", 1);

        if( damage < 10 ) return 1;
//          ob->start_busy(2);
            if ( random(12) == 0 || random(level) > 150){
         msg = RED"$N面对$n的攻势。突然点出几下无形的无相劫指!!!。\n"NOR;
         msg += RED"$n感到全身一紧，尽然不能动了!!。\n"NOR;
ob->start_busy(3);

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}
